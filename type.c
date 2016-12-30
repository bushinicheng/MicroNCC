#include "common.h"
#include "type.h"
#include <memory.h>

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static uintptr_t specptr = 0;
Spec specpool[MAX_SIZE];

Spec *register_type_function(Node *root);
Spec *register_type_array(Node *root);
Spec *register_type_struct(Node *root);

/* root=>FuncDec
 * FuncDec:ID LP RP
 *        |ID LP FuncDefArgList RP
 * FuncDefArgList:FuncDefArg COMMA FuncDefArgList
 *               |FuncDefArg
 * FuncDefArg:Specifier ID
 * Specifier:TYPE
 *          |STRUCT ID
 * */
Spec *register_type_function(Node *root) {
	Spec *newspec = &specpool[specptr++];
	newspec->btype = SpecTypeFunc;
	newspec->width = 0;

	Node *deflist = root->child->sibling->sibling;
	newspec->type.func.ret = NULL;
	newspec->type.func.args = register_argslist(deflist);
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
#define btype_register(b, w) do {\
	specpool[specptr].btype = b;\
	specpool[specptr].width = w;\
	specptr ++;\
} while(0)

	btype_register(SpecTypeConst,    4);
	btype_register(SpecTypeVoid,     4);
	btype_register(SpecTypeChar,     4);
	btype_register(SpecTypeInt,      4);
	btype_register(SpecTypeUnsigned, 4);
	btype_register(SpecTypeFloat,    4);
}
