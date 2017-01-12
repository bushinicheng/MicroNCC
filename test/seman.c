#include "common.h"

bool is_syntax_error = false;
int last_syntax_error;

typedef struct tagVarElement {
	char *varname;
	Spec *type;
	Node *node;
	int citcount;
} VarElement;

static int asptr, actionlevel;
VarElement actionscope[102400];//action scope of variable


/* IN[0]: char *
 *   specify the output string, assume
 *   duplicate element as given parameter
 * IN[1]: void *
 *   set of struct contains id
 * IN[2]: size_t
 *   the length of set
 * IN[3]: size_t
 *   size of a single element
 * IN[4]: off_t
 *   offset of id in a single element
 * OUT[0]:bool
 *   true if duplicate, else false
 */
bool check_dupset(char *dupformat, void *set, size_t len, size_t unitsize, off_t off) {
	//assume ith id: ((char**)(set + i * unitsize + off))[0]
	
	for(int i = 0; i < len; i++) {
		char *sa = ((char**)(set + i * unitsize + off))[0];
		for(int j = 0; j < i; j++) {
			char *sb = ((char**)(set + j * unitsize + off))[0];
			if(strcmp(sa, sb) == 0) {
				yyerr(dupformat, sa);
				is_syntax_error = 1;
			}
		}
	}
	return true;
}


/* IN[0]:  char *
 *   variable name
 * OUT[0]: bool
 *   true if duplicate, else false
 * function:
 *   check the duplication of current action scope
 */
bool find_duplication(char *varname) {
	int i = asptr - 1;
	while(i >= 0 && actionscope[i].varname != NULL) {
		if(strcmp(varname, actionscope[i].varname) == 0) {
			return true;
		}
		i --;
	}
	return false;
}


/*
 * function:
 *   ...
 * assume each query is meaningful :)
 */
VarElement *find_variable(Node *node, char *varname) {
	wt_assert(node && varname);
	if(asptr <= 0) return NULL;
	for(int i = asptr - 1; i>=0; i--) {
		if(actionscope[i].varname) {
			if(strcmp(varname, actionscope[i].varname) == 0) {
				actionscope[i].citcount ++;
				return &actionscope[i];
			}
		}
	}

	//not found
	yyerrtype(ErrorUndeclaredIdentifier, node->lineno, varname);
	is_syntax_error = true;
	return NULL;
}


/* function:
 *   split the action scope
 */
void push_barrier() {
	actionscope[asptr].varname = NULL;
	actionscope[asptr].type = NULL;
	actionlevel ++;
	asptr ++;
}


/*
 * function:
 *   register a variable in actionscope array
 *   TODO: alloc register for active variable
 */
void push_variable(Node *node, char *varname, Spec *type) {
	wt_assert(node && varname && type);
	find_duplication(varname);

	//calculate base
	if(node->idtype)
		node->var_size = node->idtype->width;
	if(actionscope[asptr].node)
		node->base_addr = actionscope[asptr].node->base_addr + actionscope[asptr].node->var_size;
	else
		node->base_addr = 0;

	//decide base type
	if(actionlevel > 0) {
		node->base_type = 2;//global
	} else if(actionlevel == 0) {
		node->base_type = 1;//local stack
	} else {
		logw("actionlevel = %d < 0\n", actionlevel);
	}


	//check duplication
	if(find_duplication(varname)) {
		yyerrtype(ErrorRedefinition, node->lineno, varname);
		is_syntax_error = true;
	}

	//push variable
	actionscope[asptr].varname = varname;
	actionscope[asptr].node = node;
	actionscope[asptr].type = type;
	actionscope[asptr].citcount = 1;
	asptr ++;
}


/*
 * function:
 *   clear current scope
 */
void pop_scope() {
	if(asptr > 0) asptr --;
	if(actionlevel > 0) actionlevel --;
	while(asptr > 0){
	   	if(actionscope[asptr].varname != NULL)
			asptr --;
		else
			break;
	}
}

/*-------------------------*/
int analyse_vardef(Node *root);
int analyse_expression(Node *root);


void check_function_call(Node *root, VarElement *func) {
	if(!root || !func) return;
	wt_assert(root->reduce_rule == AST_Exp_is_ID_LP_RP
		|| root->reduce_rule == AST_Exp_is_ID_LP_FuncCallArgList_RP);
	//need  <==> func->type->func.argv
	//given <==> root->reduce_rule
	if(func->type->btype != SpecTypeFunc) {
		//function not callable
		yyerrtype(ErrorNotCallable, root->lineno, get_child_node_w(root, ID)->idtype->cons.supval.st);
	}else if(func->type->func.argv == 0) {
		//0 parameter need, ? given
		if(root->reduce_rule != AST_Exp_is_ID_LP_RP) {
			yyerrtype(ErrorCall0vx, root->lineno);
		}
	}else{
		if(root->reduce_rule != AST_Exp_is_ID_LP_FuncCallArgList_RP) {
			//n parameter need, 0 given
			yyerrtype(ErrorCallnv0, root->lineno, func->type->func.argv);
		} else {
			//n parameter need, m given, n may equal to m
			Node *arglist = get_child_node(root, FuncCallArgList);
			for(int i = 0; i < func->type->func.argv; i++) {
				if(!arglist) {
					//n parameter need, m given, n > m
					yyerrtype(ErrorCallngtm, root->lineno, func->type->func.argv, i);
					break;
				}
				//check every parameter if mismatch
				Node *expnode = get_child_node_dw(arglist, 2, FuncCallArg, Exp);
				analyse_expression(expnode);
				if(!compare_type(func->type->func.arglist[i].type, expnode->idtype)) {
					yyerrtype(ErrorCallParameterNotMatch, root->lineno, type_format(expnode->idtype), type_format(func->type->func.arglist[i].type), i + 1);
				}

				arglist = get_child_node(arglist, FuncCallArgList);
			}
			
			if(arglist) {
				//n parameter need, m given, n < m
				yyerrtype(ErrorCallnltm, root->lineno, func->type->func.argv);
			}
		}
	}
}


/*
 *
 *-------------------------------------------------
 *
 */

void register_idlist(Node *root, Spec *type) {
	if(!root) return;
	wt_assert(root->token == IdList);
	
	Node *idlist = root;
	while(idlist) {
		char *varname = NULL;
		Node *vardec = get_child_node_w(idlist, Decln);
		Spec *newtype = register_complex_var_with_type(type, vardec, &varname);
		push_variable(vardec, varname, newtype);

		idlist = get_child_node(idlist, IdList);
	}
}


int analyse_expression(Node *root) {
	if(root == NULL) return 0;
	wt_assert(root->token == Exp);

	Spec *type;
	VarElement *var;
	Node *id = NULL, *num = NULL, *st = NULL;
	Node *exp = NULL, *exp2 = NULL;

	switch(root->reduce_rule) {
		case AST_Exp_is_ID:
			id = get_child_node_w(root, ID);
			root->idtype = get_spec_by_btype(SpecTypeInt32, SpecLvalue);
			var = find_variable(root, id->idtype->cons.supval.st);
			if(var)	root->idtype = var->type;
			break;
		case AST_Exp_is_ID_LP_RP:
			id = get_child_node_w(root, ID);
			root->idtype = get_spec_by_btype(SpecTypeInt32, SpecLvalue);
			var = find_variable(root, id->idtype->cons.supval.st);
			if(var) {
				root->idtype = var->type->func.ret;
				check_function_call(root, var);
			}
			//check args type
			break;
		case AST_Exp_is_ID_LP_FuncCallArgList_RP:
			id = get_child_node_w(root, ID);
			root->idtype = get_spec_by_btype(SpecTypeInt32, SpecLvalue);
			var = find_variable(root, id->idtype->cons.supval.st);
			if(var) {
				root->idtype = var->type->func.ret;
				check_function_call(root, var);
			}
			//check args type
			break;
		case AST_Exp_is_NUM:
			//rval
			num = get_child_node_w(root, NUM);
			root->idtype = get_spec_of_const(num->idtype);
			break;
		case AST_Exp_is_ADD_NUM:
			//rval
			num = get_child_node_w(root, NUM);
			root->idtype = get_spec_of_const(num->idtype);
			break;
		case AST_Exp_is_SUB_NUM:
			//rval
			num = get_child_node_w(root, NUM);
			root->idtype = get_spec_of_const(num->idtype);
			break;
		case AST_Exp_is_MULT_Exp:
			//int *p; *p
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			if(exp->idtype->btype != SpecTypeComplex){
				yyerrtype(ErrorNotPointer, root->lineno);
			}else if(exp->idtype->comp.plevel > 1){
				root->idtype = copy_spec(exp->idtype);
				root->idtype->comp.plevel --;
			}else if(root->idtype->comp.plevel == 1){
				root->idtype = exp->idtype->comp.spec;
			}else{
				yyerrtype(ErrorNotPointer, root->lineno);
			}
			break;
		case AST_Exp_is_AND_Exp:
			//int p; &p
			//lval -> OK, rval -> error
			//FIXME: function pointer;
			//       int func(); *func; &func;//OK
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			if(exp->idtype->btype == SpecTypeComplex){
				root->idtype = copy_spec(exp->idtype);
				root->idtype->width = get_size_of_btype(SpecTypePointer);
				root->idtype->comp.plevel ++;
			}else{
				root->idtype = new_spec();
				root->idtype->lval = SpecRvalue;
				root->idtype->btype = SpecTypeComplex;
				root->idtype->comp.spec = exp->idtype;
				root->idtype->width = get_size_of_btype(SpecTypePointer);
				root->idtype->comp.plevel = 1;
			}

			if(exp->idtype->lval != SpecLvalue) {
				yyerrtype(ErrorTakeRvalueAddress, root->lineno, type_format(exp->idtype));
			}
			break;
		case AST_Exp_is_NOT_Exp:
			//int p; ~p; ==> rval
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = get_spec_by_btype(SpecTypeInt32, SpecRvalue);
			if(exp->idtype->btype == SpecTypeUint32) {
				root->idtype = get_spec_by_btype(SpecTypeUint32, SpecRvalue);
			}else if(!type_is_bit(exp->idtype))
				yyerrtype(ErrorUnaryOperatorMismatch, root->lineno);
			break;
		case AST_Exp_is_LNOT_Exp:
			//int p; !p
			//ok: num or (comp and (plevel>0 or size>0))
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = get_spec_by_btype(SpecTypeUint8, SpecRvalue);
			if(!(type_is_num(exp->idtype)
				|| ( exp->idtype->btype == SpecTypeComplex
				   && (exp->idtype->comp.plevel
					   || exp->idtype->comp.size)
				   )
				)
			)
				yyerrtype(ErrorUnaryOperatorMismatch, root->lineno);
			break;
		case AST_Exp_is_STRING:
			//char *p = "string"
			st = get_child_node_w(root, STRING);
			analyse_expression(exp);
			root->idtype = get_spec_of_const(st->idtype);
			break;
		case AST_Exp_is_Exp_ASSIGNOP_Exp:
			//FIXME
			//int a; a = 1.5; is OK
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			if(exp->idtype->lval != SpecLvalue){
				yyerrtype(ErrorNotAssignable, root->lineno);
			}else if(!type_is_compatible(exp->idtype, exp2->idtype)) {
				yyerrtype(ErrorAssignIncompatible, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}
			break;
		case AST_Exp_is_Exp_COMMA_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			break;
		case AST_Exp_is_Exp_DOT_ID:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			id = get_child_node_w(root, ID);
			if(exp->idtype->btype != SpecTypeStruct) {
				//not a struct
				yyerrtype(ErrorReferenceStructMember, root->lineno, type_format(exp->idtype));
			} else {
				type = find_type_of_struct_member(exp->idtype, id->idtype->cons.supval.st);
				if(type == NULL) {
					//no this member
					yyerrtype(ErrorNoSuchMember, root->lineno, id->idtype->cons.supval.st, type_format(exp->idtype));
				} else {
					root->idtype = type;
				}
			}
			break;
		case AST_Exp_is_Exp_POINTER_ID:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			id = get_child_node_w(root, ID);
			//plevel = 1 and array.size = 0 and btype = comp
			//plevel = 0 and array.size = 1
			if(exp->idtype->btype != SpecTypeComplex) {
				yyerrtype(ErrorReferenceNotPointer, root->lineno, type_format(exp->idtype));
			} else if((exp->idtype->comp.size == 1
					    &&exp->idtype->comp.plevel == 0)
					||(exp->idtype->comp.size == 0
						&&exp->idtype->comp.plevel == 1)) {
				//struct{int b;} a[1]; a->b;
				type = find_type_of_struct_member(exp->idtype->comp.spec, id->idtype->cons.supval.st);
				if(type == NULL) {
					//no this member
					yyerrtype(ErrorNoSuchMember, root->lineno, id->idtype->cons.supval.st, type_format(exp->idtype));
				} else {
					root->idtype = type;
				}
			} else {
				yyerrtype(ErrorReferenceStructMember, root->lineno, type_format(exp->idtype));
			}
			break;
		case AST_Exp_is_Exp_ADD_Exp:
		case AST_Exp_is_Exp_SUB_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			/*limit: type(operand) in (
			 *      SpecTypeFloat32,
			 *		SpecTypeInt32, SpecTypeUint32,
			 *		SpecTypeUint8, SpecTypeInt8,
			 *		SpecTypeConst:'i', 'f'
			 *		)
			 *	or type(operandA) == INT, UNSIGNED
			 *	   type(operandB) == pointer
			 *
			 *	result: rval
			 */
			if(exp->idtype->btype == SpecTypeComplex) {
				//note: int a = 0, *p = &a; p + 3;
				if(!type_is_bit(exp2->idtype)) {
					//error
					yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
				}else{
					if(exp->idtype->lval == SpecRvalue){
						root->idtype = exp->idtype;
					}else{
						root->idtype = copy_spec(exp->idtype);
						root->idtype->lval = SpecRvalue;
					}
				}
			}else if(exp2->idtype->btype == SpecTypeComplex){
				//note: int a = 0, *p = &a; 3 + p;
				if(!type_is_bit(exp->idtype)) {
					//error
					yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
				}else{
					if(exp2->idtype->lval == SpecRvalue){
						root->idtype = exp2->idtype;
					}else{
						root->idtype = copy_spec(exp2->idtype);
						root->idtype->lval = SpecRvalue;
					}
				}
			}else if(type_is_num(exp->idtype)
				  && type_is_num(exp2->idtype) ){
				//valid operation
				root->idtype = type_more_accurate(exp->idtype, exp2->idtype);
			}else{
				//invalid
				yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}
			break;
		case AST_Exp_is_Exp_MULT_Exp:
		case AST_Exp_is_Exp_DIV_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			/*limit: type(operand) in (
			 *      SpecTypeFloat32,
			 *		SpecTypeInt32, SpecTypeUint32,
			 *		SpecTypeUint8, SpecTypeInt8,
			 *		SpecTypeConst:'i', 'f'
			 *		)
			 *
			 * transformation rule:
			 *      int op unsigned  ==>  unsigned op unsigned
			 *      unsigned op float  ==>  float op float
			 *
			 *	result: rval
			 */
			if(type_is_num(exp->idtype)
			&& type_is_num(exp2->idtype)) {
				root->idtype = type_more_accurate(exp->idtype, exp2->idtype);
			}else{
				yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}
			break;
		case AST_Exp_is_Exp_AND_Exp:
		case AST_Exp_is_Exp_OR_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			/* a & b; a | b;
			 * limit: no float
			 * type(operand) in (
			 *      SpecTypeInt32, SpecTypeUint32,
			 *		SpecTypeUint8, SpecTypeInt8,
			 *      SpecTypeConst:'i'
			 *      )
			 *
			 * transformation rule:
			 *      int op unsigned  ==>  unsigned op unsigned
			 *
			 *	result: rval
			 */
			if(type_is_bit(exp->idtype)
			&& type_is_bit(exp2->idtype)) {
				root->idtype = type_more_accurate(exp->idtype, exp2->idtype);
			}else{
				yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}
			break;
		case AST_Exp_is_Exp_EQ_Exp:
		case AST_Exp_is_Exp_LT_Exp:
		case AST_Exp_is_Exp_LE_Exp:
		case AST_Exp_is_Exp_NE_Exp:
		case AST_Exp_is_Exp_GT_Exp:
		case AST_Exp_is_Exp_GE_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = get_spec_by_btype(SpecTypeUint8, SpecRvalue);
			/* limit: no float, no struct
			 * type(operand) not in (
			 *      SpecTypeStruct
			 *      )
			 * warning for pointer op int, just warning
			 * error for pointer op float
			 *        or struct op ?
			 * return SpecTypeUint8
			 *
			 * result: rval
			 */
			if(exp->idtype->btype == SpecTypeStruct
			|| exp2->idtype->btype == SpecTypeStruct) {
				yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}else if(type_is_float(exp->idtype)){
				if(exp2->idtype->btype == SpecTypeComplex
				&& ( exp2->idtype->comp.size > 0
				   || exp2->idtype->comp.plevel > 0)
				  ) {
					yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
				}
			}else if(type_is_float(exp2->idtype)){
				if(exp->idtype->btype == SpecTypeComplex
				&& ( exp->idtype->comp.size > 0
				   || exp->idtype->comp.plevel > 0)
				  ) {
					yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
				}
			}
			break;
		case AST_Exp_is_Exp_LAND_Exp:
		case AST_Exp_is_Exp_LOR_Exp:
			//all type except struct
			//	result: rval
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = get_spec_by_btype(SpecTypeUint8, SpecRvalue);
			if(exp->idtype->btype == SpecTypeStruct
			|| exp2->idtype->btype == SpecTypeStruct) {
				yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}
			break;
		case AST_Exp_is_LP_Exp_RP:
			//exp -> ( exp )
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			break;
		case AST_Exp_is_Exp_LB_Exp_RB:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			// exp -> exp [ exp2 ]
			// type(operand2) in (INT, UNSIGNED)
			// pointer int *p; p [ 0 ];
			// array int a[5]; a [ 0 ];
			// rval -> lval
			if(!type_is_bit(exp2->idtype)) {
				//index is not an integer
				yyerrtype(ErrorIndexNotInteger, root->lineno);
			}
			
			if(exp->idtype->btype != SpecTypeComplex){
				//variable is not an array or pointer
				yyerrtype(ErrorSubscripted, root->lineno);
			}else if(exp->idtype->comp.size > 0){
				//subscripted value is an array
				if(root->idtype->comp.size == 1
				&& exp->idtype->comp.plevel == 0) {
					root->idtype = exp->idtype->comp.spec;
				}else{
					root->idtype = copy_spec(exp->idtype);
					root->idtype->comp.size --;
				}
			}else if(exp->idtype->comp.plevel > 0){
				//pure pointer
				if(exp->idtype->comp.plevel == 1) {
					root->idtype = exp->idtype->comp.spec;
				}else{
					root->idtype = copy_spec(exp->idtype);
					root->idtype->comp.plevel --;
				}
			}else{
				logw("check here :(\n");
			}
			break;
		default:
			wt_assert(0);
	}
}


int analyse_statement(Node *root) {
	if(root == NULL) return 0;
	wt_assert(root->token == Stmt);

	Node *exp = NULL, *exp2 = NULL, *exp3 = NULL;
	Node *vardef = NULL, *stmt = NULL;
	Node *stmt2 = NULL, *stmtlist = NULL;
	switch(root->reduce_rule) {
		case AST_Stmt_is_Exp_SEMI:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			break;
		case AST_Stmt_is_VarDef:
			vardef = get_child_node_w(root, VarDef);
			analyse_vardef(vardef);
			break;
		case AST_Stmt_is_CompSt:
			push_barrier();
			stmtlist = get_child_node_dw(root, 2, CompSt, StmtList);
			while(stmtlist) {
				stmt = get_child_node_w(stmtlist, Stmt);
				analyse_statement(stmt);
				stmtlist = get_child_node(stmtlist, StmtList);
			}
			pop_scope();
			break;
		case AST_Stmt_is_RETURN_Exp_SEMI:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			break;
		case AST_Stmt_is_IF_LP_Exp_RP_Stmt:
			push_barrier();
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			pop_scope();
			break;
		case AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt:
			push_barrier();
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			stmt = get_child_node_w(root, Stmt);
			analyse_statement(stmt);
			stmt2 = get_child_node_with_skip_w(root, Stmt, 1);
			analyse_statement(stmt2);
			pop_scope();
			break;
		case AST_Stmt_is_WHILE_LP_Exp_RP_Stmt:
			push_barrier();
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			stmt = get_child_node_w(root, Stmt);
			analyse_statement(stmt);
			pop_scope();
			break;
		case AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI:
			push_barrier();
			stmt = get_child_node_w(root, Stmt);
			analyse_statement(stmt);
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			pop_scope();
			break;
		case AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt:
			push_barrier();
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			exp3 = get_child_node_with_skip_w(root, Exp, 2);
			analyse_expression(exp3);
			stmt = get_child_node_w(root, Stmt);
			analyse_statement(stmt);
			pop_scope();
			break;
		default:
			wt_assert(0);
	}
}

int analyse_function(Node *root, Spec *functype) {
	if(root == NULL) return 0;
	wt_assert(root->reduce_rule == AST_Block_is_TypeSpec_FuncDec_CompSt);

	push_barrier();
	/*register function arguments*/
	for(int i = 0; i < functype->func.argv; i++) {
		Spec *type = functype->func.arglist[i].type;
		char *varname = functype->func.arglist[i].varname;
		if(type == NULL	|| varname == NULL)
			logw("check here!\n");
		push_variable(root, varname, type);
	}


	Node *stmt = NULL;
	Node *stmtlist = get_child_node_dw(root, 2, CompSt, StmtList);

	/*analyse every statements*/
	while(stmtlist) {
		stmt = get_child_node_w(stmtlist, Stmt);
		analyse_statement(stmt);
		stmtlist = get_child_node(stmtlist, StmtList);
	}

	pop_scope();
}

int analyse_vardef(Node *root) {
	if(root == NULL) return 0;
	wt_assert(root->token == VarDef);
	Spec *type = find_type_of_spec(get_child_node_w(root, TypeSpec));
	Node *declist = get_child_node_w(root, DecList);
	while(declist) {
		char *varname = NULL;
		Node *vardec = get_child_node_dw(declist, 2, Dec, Decln);
		Spec *type = register_type_complex_var(vardec, &varname);
		//push and check
		vardec->idtype = type;
		push_variable(vardec, varname, type);
		declist = get_child_node(declist, DecList);
	}
	return 0;
}

int semantic_analysis(Node *root)
{
	if(root == NULL)
		return 0;

	wt_assert(root->token == Program);
	Node *blocklist = get_child_node_w(root, BlockList);

	//block reduce
	while(blocklist != NULL) {
		Spec *type = NULL;
		Node *idlist = NULL;
		Node *block = get_child_node_w(blocklist, Block);
		switch(block->reduce_rule) {
			case AST_Block_is_TypeSpec_FuncDec_CompSt:
				type = register_type_function(get_child_node_w(block, FuncDec));
				push_variable(block, get_child_node_dw(block, 2, FuncDec, ID)->idtype->cons.supval.st, type);
				analyse_function(block, type);
				break;
			case AST_Block_is_StructDecln_SEMI:
				register_type_struct(get_child_node_w(block, StructDecln));
				break;
			case AST_Block_is_VarDef:
				analyse_vardef(get_child_node_w(block, VarDef));
				break;
			default:
				wt_assert(0);
		}

		blocklist = get_child_node(blocklist, BlockList);
	}

	return 0;
}

void init_seman()
{
#define STATE_RESET do{ \
	void reset_spec_state(); \
	asptr = 0; \
	is_syntax_error = false; \
	last_syntax_error = 0; \
	actionlevel = 0; \
	reset_spec_state(); \
} while(0)

//#undef __DEBUG__
//#warning "don't forget it"
#ifdef __DEBUG__
	
	UNIT_TEST_START;
	/*unit test start*/
	extern Node *astroot;
	void yy_scan_string(char *);
/*
	char *vardef_test_sample[] = {
		"int a;", "int a, b, c;", "int *a, b[10], *c[10];",
		"int **a[2][3][4];",
		"int a = 0;", "int a = 0, b = 10;", "int a = 0, *p = &a;",
		"struct A {int arg;}; struct A a, *b, c[2], *d[3];",
	};
	
	for(int i = 0; i < sizeof(vardef_test_sample)/sizeof(vardef_test_sample[0]); i++) {
		STATE_RESET;
		yy_scan_string(vardef_test_sample[i]);
		yyparse();

		Node *structdec = find_child_node(astroot, StructDecln);
		if(structdec != NULL) register_type_struct(structdec);
		Node *vardef = find_child_node(astroot, VarDef);
		Node *spec = get_child_node(vardef, TypeSpec);
		Node *declist = get_child_node_w(vardef, DecList);
		Spec *rawtype = find_type_of_spec(spec);
		analyse_vardef(vardef);
		while(declist) {
			char *varname;
			Node *vardec = get_child_node_dw(declist, 2, Dec, Decln);
			Spec *newtype = register_complex_var_with_type(rawtype, vardec, &varname);
			UNIT_TEST_EQUAL(compare_type(newtype, find_variable(vardec, varname)->type), true);

			declist = get_child_node(declist, DecList);
		}
	}

	char *exp_test_sample[] = {
		"int a; int main(){a;}",
		"int main(){int a; (~a)*45+(12*3.4)/78+7;}",
		"int main(){+7;}",
		"int main(){-7;}",
		"int main(){89+-7;}",
		"int main(){99--7;}",
		"int *a; int main(){*a;}",
		"int a; int main(){*&a;}",
		"int a; int main(){!a&&(1||a)&&(!~~!(a&a|a));}",
		"int func(){\"hello\"[0] == 97 + 7;}",
		"int a; int main(){a = 45,\"main\", 1.35;}",
		"int a;struct A{int a;}x; int main(){a = x.a*a*x.a&x.a;}",
		"struct A{int a;}*p;int a; int main(){p->a*a*p->a&p->a;}",
		"struct A{int a;}*p,a[12]; int main(){p->a*a[2].a*p->a&p->a;}",
		"struct A{int a;}p[0][1];int main(){p[0]->a*(&p[0][0])->a*p[0][0].a;}",
		"int func(){func();}",
		"int func(int a, int b){int a; func(a, 3);}",
		"int a; int func(int a, int *p){(func(16, &a)+56)*78;}",
	};

	int exp_test_answer[][2] = {
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeFloat32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeUint8, SpecRvalue},
		{SpecTypeUint8, SpecRvalue},
		{SpecTypeInt32, SpecLvalue},
		{SpecTypeInt32, SpecLvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecRvalue},
		{SpecTypeInt32, SpecLvalue},
		{SpecTypeInt32, SpecLvalue},
		{SpecTypeInt32, SpecLvalue},
	};

	for(int i = 0; i < sizeof(exp_test_sample)/sizeof(exp_test_sample[0]); i++) {
		STATE_RESET;
		yy_scan_string(exp_test_sample[i]);
		yyparse();

		Node *funcdec = find_child_node(astroot, FuncDec);
		Node *structdec = find_child_node(astroot, StructDecln);
		Node *exp = find_child_node(astroot, Exp);
		Node *vardef = find_child_node(astroot, VarDef);
		Spec *structtype = register_type_struct(structdec);
		Spec *functype = register_type_function(funcdec);
		if(get_sibling_node(structdec, IdList)) {
			Spec *stype = register_type_struct(structdec);
			Node *idlist = get_sibling_node_w(structdec, IdList);
			register_idlist(idlist, stype);
		}
		if(functype){
			char *funcname = get_child_node_w(funcdec, ID)->idtype->cons.supval.st;
			push_variable(funcdec, funcname, functype);
		}
		analyse_vardef(vardef);
		analyse_expression(exp);
		//print_exp(exp);//check all samples by human !important!
		UNIT_TEST_ASSERT(compare_type(exp->idtype, get_spec_by_btype(exp_test_answer[i][0], exp_test_answer[i][1])), "fail at #%d: '%s'", i, exp_test_sample[i]);
	}
*/

	/*
	struct {
		int is_error, reason;
		char *sample;
	} error_detection_testcase[] = {
	//TODO:test following sample by human
	//test error detection, 2nd pharse, checked by human
		{false, 0, "int func(){!0.5;}"},
		{false, 0, "int func(){\"123456789\"[0]+8==48+9;}"},
		{false, 0, "int func(){!(6+0.5);}"},
		{false, 0, "int func(){float a; !a;}"},
		{false, 0, "int func(){&func;}"},
		{false, 0, "int func(){int a[0][0]; a != 456789;}"},
		{false, 0, "int func(){int *a[0]; !a;}"},
		{false, 0, "int func(){int a[0]; !a;}"},
		{false, 0, "int func(){int a[0]; a != 456789;}"},
		{false, 0, "int func(){int **a;*a;}"},
		{false, 0, "int func(){int a; *&a;}"},
		{false, 0, "int func(){int **a;*a[0];}"},
		{false, 0, "int func(){int a; a <= 0.5;}"},
		{false, 0, "int func(){int a; a || 0.5;}"},
		{false, 0, "int func(){int a; a=1.5;}"},
		{false, 0, "int func(){int **a; a != 456789;}"},
		{false, 0, "int func(){int *a; a != &a;}"},
		{false, 0, "int func(){int a; a != &a;}"},
		{false, 0, "int func(){int a; a && &a;}"},
		{false, 0, "int func(){int a; a=a*1.5;}"},
		{false, 0, "int func(){int a; a && func;}"},
		{false, 0, "int func(){int a; a && func;}"},
		{false, 0, "struct A{int a;}a[0];int func(){a->a;}"},
		{false, 0, "struct A{int a;} *x[0];int func(){int a; a > x;}"},
		{false, 0, "struct A{int a;} *x[0];int func(){int a; a && x;}"},
		{false, 0, "struct A{int a;} *x[0];int func(){int a; a > x[0];}"},
		{false, 0, "struct A{int a;} *x[0];int func(){int a; a && x[0];}"},
		{false, 0, "struct A{int a;}*x[0];int func(){!x;}"},
		{false, 0, "struct A{int a;} *x;int func(){int a; a >= x;}"},
		{false, 0, "struct A{int a;} *x;int func(){int a; a && x;}"},
		{false, 0, "struct A{int a;}*x;int func(){!x;}"},
		{false, 0, "struct A{int a;}*x;int func(){x+3;}"},
		{true, ErrorCall0vx, "int func(){func(a,12);}"},
		{true, ErrorCallngtm, "int func(int a, int b){int a; func(&a);}"},
		{true, ErrorCallngtm, "int func(int a, int b){int a; func(a);}"},
		{true, ErrorCallnltm, "int func(int a, int b){int a; func(a, 3, &a);}"},
		{true, ErrorCallnltm, "int func(int a, int b){int a; func(a, &a, 3);}"},
		{true, ErrorCallnv0, "int func(int a, int b){func();}"},
		{true, ErrorCallParameterNotMatch, "int func(int a, int b){int a; func(a, &a);}"},
		{true, ErrorIndexNotInteger, "int func(){\"123456789\"[0.1]+8.4==48+9;}"},
		{true, ErrorIndexNotInteger, "int func(){int a[0];a[0.5];}"},
		{true, ErrorInvalidOperand, "int func(){int a[0][0]; a != 0.5;}"},
		{true, ErrorInvalidOperand, "int func(){int a[0]; a != 0.5;}"},
		{true, ErrorInvalidOperand, "int func(){int *a; a != 0.5;}"},
		{true, ErrorInvalidOperand, "struct A{int a;} *x[0];int func(){int a; a > x[0][0];}"},
		{true, ErrorInvalidOperand, "struct A{int a;} *x[0];int func(){int a; a && x[0][0];}"},
		{true, ErrorInvalidOperand, "struct A{int a;} x;int func(){int a; a < x;}"},
		{true, ErrorInvalidOperand, "struct A{int a;} x;int func(){int a; a && x;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x;int func(){x&3.5;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x;int func(){x+3.5;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x;int func(){x&5;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x, y;int func(){x[0]+y;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x, y;int func(){x*x->a;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x, y;int func(){y&x;}"},
		{true, ErrorInvalidOperand, "struct A{int a;}*x, y, z;int func(){x[0]+y*z;}"},
		{true, ErrorNoSuchMember, "struct A{int a;}x[0];int func(){x->b;}"},
		{true, ErrorNoSuchMember, "struct A{int a;}*x;int func(){x->b;}"},
		{true, ErrorNotAssignable, "int func(){int a; *1.5=a;}"},
		{true, ErrorNotAssignable, "int func(){int a; 1.5=a;}"},
		{true, ErrorNotAssignable, "int func(){int a; &a=1.5;}"},
		{true, ErrorNotAssignable, "int func(){int a; a*1.5=a;}"},
		{true, ErrorNotPointer, "int func(){*6;}"},
		{true, ErrorNotPointer, "int func(){*func;}"},
		{true, ErrorNotPointer, "int func(){int a; &*a;}"},
		{true, ErrorNotPointer, "int func(){int a;*a;}"},
		{true, ErrorNotPointer, "int func(){int a;*a[0];}"},
		{true, ErrorTakeRvalueAddress, "int func(){&(45+12*78.+6.12);}"},
		{true, ErrorTakeRvalueAddress, "int func(){*&6;}"},
		{true, ErrorTakeRvalueAddress, "int func(){&*6;}"},
		{true, ErrorTakeRvalueAddress, "int func(){&6;}"},
		{true, ErrorTakeRvalueAddress, "int func(){&(78+6*12);}"},
		{true, ErrorTakeRvalueAddress, "int func(){&(a*78.+6.12);}"},
		{true, ErrorTakeRvalueAddress, "int func(){int a[0]; & &a[0];}"},
		{true, ErrorTakeRvalueAddress, "int func(){int a; &(a*78.+6.12);}"},
		{true, ErrorUnaryOperatorMismatch, "int func(){~0.5;}"},
		{true, ErrorUnaryOperatorMismatch, "int func(){~(6+0.5);}"},
		{true, ErrorUnaryOperatorMismatch, "int func(){float a; ~a;}"},
		{true, ErrorUnaryOperatorMismatch, "int func(){int *a[0]; ~a;}"},
		{true, ErrorUnaryOperatorMismatch, "int func(){int a[0]; ~a;}"},
		{true, ErrorUnaryOperatorMismatch, "struct A{int a;}x;int func(){~x;}"},
		{true, ErrorUnaryOperatorMismatch, "struct A{int a;}x;int func(){!x;}"},
		{true, ErrorUndeclaredIdentifier, "int func(){&a;}"},
		{true, ErrorUndeclaredIdentifier, "int func(){int a; a > b;}"},
		{true, ErrorUndeclaredIdentifier, "int func(){int a; a && b;}"},
		{true, ErrorUndeclaredIdentifier, "int func(){next();}"},
		{true, ErrorUndeclaredIdentifier, "int func(){next(78,12);}"},
		{true, ErrorUndeclaredIdentifier, "int func(){next(78,12)*3;}//pass all these testcases :)"},
	};

	for(int i = 0; i < sizeof(error_detection_testcase)/sizeof(error_detection_testcase[0]); i++) {
		STATE_RESET;
		yy_scan_string(error_detection_testcase[i].sample);
		yyparse();

		logd("line %d, case %d: %s\n", __LINE__, i, error_detection_testcase[i].sample);
		Node *funcdec = find_child_node(astroot, FuncDec);
		Node *structdec = find_child_node(astroot, StructDecln);
		Node *exp = find_child_node(astroot, Exp);
		Node *vardef = find_child_node(astroot, VarDef);
		Spec *structtype = register_type_struct(structdec);
		Spec *functype = register_type_function(funcdec);
		if(get_sibling_node(structdec, IdList)) {
			Spec *stype = register_type_struct(structdec);
			Node *idlist = get_sibling_node_w(structdec, IdList);
			register_idlist(idlist, stype);
		}
		if(functype){
			char *funcname = get_child_node_w(funcdec, ID)->idtype->cons.supval.st;
			push_variable(funcdec, funcname, functype);
		}
		analyse_vardef(vardef);
		analyse_expression(exp);
		//print_exp(exp);//check all samples by human !important!
		UNIT_TEST_ASSERT(is_syntax_error == error_detection_testcase[i].is_error && last_syntax_error == error_detection_testcase[i].reason, "fail at #%d: '%s'", i, error_detection_testcase[i].sample);
	}
*/
	UNIT_TEST_END;
#endif
	STATE_RESET;
}
