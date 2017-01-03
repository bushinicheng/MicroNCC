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
		if(strcmp(varname, actionscope[i].varname) == 0)
			actionscope[i].citcount ++;
			return &actionscope[i];
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
			var = find_variable(root, id->idtype->type.cons.supval.st);
			if(var)	root->idtype = var->type;
			break;
		case AST_Exp_is_ID_LP_RP:
			id = get_child_node_w(root, ID);
			var = find_variable(root, id->idtype->type.cons.supval.st);
			if(var)	root->idtype = var->type->type.func.ret;
			check_function_call(root, var);
			//check args type
			break;
		case AST_Exp_is_ID_LP_FuncCallArgList_RP:
			id = get_child_node_w(root, ID);
			var = find_variable(root, id->idtype->type.cons.supval.st);
			if(var)	root->idtype = var->type->type.func.ret;
			check_function_call(root, var);
			//check args type
			break;
		case AST_Exp_is_NUM:
			num = root->child;
			root->idtype = num->idtype;
			break;
		case AST_Exp_is_ADD_NUM:
			num = get_child_node_w(root, NUM);
			root->idtype = num->idtype;
			break;
		case AST_Exp_is_SUB_NUM:
			num = get_child_node_w(root, NUM);
			root->idtype = num->idtype;
			break;
		case AST_Exp_is_MULT_Exp:
			//int *p; *p
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = copy_type(exp->idtype);
			if(root->idtype->type.comp.plevel > 0)
				root->idtype->type.comp.plevel --;
			else
				yyerrtype(ErrorNotPointer, root->lineno);
			break;
		case AST_Exp_is_BITAND_Exp:
			//int p; &p
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = copy_type(exp->idtype);
			if(exp->idtype->type.cons.suptype == 0 || exp->idtype->type.cons.suptype == 's')
				root->idtype->type.comp.plevel ++;
			else
				yyerrtype(ErrorTakeRvalueAddress, root->lineno);
			break;
		case AST_Exp_is_BITNOT_Exp:
			//int p; &p
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			if(exp->idtype->type.cons.suptype != 'i')
				yyerrtype(ErrorUnaryOperatorMismatch, root->lineno);
			break;
		case AST_Exp_is_NOT_Exp:
			//int p; !p
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = new_spec();
			root->idtype->btype = SpecTypeBool;
			if(exp->idtype->type.cons.suptype != 'i')
				yyerrtype(ErrorUnaryOperatorMismatch, root->lineno);
			break;
		case AST_Exp_is_STRING:
			//char *p = "string"
			st = get_child_node_w(root, STRING);
			analyse_expression(exp);
			root->idtype = new_spec();
			root->idtype->btype = SpecTypeComplex;
			root->idtype->type.comp.plevel = 1;
			root->idtype->type.comp.spec = get_spec_by_btype(SpecTypeChar);
			root->idtype->aslevel = 1;
			break;
		case AST_Exp_is_Exp_ASSIGNOP_Exp:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			root->idtype = exp->idtype;
			if(!compare_type(exp->idtype, exp2->idtype)) {
				yyerrtype(ErrorAssignIncompatible, root->lineno, type_format(exp->idtype));
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
			//plevel = 1 and array.size = 0 and btype = array
			if(exp->idtype->btype != SpecTypeArray) {
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
		case AST_Exp_is_Exp_MULT_Exp:
		case AST_Exp_is_Exp_DIV_Exp:
		case AST_Exp_is_Exp_BITAND_Exp:
		case AST_Exp_is_Exp_BITOR_Exp:
			//SpecType, SpecTypeBool, SpecTypeInt,
			//SpecTypeUnsigned, SpecTypeFloat, SpecTypePointer,
			//'i', 'p', 's' is OK
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			break;
		case AST_Exp_is_Exp_EQ_Exp:
		case AST_Exp_is_Exp_LT_Exp:
		case AST_Exp_is_Exp_LE_Exp:
		case AST_Exp_is_Exp_NE_Exp:
		case AST_Exp_is_Exp_GT_Exp:
		case AST_Exp_is_Exp_GE_Exp:
		case AST_Exp_is_Exp_AND_Exp:
		case AST_Exp_is_Exp_OR_Exp:
			//all type except struct
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			exp2 = get_child_node_with_skip_w(root, Exp, 1);
			analyse_expression(exp2);
			break;
		case AST_Exp_is_LP_Exp_RP:
			exp = get_child_node_w(root, Exp);
			analyse_expression(exp);
			root->idtype = exp->idtype;
			break;
		case AST_Exp_is_Exp_LB_Exp_RB:
			break;
		default:
			assert(0);
	}
}

int analyse_statement(Node *root) {
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
				push_variable(block, get_child_node_w(block->child, ID)->idtype->type.cons.supval.st, type);
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
		"int a;", "int a, b, c;", "int *a, b[10], *c[10]",
		"int **a[2][3][4];",
		"int a = 0;", "int a = 0, b = 10;", "int a = 0, *p = &a;",
		"struct A {int a;}; struct A a, *b, c[2], *d[3];"
	};
	
	for(int i = 0; i < sizeof(vardef_test_sample)/sizeof(vardef_test_sample[0]); i++) {
		//TODO
		STATE_RESET;
		logw("%d\n", i);
		yy_scan_string(vardef_test_sample[i]);
		yyparse();
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

	UNIT_TEST_END;
#else
	STATE_RESET;
#endif
}
