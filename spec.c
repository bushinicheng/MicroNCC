#include "common.h"
#include <memory.h>

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static uintptr_t specptr = 0;
Spec specpool[MAX_SIZE];

Spec *register_type_function(Node *root);
Spec *register_type_array(Node *root);
Spec *register_type_struct(Node *root);

/* DefArgList:DefArg COMMA DefArgList
 *           |DefArg
 * DefArg:Specifier ID
 * */
Args *register_argslist(Node *root) {
	// a simple stack;
	int p = 0;
	SinArg stack[2000];//assume no more than 2000 args

	while(root) {
		Node *defarg = root->child;
		Node *defargspec = defarg->child;
		if(defargspec->semanval == AST_Specifier_is_TYPE) {
			switch(defargspec->child->semanval) {
				case INT: 
					stack[p].type = &specpool[SpecTypeInt];
					break;
				case CHAR: 
					stack[p].type = &specpool[SpecTypeInt];
					break;
				case FLOAT: 
					stack[p].type = &specpool[SpecTypeInt];
					break;
			}

		} else if(defargspec->semanval == AST_Specifier_is_StructSpecifier) {
			stack[p].type = register_struct(defargsspec);
		}
		
		stack[p].id = defargspec->sibling->exval->st;

		p++;
		root = root->next->next;
	}

	Args *ret = (Args*)malloc(sizeof(Args));
	ret->arglist = stack;
	ret->argv = p;

	return ret;
};

/* root=>FuncDec
 * FuncDec:ID LP RP
 *        |ID LP DefArgList RP
 * DefArgList:DefArg COMMA DefArgList
 *           |DefArg
 * DefArg:Specifier ID
 * */
Spec *register_type_function(Node *root) {
	Spec *newspec = &specpool[specptr++];
	newspec->btype = SpecTypeFunc;
	newspec->width = 0;

	Node *deflist = root->child->sibling->sibling;
	newspec->func.ret = NULL;
	newspec->func.args = register_argslist(deflist);
	return NULL;
}

/*root=>Dec
 *
 * Def: Specifier DecList SEMI;
 *
 * DecList: Dec COMMA DecList
 *        | Dec
 *
 * Dec: VarDec
 *    | VarDec ASSIGNOP Exp
 */
Spec *register_type_array(Node *root) {
	return NULL;
}

Spec *register_type_struct(Node *root) {
	return NULL;
}


void init_spec() {
#define btype_register(btype, width) do {\
	specpool[specptr].btype = btype;\
	specpool[specptr].width = width;\
	specptr ++;\
} while(0)

	btype_register(SpecTypeConst,    4);
	btype_register(SpecTypeVoid,     4);
	btype_register(SpecTypeChar,     4);
	btype_register(SpecTypeInt,      4);
	btype_register(SpecTypeUnsigned, 4);
	btype_register(SpecTypeFloat,    4);
}
