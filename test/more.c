bool is_syntax_error = false;
int last_syntax_error;

int (*func)(int, int);
//basic data type
enum {
	SpecTypeConst,
	SpecTypeVoid,
	/*number*/
	SpecTypeInt8,//also SpecTypeChar
	SpecTypeUint8,//also SpecTypeBool
	SpecTypeInt16,
	SpecTypeUint16,
	SpecTypeInt32,
	SpecTypeUint32,
	SpecTypeInt64,
	SpecTypeUint64,
	SpecTypeFloat32,
	SpecTypeFloat64,
	/*number*/
	SpecTypeString, //char *s = "string"; equivalent to `char *`
	//the above must be registered firstly
	SpecTypeArray,
	SpecTypePointer,
	SpecTypeComplex,
	SpecTypeStruct,
	SpecTypeUnion,
	SpecTypeFunction,
};

enum {
	SpecLvalue = 0,
	SpecRvalue = 1,
};

struct tagSpec;

typedef struct tagSinArg {
	struct tagSpec *type;
	char *varname;
} SinArg;

struct SinArg {
	struct Spec *type;
	char *varname;
};

struct Spec {
	bool lval;//default to be zero
			//0 for lval, 1 for rval
	bool aslevel;//default to be zero
			//0 for global declaration, 1 for local declaration
	int btype;
	int width;
	char *format_string;
	union {
		struct {
			struct Spec *ret;
			struct SinArg *arglist;
			size_t argv;
		} func;//func type

		struct {
			char *struc_name;
			struct {
				char *varname;
				off_t offset;//offset of current var in struct
				struct tagSpec *spec;
			} *varlist;
			size_t size;
		} struc;//for structure

		struct {
			struct tagSpec *spec;//actual spec,such as `struct A`
			size_t *dim;//dimension array:a[2][3][4]=>[2,3,4]
			size_t size;//length of(dim)
			int plevel;//pointer level
					   //default to be zero(not pointer)
		} comp;//complex variable, array or pointer or both

		//for constant, such as "hello", 12, 5.1
		struct {
			int suptype;//such as INT for TYPE or float for NUM
					//'i' for INT, 'u' for unsigned
					//'o' for OCT, 'x' for HEX
					//**for convenience, just 'i' is used
					//'f' for FLOAT
					//'c' for char, 's' for string
					//'p' for pointer, maybe never use
			struct {
				int i;float f;double llf;void *p;
				char* st;// the address of string or id
				uintptr_t da;//dest addr of structure or function
			} supval;
		} cons; //constant value
	};
} Spec;

struct VarElement {
	char *varname;
	struct Spec *type;
	struct Node *node;
	int citcount;
};

int asptr, actionlevel;
struct VarElement actionscope[102400];//action scope of variable


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
	int a[16] = {45,12,45,323};
	int a = b = c = 12;
	
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
struct VarElement find_variable(struct Node *node, char *varname) {
	assert(node && varname);
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
void push_variable(struct Node *node, char *varname, struct Spec *type) {
	assert(node && varname && type);
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

void check_function_call(struct Node *root, struct VarElement *func) {
	if(!root || !func) return;
	assert(root->production == AST_Exp_is_ID_LP_RP
		|| root->production == AST_Exp_is_ID_LP_FuncCallArgList_RP);
	//need  <==> func->type->func.argv
	//given <==> root->production
	if(func->type->btype != SpecTypeFunction) {
		//function not callable
		yyerrtype(ErrorNotCallable, root->lineno, get_child_node_w(root, ID)->idtype->cons.supval.st);
	}else if(func->type->func.argv == 0) {
		//0 parameter need, ? given
		if(root->production != AST_Exp_is_ID_LP_RP) {
			yyerrtype(ErrorCall0vx, root->lineno);
		}
	}else{
		if(root->production != AST_Exp_is_ID_LP_FuncCallArgList_RP) {
			//n parameter need, 0 given
			yyerrtype(ErrorCallnv0, root->lineno, func->type->func.argv);
		} else {
			//n parameter need, m given, n may equal to m
			struct Node *arglist = get_child_node(root, FuncCallArgList);
			for(int i = 0; i < func->type->func.argv; i++) {
				if(!arglist) {
					//n parameter need, m given, n > m
					yyerrtype(ErrorCallngtm, root->lineno, func->type->func.argv, i);
					break;
				}
				//check every parameter if mismatch
				struct Node *expnode = get_child_node_dw(arglist, 2, FuncCallArg, Exp);
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

void register_idlist(struct Node *root, struct Spec *type) {
	if(!root) return;
	assert(root->token == IdList);
	
	struct Node *idlist = root;
	while(idlist) {
		char *varname = NULL;
		struct Node *vardec = get_child_node_w(idlist, VarDec);
		struct Spec *newtype = register_complex_var_with_type(type, vardec, &varname);
		push_variable(vardec, varname, newtype);

		idlist = get_child_node(idlist, IdList);
	}
}


int analyse_expression(struct Node *root) {
	if(root == NULL) return 0;
	assert(root->token == Exp);

	struct Spec *type;
	struct VarElement *var;
	struct Node *id = NULL, *num = NULL, *st = NULL;
	struct Node *exp = NULL, *exp2 = NULL;

	switch(root->production) {
		case AST_Exp_is_ID:
			id = get_child_node_w(root, ID);
			root->idtype = convert_btype_to_pointer(SpecTypeInt, SpecLvalue);
			var = find_variable(root, id->idtype->cons.supval.st);
			if(var)	root->idtype = var->type;
			break;
		case AST_Exp_is_ID_LP_RP:
			id = get_child_node_w(root, ID);
			root->idtype = convert_btype_to_pointer(SpecTypeInt, SpecLvalue);
			var = find_variable(root, id->idtype->cons.supval.st);
			if(var) {
				root->idtype = var->type->func.ret;
				check_function_call(root, var);
			}
			//check args type
			break;
		case AST_Exp_is_ID_LP_FuncCallArgList_RP:
			id = get_child_node_w(root, ID);
			root->idtype = convert_btype_to_pointer(SpecTypeInt, SpecLvalue);
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
			root->idtype = convert_btype_to_pointer(SpecTypeInt, SpecRvalue);
			if(exp->idtype->btype == SpecTypeUint32) {
				root->idtype = convert_btype_to_pointer(SpecTypeUint32, SpecRvalue);
			}else if(!type_is_bit(exp->idtype))
				yyerrtype(ErrorUnaryOperatorMismatch, root->lineno);
			break;
		case AST_Exp_is_LNOT_Exp:
			//int p; !p
			//ok: num or (comp and (plevel>0 or size>0))
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = convert_btype_to_pointer(SpecTypeBool, SpecRvalue);
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
			 *      SpecTypeFloat,
			 *		SpecTypeInt, SpecTypeUint32,
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
			 *      SpecTypeFloat,
			 *		SpecTypeInt, SpecTypeUint32,
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
			 *      SpecTypeInt, SpecTypeUint32,
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
			root->idtype = convert_btype_to_pointer(SpecTypeBool, SpecRvalue);
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
			root->idtype = convert_btype_to_pointer(SpecTypeBool, SpecRvalue);
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
			assert(0);
	}
}


int analyse_statement(struct Node *root) {
	if(root == NULL) return 0;
	assert(root->token == Stmt);

	struct Node *exp = NULL, *exp2 = NULL, *exp3 = NULL;
	struct Node *vardef = NULL, *stmt = NULL;
	struct Node *stmt2 = NULL, *stmtlist = NULL;
	switch(root->production) {
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
			assert(0);
	}
}

int analyse_function(struct Node *root, struct Spec *functype) {
	if(root == NULL) return 0;

	push_barrier();
	/*register function arguments*/
	for(int i = 0; i < functype->func.argv; i++) {
		struct Spec *type = functype->func.arglist[i].type;
		char *varname = functype->func.arglist[i].varname;
		if(type == NULL	|| varname == NULL)
			logw("check here!\n");
		push_variable(root, varname, type);
	}


	struct Node *stmt = NULL;
	struct Node *stmtlist = get_child_node_dw(root, 2, CompSt, StmtList);

	/*analyse every statements*/
	while(stmtlist) {
		stmt = get_child_node_w(stmtlist, Stmt);
		analyse_statement(stmt);
		stmtlist = get_child_node(stmtlist, StmtList);
	}

	pop_scope();
}

int analyse_vardef(struct Node *root) {
	if(root == NULL) return 0;
	assert(root->token == VarDef);
	struct Spec *type = find_type_of_spec(get_child_node_w(root,  Specifier));
	struct Node *declist = get_child_node_w(root, DecList);
	while(declist) {
		char *varname = NULL;
		struct Node *vardec = get_child_node_dw(declist, 2, Dec, VarDec);
		struct Spec *type = register_type_complex_var(vardec, &varname);
		//push and check
		vardec->idtype = type;
		push_variable(vardec, varname, type);
		declist = get_child_node(declist, DecList);
	}
	return 0;
}

int semantic_analysis(struct Node *root)
{
	if(root == NULL)
		return 0;

	assert(root->token == Program);
	struct Node *blocklist = get_child_node_w(root, BlockList);

	//block reduce
	while(blocklist != NULL) {
		struct Spec *type = NULL;
		struct Node *idlist = NULL;
		struct Node *block = get_child_node_w(blocklist, Block);
		switch(block->production) {
			case AST_Block_is_struct_Specifier_FuncDec_CompSt:
				type = register_type_function(get_child_node_w(block, FuncDec));
				push_variable(block, get_child_node_w(get_child_node_w(block, FuncDec), ID)->idtype->cons.supval.st, type);
				analyse_function(block, type);
				break;
			case AST_Block_is_StructDec_SEMI:
				register_type_struct(get_child_node_w(block, StructDec));
				break;
			case AST_Block_is_VarDef:
				analyse_vardef(get_child_node_w(block, VarDef));
				break;
			default:
				assert(0);
		}

		blocklist = get_child_node(blocklist, BlockList);
	}

	return 0;
}

void init_seman()
{
;
}
