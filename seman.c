#include "common.h"

bool is_syntax_error = false;

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
	for(int i = asptr - 1; i >= 0; i--) {
		if(strcmp(varname, actionscope[i].varname) == 0) {
			actionscope[i].citcount ++;
			return &actionscope[i];
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
}


/*
 * function:
 *   register a variable in actionscope array
 *   TODO: alloc register for active variable
 */
void push_variable(Node *node, char *varname, Spec *type) {
	assert(node && varname && type);
	find_duplication(varname);

	//calculate base
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
	while(asptr > 0 && actionscope[asptr].varname != NULL) {
		asptr --;
	}
}

/*-------------------------*/
int analyse_expression(Node *root);


void check_function_call(Node *root, VarElement *func) {
	if(!root || !func) return;
	assert(root->reduce_rule == AST_Exp_is_ID_LP_RP
		|| root->reduce_rule == AST_Exp_is_ID_LP_FuncCallArgList_RP);
	//need  <==> func->type->type.func.argv
	//given <==> root->reduce_rule
	if(func->type->btype != SpecTypeFunc) {
		//function not callable
		yyerrtype(ErrorNotCallable, root->lineno, root->child->idtype->type.cons.supval.st);
	}else if(func->type->type.func.argv == 0) {
		//0 parameter need, ? given
		if(root->reduce_rule != AST_Exp_is_ID_LP_RP) {
			yyerrtype(ErrorCall0vx, root->lineno);
		}
	}else{
		if(root->reduce_rule != AST_Exp_is_ID_LP_FuncCallArgList_RP) {
			//n parameter need, 0 given
			yyerrtype(ErrorCallnv0, root->lineno, func->type->type.func.argv);
		} else {
			//n parameter need, m given, n may equal to m
			Node *arglist = get_child_node(root, FuncCallArgList);
			for(int i = 0; i < func->type->type.func.argv; i++) {
				//check every parameter if mismatch
				Node *expnode = get_child_node_w(arglist->child, Exp);
				analyse_expression(expnode);
				if(!compare_type(func->type->type.func.arglist[i].type, expnode->idtype)) {
					yyerrtype(ErrorCallParameterNotMatch, root->lineno, i, root->child->idtype->type.cons.supval.st);
				}

				arglist = get_child_node(arglist, FuncCallArgList);
				if(!arglist) {
					//n parameter need, m given, n > m
					yyerrtype(ErrorCallngtm, root->lineno, func->type->type.func.argv, i);
				}
			}
			
			if(arglist->child->sibling) {
				//n parameter need, m given, n < m
				yyerrtype(ErrorCallnltm, root->lineno, func->type->type.func.argv);
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
	assert(root->token == IdList);
	
	Node *idlist = root;
	while(1) {
		char *varname = NULL;
		Spec *newtype = register_complex_var_with_type(type, idlist->child, &varname);
		push_variable(idlist->child, varname, newtype);

		if(idlist->child->sibling)
			idlist = idlist->child->sibling->sibling;
		else
			break;
	}
}


int analyse_expression(Node *root) {
	if(root == NULL) return 0;
	assert(root->token == Exp);

	Spec *type;
	VarElement *var;
	Node *id = NULL, *num = NULL, *st = NULL;
	Node *exp = NULL, *exp2 = NULL;

	switch(root->reduce_rule) {
		case AST_Exp_is_ID:
			id = get_child_node_w(root, ID);
			root->idtype = get_spec_by_btype(SpecTypeInt, SpecLvalue);
			var = find_variable(root, id->idtype->type.cons.supval.st);
			if(var)	root->idtype = var->type;
			break;
		case AST_Exp_is_ID_LP_RP:
			id = get_child_node_w(root, ID);
			root->idtype = get_spec_by_btype(SpecTypeInt, SpecLvalue);
			var = find_variable(root, id->idtype->type.cons.supval.st);
			if(var) {
				root->idtype = var->type->type.func.ret;
				check_function_call(root, var);
			}
			//check args type
			break;
		case AST_Exp_is_ID_LP_FuncCallArgList_RP:
			id = get_child_node_w(root, ID);
			root->idtype = get_spec_by_btype(SpecTypeInt, SpecLvalue);
			var = find_variable(root, id->idtype->type.cons.supval.st);
			if(var) {
				root->idtype = var->type->type.func.ret;
				check_function_call(root, var);
			}
			//check args type
			break;
		case AST_Exp_is_NUM:
			//rval
			num = root->child;
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
			}else if(exp->idtype->type.comp.plevel > 1){
				root->idtype = copy_spec(exp->idtype);
				root->idtype->type.comp.plevel --;
			}else if(root->idtype->type.comp.plevel == 1){
				root->idtype = exp->idtype->type.comp.spec;
			}else{
				yyerrtype(ErrorNotPointer, root->lineno);
			}
			break;
		case AST_Exp_is_BITAND_Exp:
			//int p; &p
			//lval -> OK, rval -> error
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = copy_spec(exp->idtype);
			if(exp->idtype->lval == SpecLvalue) {
				if(root->idtype->type.comp.size != 0) {
					logw("check here, something go wrong!");
				}
				root->idtype->type.comp.plevel ++;
			}else{
				yyerrtype(ErrorTakeRvalueAddress, root->lineno);
			}
			break;
		case AST_Exp_is_BITNOT_Exp:
			//int p; ~p; ==> rval
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = get_spec_by_btype(SpecTypeInt, SpecRvalue);
			if(exp->idtype->btype == SpecTypeUnsigned) {
				root->idtype = get_spec_by_btype(SpecTypeUnsigned, SpecRvalue);
			}else if(!type_is_bit(exp->idtype))
				yyerrtype(ErrorUnaryOperatorMismatch, root->lineno);
			break;
		case AST_Exp_is_NOT_Exp:
			//int p; !p
			//ok: num or (comp and (plevel>0 or size>0))
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = get_spec_by_btype(SpecTypeBool, SpecRvalue);
			if(!(type_is_num(exp->idtype)
				|| ( exp->idtype->btype == SpecTypeComplex
				   && (exp->idtype->type.comp.plevel
					   || exp->idtype->type.comp.size)
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
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			if(!compare_type(exp->idtype, exp2->idtype)) {
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
				type = find_type_of_struct_member(exp->idtype, id->idtype->type.cons.supval.st);
				if(type == NULL) {
					//no this member
					yyerrtype(ErrorNoSuchMember, root->lineno, type_format(exp->idtype));
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
			if(exp->idtype->btype != SpecTypeComplex) {
				yyerrtype(ErrorReferenceNotPointer, root->lineno, type_format(exp->idtype));
			} else if(exp->idtype->type.comp.size > 0) {
				yyerrtype(ErrorReferenceNotPointer, root->lineno, type_format(exp->idtype));
			} else if(exp->idtype->type.comp.plevel == 0) {
				//not a pointer
				yyerrtype(ErrorReferenceNotPointer, root->lineno, type_format(exp->idtype));
			} else if(exp->idtype->type.comp.plevel > 1) {
				//struct A {int x;} ***p; p->x;
				yyerrtype(ErrorReferenceStructMember, root->lineno, type_format(exp->idtype));
			} else {
				//struct A {int x;} p[10]; p->x;

				type = find_type_of_struct_member(exp->idtype->type.comp.spec, id->idtype->type.cons.supval.st);
				if(type == NULL) {
					//no this member
					yyerrtype(ErrorNoSuchMember, root->lineno, type_format(exp->idtype));
				} else {
					root->idtype = type;
				}
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
			 *      SpecTypeFloat,
			 *		SpecTypeInt, SpecTypeUnsigned,
			 *		SpecTypeBool, SpecTypeChar,
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
					if(exp->idtype->lval == SpecRvalue)
						root->idtype = exp->idtype;
					else {
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
					if(exp2->idtype->lval == SpecRvalue)
						root->idtype = exp2->idtype;
					else {
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
			 *      SpecTypeFloat,
			 *		SpecTypeInt, SpecTypeUnsigned,
			 *		SpecTypeBool, SpecTypeChar,
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
		case AST_Exp_is_Exp_BITAND_Exp:
		case AST_Exp_is_Exp_BITOR_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			/* a & b; a | b;
			 * limit: no float
			 * type(operand) in (
			 *      SpecTypeInt, SpecTypeUnsigned,
			 *		SpecTypeBool, SpecTypeChar,
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
			root->idtype = get_spec_by_btype(SpecTypeBool, SpecRvalue);
			/* limit: no float, no struct
			 * type(operand) not in (
			 *      SpecTypeStruct
			 *      )
			 * warning for pointer op int, just warning
			 * error for pointer op float
			 *        or struct op ?
			 * return SpecTypeBool
			 *
			 * result: rval
			 */
			if(exp->idtype->btype == SpecTypeStruct
			|| exp2->idtype->btype == SpecTypeStruct) {
				yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
			}else if(type_is_float(exp->idtype)){
				if(exp2->idtype->btype == SpecTypeComplex
				&& ( exp2->idtype->type.comp.size > 0
				   || exp2->idtype->type.comp.plevel > 0)
				  ) {
					yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
				}
			}else if(type_is_float(exp2->idtype)){
				if(exp->idtype->btype == SpecTypeComplex
				&& ( exp->idtype->type.comp.size > 0
				   || exp->idtype->type.comp.plevel > 0)
				  ) {
					yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp->idtype), type_format(exp2->idtype));
				}
			}
			break;
		case AST_Exp_is_Exp_AND_Exp:
		case AST_Exp_is_Exp_OR_Exp:
			//all type except struct
			//	result: rval
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = get_spec_by_btype(SpecTypeBool, SpecRvalue);
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
			// FIXME:
			if(!type_is_bit(exp2->idtype)) {
				yyerrtype(ErrorIndexNotInteger, root->lineno);
			}else if(exp->idtype->btype != SpecTypeComplex){
				yyerrtype();
			}else if(exp->idtype->type.comp.size > 0){
			}else if(exp->idtype->type.comp.plevel > 0){
			}else{
			}
			break;
		default:
			assert(0);
	}
}


int analyse_statement(Node *root) {
	assert(0);
	if(root == NULL) return 0;
}

int analyse_function(Node *root, Spec *functype) {
	if(root == NULL) return 0;
	assert(root->reduce_rule == AST_Block_is_Specifier_FuncDec_CompSt);

	push_barrier();
}

int analyse_vardef(Node *root) {
	if(root == NULL) return 0;
	assert(root->token == VarDef);
	Spec *type = find_type_of_spec(get_child_node_w(root, Specifier));
	Node *declist = get_child_node_w(root, DecList);
	while(declist) {
		char *varname = NULL;
		Node *vardec = get_child_node_w(declist->child, VarDec);
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

	assert(root->token == Program);
	Node *blocklist = get_child_node_w(root, BlockList);

	//block reduce
	while(blocklist != NULL) {
		Spec *type = NULL;
		Node *idlist = NULL;
		Node *block = get_child_node_w(blocklist, Block);
		switch(block->reduce_rule) {
			case AST_Block_is_Specifier_FuncDec_CompSt:
				type = register_type_function(get_child_node_w(block, FuncDec));
				push_variable(block, get_child_node_w(get_child_node_w(block, FuncDec), ID)->idtype->type.cons.supval.st, type);
				analyse_function(block, type);
				break;
			case AST_Block_is_StructDec_IdList_SEMI:
				type = register_type_struct(block->child);
				idlist = get_child_node_w(block, IdList);
				register_idlist(idlist, type);
				break;
			case AST_Block_is_StructDec_SEMI:
				register_type_struct(block->child);
				break;
			case AST_Block_is_VarDef:
				analyse_vardef(get_child_node_w(block, VarDef));
				break;
		}

		blocklist = get_child_node(blocklist, BlockList);
	}

	return 0;
}

void init_seman()
{
#define STATE_RESET do{ \
	asptr = 0; \
	actionlevel = 0; \
} while(0)

#ifdef __DEBUG__
	
	UNIT_TEST_START;
	/*unit test start*/
	extern Node *astroot;
	void yy_scan_string(char *);

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
		Node *structdec = find_child_node(astroot, StructDec);
		if(structdec != NULL) register_type_struct(structdec);
		Node *vardef = find_child_node(astroot, VarDef);
		Node *spec = get_child_node(vardef, Specifier);
		Node *declist = get_child_node_w(vardef, DecList);
		Spec *rawtype = find_type_of_spec(spec);
		analyse_vardef(vardef);
		while(declist) {
			char *varname;
			Node *vardec = get_child_node_w(declist->child, VarDec);
			Spec *newtype = register_complex_var_with_type(rawtype, vardec, &varname);
			UNIT_TEST_EQUAL(compare_type(newtype, find_variable(vardec, varname)->type), true);

			declist = get_child_node(declist, DecList);
		}
	}

	char *exp_test_sample[] = {
		"int a; int main(){a;}",
		"int func(){func();}",
		"int func(int a, int b){func(1, 3);};}",
		"int a; int func(int a, int *p){(func(16, &a)+56)*78;}",
		"int main(){int a; ~a*45+(12*3.4)/78+7;}",
		"int main(){+7;}",
		"int main(){-7;}",
		"int main(){89+-7;}",
		"int main(){99--7;}",
		"int *a; int main(){*a;}",
		"int a; int main(){*&a;}",
		"int a; int main(){!a&&(1||a)&&(!~~!(a&a|a));}",
		"int func(){\"hello\"[0] == 97 + 7;}",
		"int a; int main(){a = 45,\"main\", 1.35;}",
		"struct A{int a;}x; int main(){a = x.a*a*x.a&x.a;}",
		"struct A{int a;}*p;int a; int main(){p->a*a*p->a&p->a;}",
		"struct A{int a;}*p;int a; int main(){p->a*a*p->a&p->a;}",
		"struct A{int a;}p[0][1];int main(){p->a*p[0]->a*p[0][0].a;}",
	};

	int exp_test_answer[][2] = {
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeInt, SpecRvalue},
		{SpecTypeBool, SpecRvalue},
		{SpecTypeInt, SpecLvalue},
	};

	for(int i = 0; i < sizeof(exp_test_sample)/sizeof(exp_test_sample[0]); i++) {
		//TODO
		STATE_RESET;
		yy_scan_string(exp_test_sample[i]);
		yyparse();
		Node *vardef = find_child_node(astroot, VarDef);
		Node *exp = find_child_node(astroot, Exp);
		analyse_vardef(vardef);
		analyse_expression(exp);
		logw("%d\n", i);
		print_exp(exp);
		UNIT_TEST_ASSERT(compare_type(exp->idtype, get_spec_by_btype(exp_test_answer[i][0], exp_test_answer[i][1])), "fail at #%d: '%s'", i, exp_test_sample[i]);
	}

	UNIT_TEST_END;
#else
	STATE_RESET;
#endif
}
