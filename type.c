#include "common.h"
#include <memory.h>

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static uintptr_t specptr = 0;
Spec specpool[MAX_SIZE];

Spec *register_type_function(Node *root);
Spec *register_type_array(Node *root);
Spec *register_type_struct(Node *root);

size_t get_size_of_btype(int btype) {
	switch(btype) {
		case SpecTypeConst:    return 0;
		case SpecTypeVoid:     return 4;
		case SpecTypeChar:     return 1;
		case SpecTypeInt:      return 4;
		case SpecTypeUnsigned: return 4;
		case SpecTypeFloat:    return 4;
		case SpecTypePointer:  return 4;
	}

	return 0;
}

Spec *find_type_of_spec(Node *root) {
	assert(root->token == Specifier);
	char *struct_id = NULL;
	
	if(root->reduce_rule == AST_Specifier_is_TYPE) {
		switch(root->child->suptype) {
			case CHAR:
				return &specpool[SpecTypeChar];
			case INT:
				return &specpool[SpecTypeInt];
			case FLOAT:
				return &specpool[SpecTypeFloat];
			default:
				yyerr("error type B:type `%c` not supported!\n", root->child->suptype);
				return NULL;
		}
	} else {//AST_Specifier_is_STRUCT_ID
		struct_id = root->child->sibling->supval.st;
		for(int i = specptr - 1; i; i--) {
			if(specpool[i].btype == SpecTypeStruct) {
				if(strcmp(specpool[i].type.struc.struc_name, struct_id) == 0) {
					return &specpool[i];
				}
			}
		}
	}

	//type not found!
	yyerr("error type B: type `struct %s` not declared!\n", struct_id);
	return NULL;
}




/* IN[0]:struct tagNode *
 *   a pointer point to ast node
 *   STRICT: root->token == FuncDec
 * function:
 *   register the type of function, including type of arguments
 *   and type of return value
 *
 *
 * root=>FuncDec
 *
 * Block:Specifier FuncDec CompSt
 *
 * FuncDec:ID LP RP
 *        |ID LP FuncDefArgList RP
 *
 * FuncDefArgList:FuncDefArg COMMA FuncDefArgList
 *               |FuncDefArg
 *
 * FuncDefArg:Specifier ID
 *
 * Specifier:TYPE
 *          |STRUCT ID
 * */
Spec *register_type_function(Node *root) {
	Spec *newspec = &specpool[specptr++];
	assert(root->token == FuncDec);
	newspec->btype = SpecTypeFunc;
	newspec->width = 0;
	newspec->type.func.ret = find_type_of_spec(root->parent->child);

	if(root->reduce_rule == AST_FuncDec_is_ID_LP_RP)
		return newspec;

	size_t parg = 0;
	SinArg *args = (SinArg*)get_memory_pointer();
	Node *deflist = root->child->sibling->sibling;
	//register FuncDefArg recursively
	while(1) {
		/* deflist as entry => FuncDefArg
		 * register FuncDef by `FuncDefArg:Specifier ID` 
		 */
		args[parg].type = find_type_of_spec(deflist->child->child);
		args[parg].varname = deflist->child->child->sibling->supval.st;
		parg ++;
		if(deflist->child->sibling == NULL)
			break;
		else
			deflist = deflist->child->sibling->sibling;
	}
	require_memory(sizeof(SinArg) * parg);
	newspec->type.func.argv = parg;
	newspec->type.func.arglist = args;
	
	return newspec;
}




/* IN[0]:struct tagNode *
 *   a pointer point to ast node
 *   STRICT: root->token == VarDec
 * function:
 *   register the type of target array or pointer variable
 *
 *
 * root=>VarDec
 *       and VarDec !=> ID
 *
 * VarDef: Specifier DecList SEMI;
 *
 * DecList: Dec COMMA DecList
 *        | Dec
 *
 * Dec: VarDec
 *    | VarDec ASSIGNOP Exp
 *
 * VarDec:ID
 *       |MULT VarDec
 *       |VarDec LB NUM RB
 */
Spec *register_type_complex_var(Node *root) {
	Spec *newspec = &specpool[specptr++];
	newspec->btype = SpecTypeArray;
	newspec->width = 1;
	assert(root->token == VarDec);
	Node *vardef = root;
	while(vardef->reduce_rule != AST_VarDef_is_Specifier_DecList_SEMI) {
		vardef = vardef->parent;
	}
	newspec->type.array.spec = find_type_of_spec(vardef->child);
	
	//process star corresponding to `POINTER`
	while(root->reduce_rule == AST_VarDec_is_MULT_VarDec) {
		newspec->plevel ++;
		root = root->child->sibling;
	}

	//process dim corresponding to `Array`
	newspec->type.array.size = 0;
	newspec->type.array.dim = (size_t*)get_memory_pointer();
	while(root->reduce_rule == AST_VarDec_is_VarDec_LB_NUM_RB) {
		int cur_dim = root->child->sibling->sibling->supval.i;
		newspec->type.array.dim[newspec->type.array.size] = cur_dim;
		newspec->width = newspec->width * cur_dim;
		newspec->type.array.size ++;
		root = root->child;
	}

	if(newspec->plevel == 0)//pure array
		newspec->width = newspec->type.array.spec->width * newspec->width;
	else//pointer array
		newspec->width = newspec->type.array.spec->width * get_size_of_btype(SpecTypePointer);

	require_memory(sizeof(size_t) * newspec->type.array.size);

	return newspec;
}



/* IN[0]:struct tagNode *
 *   a pointer point to ast node
 *   STRICT: root->token == StructDec
 * function:
 *   register the struct type
 *
 *
 * root=>StructDec
 *
 * Block:StructDec IdList SEMI
 *
 * StructDec:STRUCT ID LC StructDecVarList RC
 *
 * StructDecVarList:StructDecVar StructDecVarList
 *                 |StructDecVar
 * 
 * StructDecVar:Specifier IdList SEMI
 *             |StructDec IdList SEMI //here need recursive
 *
 * IdList:ID COMMA IdList
 *       |ID
 */
Spec *register_type_struct(Node *root) {
	int nr_var = 0, struct_width = 0;
	assert(root->token == StructDec);
	Spec *newspec = &specpool[specptr++];
	newspec->btype = SpecTypeStruct;
	newspec->width = 0;//just init
	newspec->type.struc.struc_name = root->child->sibling->supval.st;

	Node *dvl = root->child->sibling->sibling->sibling;
	//first traverse to count up number of variable
	while(1) {
		Node *idlist = dvl->child->child->sibling;
		while(1) {
			nr_var ++;
			if(!idlist->child->sibling) break;
			else idlist = idlist->child->sibling->sibling;
		}
		if(!dvl->child->sibling) break;
		else dvl = dvl->child->sibling;
	}
	//malloc memory for struc.varlist
	newspec->type.struc.varlist = get_memory_pointer();
	require_memory(sizeof(newspec->type.struc.varlist[0]) * nr_var);

	//second traverse to register type of variable
	dvl = root->child->sibling->sibling->sibling;
	while(1) {
		Spec *cur_type = NULL;
		Node *type_node = dvl->child->child;
		Node *idlist = dvl->child->child->sibling;
		if(type_node->token == Specifier)
			cur_type = find_type_of_spec(type_node);
		else {
			cur_type = register_type_struct(type_node);
			cur_type->aslevel = newspec->aslevel + 1;
		}

		while(1) {
			//TODO:round the size of width to 4
			newspec->type.struc.varlist[newspec->type.struc.size].spec = cur_type;
			newspec->type.struc.varlist[newspec->type.struc.size].varname = idlist->child->supval.st;
			newspec->type.struc.varlist[newspec->type.struc.size].offset = newspec->width;
			newspec->type.struc.size ++;
			newspec->width += cur_type->width;

			if(!idlist->child->sibling) break;
			else idlist = idlist->child->sibling->sibling;
		}
		if(!dvl->child->sibling) break;
		else dvl = dvl->child->sibling;
	}

	/*final check*/
	assert(newspec->type.struc.size == nr_var);
	return newspec;
}



/* IN[0]:struct tagSpec *
 *   the type pointer to specpool
 * function:
 *   dumps the spec structure
 *   for debugging
 */
void print_spec(Spec *type) {
	static int indent = 0;
	switch(type->btype) {
		case SpecTypeVoid    :printf("void ");return;
		case SpecTypeChar    :printf("char ");return;
		case SpecTypeInt     :printf("int ");return;
		case SpecTypeUnsigned:printf("unsigned ");return;
		case SpecTypeFloat   :printf("float ");return;
	}

	if(type->btype == SpecTypeStruct) {
		int i;
		for(int j = 0; j < indent - 2; j++)
			printf(" ");
		printf("struct %s:%d {\n", type->type.struc.struc_name, type->aslevel);
		Spec *old_spec = type->type.struc.varlist[0].spec;
		for(int j = 0; j < indent + 2; j++)
			printf(" ");
		indent += 2;
		print_spec(type->type.struc.varlist[0].spec);
		indent -= 2;
		printf("%s(%d)", type->type.struc.varlist[0].varname, type->type.struc.varlist[0].offset);
		for(i = 1; i < type->type.struc.size; i++) {
			if(old_spec != type->type.struc.varlist[i].spec) {
				printf(";\n");
				for(int j = 0; j < indent + 2; j++)
					printf(" ");
				indent += 2;
				print_spec(type->type.struc.varlist[i].spec);
				indent -= 2;
				printf("%s(%d)", type->type.struc.varlist[i].varname, type->type.struc.varlist[i].offset);
			}
			else
				printf(", %s(%d)", type->type.struc.varlist[i].varname, type->type.struc.varlist[i].offset);
			old_spec = type->type.struc.varlist[i].spec;
		}

		printf(";\n");
		for(int j = 0; j < indent; j++)
			printf(" ");
		if(indent == 0)
			printf("};\n");
		else
			printf("} ");
	}else if(type->btype == SpecTypeFunc) {
		int i;
		print_spec(type->type.func.ret);
		printf("function(");
		for(i = 0; i < type->type.func.argv - 1; i++) {
			print_spec(type->type.func.arglist[i].type);
			printf("%s, ", type->type.func.arglist[i].varname);
		}
		print_spec(type->type.func.arglist[i].type);
		printf("%s);\n", type->type.func.arglist[i].varname);
	}else if(type->btype == SpecTypeArray) {
		print_spec(type->type.array.spec);
		for(int i = 0; i < type->plevel; i++)
			printf("*");
		printf("array");
		for(int i = type->type.array.size - 1; i >= 0; i--) {
			printf("[%lu]", type->type.array.dim[i]);
		}
		printf(";\n");
	}
}

void init_spec() {
	specptr = 0;
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
	btype_register(SpecTypePointer,  4);

#ifdef __DEBUG__
	STATE_TEST_START;
	for(int i = 0; i < 6; i++) {
		STATE_TEST_EQUAL(specpool[i].btype, i);
	}
	STATE_TEST_END;

	UNIT_TEST_START;
	/*unit test start*/
	uintptr_t utptr = 0;
	Node utpool[1024];
	Spec *retspec;
	/***********testcase 1 int func()*************/
	utpool[0].supval.st = "func";
	make_node(&utpool[0], AST_NONTERMINALBEGIN, ID);
	make_node(&utpool[1], AST_NONTERMINALBEGIN, LP);
	make_node(&utpool[2], AST_NONTERMINALBEGIN, RP);
	make_node(&utpool[3], AST_FuncDec_is_ID_LP_RP, FuncDec, &utpool[0], &utpool[1], &utpool[2]);
	utpool[4].suptype = INT;
	make_node(&utpool[4], AST_NONTERMINALBEGIN, TYPE);
	make_node(&utpool[5], AST_Specifier_is_TYPE, Specifier, &utpool[4]);
	make_node(&utpool[6], AST_NONTERMINALBEGIN, CompSt);
	make_node(&utpool[7], AST_Block_is_Specifier_FuncDec_CompSt, Block, &utpool[5], &utpool[3], &utpool[6]);
	retspec = register_type_function(&utpool[3]);
	if(retspec->type.func.argv != 0
	|| retspec->type.func.arglist != NULL
	|| retspec->type.func.ret->btype != SpecTypeInt) {
		logd("test failed at #01.\n");
		UNIT_TEST_FAIL;
	}

	/********testcase 2 int func(int a, char b, int c)********/
	extern Node *astroot;
	void yy_scan_string(char *);
	yy_scan_string("int func(int a, char b, int c){return 0;}");
	yyparse();
	retspec = register_type_function(astroot->child->child->child->sibling);
	if(retspec->type.func.argv != 3
	|| retspec->type.func.arglist[0].type->btype != SpecTypeInt
	|| retspec->type.func.arglist[1].type->btype != SpecTypeChar
	|| retspec->type.func.arglist[2].type->btype != SpecTypeInt
	|| strcmp(retspec->type.func.arglist[0].varname, "a") != 0
	|| strcmp(retspec->type.func.arglist[1].varname, "b") != 0
	|| strcmp(retspec->type.func.arglist[2].varname, "c") != 0
	|| retspec->type.func.ret->btype != SpecTypeInt) {
		logd("test failed at #02.\n");
		UNIT_TEST_FAIL;
	}

	/******testcase 3 int main(){int x,**a[12][34][56];}******/
	yy_scan_string("int main(){int x,**a[12][34][56];}");
	yyparse();
	retspec = register_type_complex_var(astroot->child->child->child->sibling->sibling->child->sibling->child->child->child->sibling->child->sibling->sibling->child->child);
	if(retspec->btype != SpecTypeArray
	|| retspec->plevel != 2
	|| retspec->type.array.size != 3
	|| retspec->type.array.dim[0] != 56
	|| retspec->type.array.dim[1] != 34
	|| retspec->type.array.dim[2] != 12
	|| retspec->type.array.spec->btype != SpecTypeInt) {
		logd("test failed at #03.\n");
		UNIT_TEST_FAIL;
	}

	/****************testcase 4(hard to check)****************/
	yy_scan_string("struct A {int a, b, c;struct B {int x, y;float z;} d, e, f;struct C {float _89;struct nested_in_C {int na, nb;float nc;} p_p;} xx;float oatt;} ;int *****array[123][12][4564][678];int init = 0;int main(struct A x) {int a[10][123][345][657];return 0;}");
	yyparse();
	retspec = register_type_struct(astroot->child->child->child);
	//print_spec(retspec);//checked by human

	UNIT_TEST_END;
	
#endif
	return;
}