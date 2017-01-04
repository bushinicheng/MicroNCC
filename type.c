#include "common.h"
#include <memory.h>

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static uintptr_t specptr = 0;
Spec specpool[MAX_SIZE];

void print_spec(Spec *type);
Spec *register_type_function(Node *root);
Spec *register_type_array(Node *root);
Spec *register_type_struct(Node *root);
Spec *register_type_complex_var(Node *root, char **varname);
Spec *register_complex_var_with_type(Spec *type, Node *root, char **varname);


/* function:
 *   return the basic size of btype
 */
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


/*
 * function:
 *   return a new spec pointer point to a clean spec element
 */
Spec *new_spec() {
	assert(specptr < MAX_SIZE);
	Spec *spec = &specpool[specptr ++];
	memset(spec, 0, sizeof(Spec));
	return spec;
}

/*
 * num -> rval
 * string -> lval
 */
Spec *get_spec_of_const(Spec *const_spec) {
	if(const_spec->btype != SpecTypeConst)
		return NULL;
	switch(const_spec->cons.suptype) {
		case 'i':return get_spec_by_btype(SpecTypeInt, SpecRvalue);
		case 'u':return get_spec_by_btype(SpecTypeUnsigned, SpecRvalue);
		case 'f':return get_spec_by_btype(SpecTypeFloat, SpecRvalue);
		case 's':return get_spec_by_btype(SpecTypeString, SpecLvalue);
		case 'c':return get_spec_by_btype(SpecTypeChar, SpecRvalue);
		default:assert(0);
	}
	return NULL;
}

bool type_is_bit(Spec *type) {
	if(!type) return false;
	switch(type->btype) {
		case SpecTypeBool:     return true;
		case SpecTypeChar:     return true;
		case SpecTypeInt:      return true;
		case SpecTypeUnsigned: return true;
	}

	if(type->btype == SpecTypeConst && type->cons.suptype == 'i') {
		return true;
	}

	return false;
}

bool type_is_float(Spec *type) {
	if(!type) return false;
	if(type->btype == SpecTypeFloat) return true;
	if(type->btype == SpecTypeConst
	&& type->cons.suptype == 'f')
		return true;
	return false;
}

bool type_is_num(Spec *type) {
	return type_is_bit(type) || type_is_float(type);
}

/* assume operand A and B, A op B ==> rval
 */
Spec *type_more_accurate(Spec *typeA, Spec *typeB) {
	if(!type_is_num(typeA) || !type_is_num(typeB))
		return NULL;
	if(typeA->btype == SpecTypeConst
	|| typeB->btype == SpecTypeConst) {
		if(typeA->cons.suptype == 'f'
		|| typeB->cons.suptype == 'f') {
			return get_spec_by_btype(SpecTypeFloat, SpecRvalue);
		}else if(typeA->cons.suptype == 'i'
		      || typeB->cons.suptype == 'i') {
			return get_spec_by_btype(SpecTypeInt, SpecRvalue);
		}
	}else{
		if(typeA->btype > typeB->btype)
			return get_spec_by_btype(typeA->btype, SpecRvalue);
		else
			return get_spec_by_btype(typeB->btype, SpecRvalue);
	}
	/**/
	logw("maybe ... :(");
	return NULL;
}

/* IN[0]: struct tagSpec *
 *   struct type
 *   **no restriction
 * IN[1]: char *
 *   member variable's id
 * OUT[0]:
 *   type of member variable
 * function:
 *   return NULL if fail
 */
Spec *find_type_of_struct_member(Spec *type, char *member) {
	if(!type || type->btype != SpecTypeStruct) return NULL;
	
	for(int i = 0; i < type->struc.size; i++) {
		if(strcmp(type->struc.varlist[i].varname, member) == 0) {
			return type->struc.varlist[i].spec;
		}
	}

	return NULL;
}



/* IN[0]: struct tagNode *
 *   AST node
 *   RESTRICTION: token = Specifier
 * OUT[0]:
 *   struct tagSpec *
 *   type of input node
 * function:
 *   find corresponding type of AST's `Specifier` node
 */
Spec *find_type_of_spec(Node *root) {
	if(!root) return NULL;
	assert(root->token == Specifier);
	char *struct_id = NULL;
	
	if(root->reduce_rule == AST_Specifier_is_TYPE) {
		switch(get_child_node_w(root, TYPE)->idtype->cons.suptype) {
			case CHAR:
				return get_spec_by_btype(SpecTypeChar, SpecLvalue);
			case INT:
				return get_spec_by_btype(SpecTypeInt, SpecLvalue);
			case FLOAT:
				return get_spec_by_btype(SpecTypeFloat, SpecLvalue);
			default:
				yyerr("error type B:type `%c` not supported!\n",\
						type_format(root->child->idtype));
				return NULL;
		}
	} else {//AST_Specifier_is_STRUCT_ID
		struct_id = get_child_node_w(root, ID)->idtype->cons.supval.st;
		for(int i = specptr - 1; i; i--) {
			if(specpool[i].btype == SpecTypeStruct && specpool[i].aslevel == 0) {
				if(strcmp(specpool[i].struc.struc_name, struct_id) == 0) {
					return &specpool[i];
				}
			}
		}
	}

	//type not found!
	//assume find operation is meaningful :)
	yyerr("error type B: type `struct %s` not declared!\n", struct_id);
	return NULL;
}


/* function:
 *   get spec pointer by btype
 */
Spec *get_spec_by_btype(int btype, int lr) {
	switch(btype) {
		case SpecTypeConst:
		case SpecTypeVoid:
		case SpecTypeBool:
		case SpecTypeChar:
		case SpecTypeInt:
		case SpecTypeUnsigned:
		case SpecTypeFloat:
		case SpecTypeString:
			return &specpool[2 * btype + lr];
	}
	logw("check here. :(\n");
	return NULL;
}


/* function:
 *   return a copy of input type
 */
Spec *copy_spec(Spec *s) {
	Spec *t = new_spec();
	memcpy(t, s, sizeof(Spec));
	return t;
}


/* IN[0]: struct tagSpec *
 *   type pointer
 * OUT[0]:char *
 *   string pointer
 * function:
 *   format given type to string
 */
char *type_format(Spec *type) {
	if(!type) return NULL;
	switch(type->btype) {
		case SpecTypeConst: 
			if(type->cons.suptype == 's')
				return "string";
			else
				return "constant";
		case SpecTypeVoid:     return "void";
		case SpecTypeBool:     return "bool";
		case SpecTypeChar:     return "char";
		case SpecTypeInt:      return "int";
		case SpecTypeUnsigned: return "unsigned";
		case SpecTypeFloat:    return "float";
		case SpecTypeStruct:   return sformat("struct %s", type->struc.struc_name);
	}

	if(type->btype == SpecTypeFunc)	{
		char **args_str = (char **)get_memory_pointer();
		require_memory(type->func.argv * sizeof(char *));
		char *ret_str = type_format(type->func.ret);
		for(int i = 0; i < type->func.argv; i++) {
			args_str[i] = type_format(type->func.arglist[i].type);
		}
		return sformat("%s (%s)", ret_str, strjoin(args_str, type->func.argv, ", "));
	} else if(type->btype == SpecTypeComplex) {
		char *rawtype_str = type_format(type->comp.spec);
		char *star_str = strmul("*", type->comp.plevel);

		int arr_size = 0;
		char *arr_str = (char *)get_memory_pointer();
		char *p = arr_str;
		for(int i = type->comp.size - 1; i >= 0; i--) {
			arr_size += sprintf(&p[arr_size], "[%lu]", type->comp.dim[i]);
		}
		require_memory(arr_size + 1);
		return sformat("%s %s%s", rawtype_str, star_str, arr_str);
	}

	return NULL;
}

/* IN[0]: struct tagSpec *
 *   type pointer
 * IN[1]: struct tagSpec *
 *   type pointer
 * out[0]:bool
 *   true if two type are equivalent, else false
 *
 * function:
 *   judge if equivalent
 */
bool compare_type(Spec *s, Spec *t) {
	if(s == t) return true;
	if(!s) return false;
	if(!t) return false;
	if(s->btype != t->btype) return false;
	if(s->width != t->width) return false;

	switch(s->btype) {
		case SpecTypeFunc:
			//TODO:compare type function, IMPLEMENT ME
			assert(0);
			break;
		case SpecTypeComplex:
			if(s->comp.plevel != t->comp.plevel)
				return false;
			else if(s->comp.spec != t->comp.spec)
				return false;
			else if(s->comp.size != t->comp.size)
				return false;
			for(int i = 0; i < s->comp.size; i++) {
				if(s->comp.dim[i] != t->comp.dim[i])
					return false;
			}
			break;
		case SpecTypeStruct:
			//TODO:compare type struct, IMPLEMENT ME
			assert(0);
			break;
	}
	return true;
}


/* IN[0]:struct tagNode *
 *   a pointer point to ast node
 *   RESTRICTION: root->token == FuncDec
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
 * FuncDefArg:Specifier VarDec
 *
 * Specifier:TYPE
 *          |STRUCT ID
 * */
Spec *register_type_function(Node *root) {
	if(!root) return NULL;
	assert(root->token == FuncDec);
	Spec *newspec = new_spec();
	char *funcname = get_child_node_w(root, ID)->idtype->cons.supval.st;
	newspec->btype = SpecTypeFunc;
	newspec->width = 0;
	newspec->func.ret = find_type_of_spec(get_sibling_node_w(root, Specifier));

	if(root->reduce_rule == AST_FuncDec_is_ID_LP_RP)
		return newspec;

	//count up variable firstly
	size_t argv = 0;
	SinArg *args = (SinArg*)get_memory_pointer();
	Node *deflist = get_child_node_w(root, FuncDefArgList);
	while(1) {
		argv ++;
		deflist = get_child_node(deflist, FuncDefArgList);
		if(!deflist) break;
	}
	require_memory(sizeof(SinArg) * argv);

	//register FuncDefArg recursively
	size_t parg = 0;
	deflist = get_child_node_w(root, FuncDefArgList);
	while(1) {
		/* FuncDefArgList => FuncDefArg COMMA FuncDefArgList
		 * deflist as entry => FuncDefArg
		 * register FuncDef by `FuncDefArg:Specifier VarDec` 
		 */
		Spec *rawtype = find_type_of_spec(deflist->child->child);
		args[parg].type = register_complex_var_with_type(rawtype,\
			deflist->child->child->sibling, &(args[parg].varname));
		parg ++;

		deflist = get_child_node(deflist, FuncDefArgList);
		if(!deflist) break;
	}

	newspec->func.argv = parg;
	newspec->func.arglist = args;

	//final check
	assert(argv == parg);

	//check duplication
	check_dupset(sformat("line %d: error: redefinition of parameter '%%s' of '%s'.\n", root->lineno, funcname), 
			args, argv, sizeof(SinArg),
			(uintptr_t)(&(args[0].varname)) - (uintptr_t)(&args[0])
		);
	
	return newspec;
}



/* IN[0]: struct tagSpec *
 *   the type pointer of target variable
 *
 * IN[1]: struct tagNode *
 *   a pointer point to ast node
 *   RESTRICTION: root->token == VarDec
 *
 * IN[2]: char **varname
 *   varname[0] will be assigned value of id's pointer
 *
 * OUT[0]:struct tagSpec *
 *   final type of variable, array or pointer or both
 *
 * function:
 *   register the type of target array or pointer variable
 *
 *
 * root=>VarDec
 *       and VarDec !=> ID
 *
 * VarDec:ID
 *       |MULT VarDec
 *       |VarDec LB NUM RB
 */
Spec *register_complex_var_with_type(Spec *type, Node *root, char **varname) {
	if(!root || !type) return NULL;
	assert(root->token == VarDec);
	Spec *newspec = new_spec();
	newspec->comp.plevel = 0;
	newspec->btype = SpecTypeComplex;
	newspec->width = 1;
	Node *vardef = root;
	newspec->comp.spec = type;
	
	//process star corresponding to `POINTER`
	while(root->reduce_rule == AST_VarDec_is_MULT_VarDec) {
		newspec->comp.plevel ++;
		root = get_child_node_w(root, VarDec);
	}

	//process dim corresponding to `Array`
	newspec->comp.size = 0;
	newspec->comp.dim = (size_t*)get_memory_pointer();
	while(root->reduce_rule == AST_VarDec_is_VarDec_LB_NUM_RB) {
		int cur_dim = get_child_node_w(root, NUM)->idtype->cons.supval.i;
		newspec->comp.dim[newspec->comp.size] = cur_dim;
		newspec->width = newspec->width * cur_dim;
		newspec->comp.size ++;
		root = get_child_node_w(root, VarDec);
	}
	require_memory(sizeof(size_t) * newspec->comp.size);

	//get here means `root` point to node with reduce rule:
	//   VarDec => ID
	if(varname != NULL) {
		varname[0] = get_child_node_w(root, ID)->idtype->cons.supval.st;
	}

	if(newspec->comp.plevel == 0) {//pure array 
		if(newspec->comp.size == 0) {//pure variable
			specptr --;
			return type;
		}
		newspec->width = newspec->comp.spec->width * newspec->width;
	}else{//pointer array
		newspec->width = newspec->width * get_size_of_btype(SpecTypePointer);
	}

	return newspec;
}


/* IN[0]:struct tagNode *
 *   a pointer point to ast node
 *   RESTRICTION: root->token == VarDec
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
Spec *register_type_complex_var(Node *root, char **varname) {
	if(!root) return NULL;
	assert(root->token == VarDec);
	Spec *newspec = new_spec();
	newspec->btype = SpecTypeArray;
	newspec->width = 1;
	Node *vardef = root;

	//search upwards for the VarDef node to get type
	while(vardef->reduce_rule != AST_VarDef_is_Specifier_DecList_SEMI) {
		vardef = vardef->parent;
	}
	Spec *rawtype = find_type_of_spec(vardef->child);
	Spec *newtype = register_complex_var_with_type(rawtype, root, varname);

	if(newtype != rawtype) {
		newspec->comp.spec = newtype;
	} else {
		specptr --;//pure variable, not array or pointer
	}

	return newtype;
}



/* IN[0]:struct tagNode *
 *   a pointer point to ast node
 *   RESTRICTION: root->token == StructDec
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
 * IdList:VarDec COMMA IdList
 *       |VarDec
 */
Spec *register_type_struct(Node *root) {
	if(!root) return NULL;
	assert(root->token == StructDec);
	int nr_var = 0, struct_width = 0;
	char *struct_id = get_child_node_w(root, ID)->idtype->cons.supval.st;
	Spec *newspec = new_spec();
	newspec->btype = SpecTypeStruct;
	newspec->width = 0;//just init
	newspec->struc.struc_name = struct_id;

	Node *dvl = get_child_node_w(root, StructDecVarList);
	//first traverse to count up number of variable
	while(1) {
		Node *idlist = get_child_node_w(dvl->child, IdList);
		while(1) {
			nr_var ++;
			idlist = get_child_node(idlist, IdList);
			if(!idlist) break;
		}
		dvl = get_child_node(dvl, StructDecVarList);
		if(!dvl) break;
	}
	//alloc memory for struc.varlist
	newspec->struc.varlist = get_memory_pointer();
	require_memory(sizeof(newspec->struc.varlist[0]) * nr_var);

	//second traverse to register type of variable
	dvl = get_child_node_w(root, StructDecVarList);
	while(1) {
		Spec *curtype = NULL;
		Node *type_node = dvl->child->child;
		Node *idlist = get_child_node_w(dvl->child, IdList);
		if(type_node->token == Specifier)
			curtype = find_type_of_spec(type_node);
		else {
			curtype = register_type_struct(type_node);
			curtype->aslevel = newspec->aslevel + 1;
		}

		while(1) {
			//TODO:round the size of width to 4
			Spec *newtype = NULL;
			char **specvarname = &(newspec->struc.varlist[newspec->struc.size].varname);
			newtype = register_complex_var_with_type(curtype, idlist->child, specvarname);
			newspec->struc.varlist[newspec->struc.size].spec = newtype;
			newspec->struc.varlist[newspec->struc.size].offset = newspec->width;
			newspec->struc.size ++;
			newspec->width += newtype->width;

			idlist = get_child_node(idlist, IdList);
			if(!idlist) break;
		}
		dvl = get_child_node(dvl, StructDecVarList);
		if(!dvl) break;
	}

	//check duplication
	check_dupset(sformat("line %d: error: duplicate member '%%s' in struct '%s'.\n", root->lineno, struct_id), 
			newspec->struc.varlist,
			newspec->struc.size,
			sizeof(newspec->struc.varlist[0]),
			0
		);

	/*final check*/
	assert(newspec->struc.size == nr_var);
	return newspec;
}



/* IN[0]:struct tagSpec *
 *   the type pointer to specpool
 * function:
 *   dumps the spec structure
 *   for debugging
 */
void print_spec(Spec *type) {
	if(type == NULL) return;
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
		printf("struct %s:%d {\n", type->struc.struc_name, type->aslevel);
		Spec *old_spec = type->struc.varlist[0].spec;
		for(int j = 0; j < indent + 2; j++)
			printf(" ");
		indent += 2;
		print_spec(type->struc.varlist[0].spec);
		indent -= 2;
		printf("%s(%d)", type->struc.varlist[0].varname, type->struc.varlist[0].offset);
		for(i = 1; i < type->struc.size; i++) {
			if(old_spec != type->struc.varlist[i].spec) {
				printf(";\n");
				for(int j = 0; j < indent + 2; j++)
					printf(" ");
				indent += 2;
				print_spec(type->struc.varlist[i].spec);
				indent -= 2;
				printf("%s(%d)", type->struc.varlist[i].varname, type->struc.varlist[i].offset);
			}
			else
				printf(", %s(%d)", type->struc.varlist[i].varname, type->struc.varlist[i].offset);
			old_spec = type->struc.varlist[i].spec;
		}

		printf(";\n");
		for(int j = 0; j < indent; j++)
			printf(" ");
		if(indent == 0)
			printf("};\n");
		else
			printf("} ");
	}else if(type->btype == SpecTypeFunc) {
		print_spec(type->func.ret);
		printf("function(");
		for(int i = 0; i < (int)(type->func.argv); i++) {
			print_spec(type->func.arglist[i].type);
			if(i != type->func.argv - 1)
				printf("%s, ", type->func.arglist[i].varname);
			else
				printf("%s", type->func.arglist[i].varname);
		}
		printf(");\n");
	}else if(type->btype == SpecTypeArray) {
		print_spec(type->comp.spec);
		for(int i = 0; i < type->comp.plevel; i++)
			printf("*");
		for(int i = type->comp.size - 1; i >= 0; i--) {
			printf("[%lu]", type->comp.dim[i]);
		}
	}
}

void reset_spec_state() {
#define btype_register(b, w, l) do {\
	specpool[specptr].btype = b;\
	specpool[specptr].width = w;\
	specpool[specptr].lval  = l;\
	specptr ++;\
} while(0)

	specptr = 0;
	btype_register(SpecTypeConst,    0, SpecLvalue);
	btype_register(SpecTypeConst,    0, SpecRvalue);
	btype_register(SpecTypeVoid,     4, SpecLvalue);
	btype_register(SpecTypeVoid,     4, SpecRvalue);
	btype_register(SpecTypeBool,     1, SpecLvalue);
	btype_register(SpecTypeBool,     1, SpecRvalue);
	btype_register(SpecTypeChar,     1, SpecLvalue);
	btype_register(SpecTypeChar,     1, SpecRvalue);
	btype_register(SpecTypeInt,      4, SpecLvalue);
	btype_register(SpecTypeInt,      4, SpecRvalue);
	btype_register(SpecTypeUnsigned, 4, SpecLvalue);
	btype_register(SpecTypeUnsigned, 4, SpecRvalue);
	btype_register(SpecTypeFloat,    4, SpecLvalue);
	btype_register(SpecTypeFloat,    4, SpecRvalue);
	specpool[specptr].lval = SpecLvalue;
	specpool[specptr].btype = SpecTypeComplex;
	specpool[specptr].comp.spec = &specpool[2 * SpecTypeChar + 1];
	specpool[specptr].comp.plevel = 1;
	specpool[specptr].aslevel = 1;
	specptr ++;
	specpool[specptr].lval = SpecRvalue;
	specpool[specptr].btype = SpecTypeComplex;
	specpool[specptr].comp.spec = &specpool[2 * SpecTypeChar + 1];
	specpool[specptr].comp.plevel = 1;
	specpool[specptr].aslevel = 1;
	specptr ++;
}

void init_spec() {

#undef __DEBUG__
#warning "don't forget it!"
#ifdef __DEBUG__

	UNIT_TEST_START;
	/*unit test start*/
	uintptr_t utptr = 0;
	Node utpool[1024];
	Spec *retspec;
	void *yybuf;
	extern Node *astroot;
	void *yy_scan_string(char *);
	void yy_delete_buffer(void *);

	/***********testcase 1 int func()*************/
	reset_spec_state();
	yybuf = yy_scan_string("int func(){return 0;}");
	yyparse();
	yy_delete_buffer(yybuf);
	retspec = register_type_function(find_child_node(astroot, FuncDec));
	UNIT_TEST_STR_EQUAL(type_format(retspec), "int ()");
	UNIT_TEST_EQUAL(retspec->func.argv, 0);
	UNIT_TEST_EQUAL(retspec->func.arglist, NULL);
	UNIT_TEST_EQUAL(retspec->func.ret->btype, SpecTypeInt);


	/********testcase 2 int func(int a, char b, int c)********/
	reset_spec_state();
	yybuf = yy_scan_string("int func(int a, char b, int c){return 0;}");
	yyparse();
	yy_delete_buffer(yybuf);
	retspec = register_type_function(find_child_node(astroot, FuncDec));
	UNIT_TEST_STR_EQUAL(type_format(retspec), "int (int, char, int)");
	UNIT_TEST_EQUAL(retspec->func.argv, 3);
	UNIT_TEST_EQUAL(retspec->func.arglist[0].type->btype, SpecTypeInt);
	UNIT_TEST_EQUAL(retspec->func.arglist[1].type->btype, SpecTypeChar);
	UNIT_TEST_EQUAL(retspec->func.arglist[2].type->btype, SpecTypeInt);
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[0].varname, "a");
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[1].varname, "b");
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[2].varname, "c");
	UNIT_TEST_EQUAL(retspec->func.ret->btype, SpecTypeInt);


	/******testcase 3 int main(){int x,**a[12][34][56];}******/
	reset_spec_state();
	yybuf = yy_scan_string("int **a[12][34][56];");
	yyparse();
	yy_delete_buffer(yybuf);
	retspec = register_type_complex_var(find_child_node(astroot, VarDec), NULL);
	UNIT_TEST_STR_EQUAL(type_format(retspec), "int **[12][34][56]");
	UNIT_TEST_EQUAL(retspec->btype, SpecTypeComplex);
	UNIT_TEST_EQUAL(retspec->comp.plevel, 2);
	UNIT_TEST_EQUAL(retspec->comp.size, 3);
	UNIT_TEST_EQUAL(retspec->comp.dim[0], 56);
	UNIT_TEST_EQUAL(retspec->comp.dim[1], 34);
	UNIT_TEST_EQUAL(retspec->comp.dim[2], 12);
	UNIT_TEST_EQUAL(retspec->comp.spec->btype, SpecTypeInt);

	/******testcase 4 duplicate parameter******/
	/*
	reset_spec_state();
	yybuf = yy_scan_string("int main(int a, int a, int a){return 0;}");
	yyparse();
	yy_delete_buffer(yybuf);
	print_ast(astroot);
	retspec = register_type_function(find_child_node(astroot, FuncDec));
	*/

	/******testcase 4 duplicate member******/
	/*
	reset_spec_state();
	yybuf = yy_scan_string("struct A{int a;int a;int b;int a;};int main(){return 0;}");
	yyparse();
	yy_delete_buffer(yybuf);
	retspec = register_type_struct(find_child_node(astroot, StructDec));
	*/

	/********testcase 5 struct ID as spec**********/
	reset_spec_state();
	yybuf = yy_scan_string("struct A{int a;};int main(struct A *a[45][78], struct A b){return 0;}");
	yyparse();
	yy_delete_buffer(yybuf);
	register_type_struct(find_child_node(astroot, StructDec));
	retspec = register_type_function(find_child_node(astroot, FuncDec));
	UNIT_TEST_STR_EQUAL(type_format(retspec), "int (struct A *[45][78], struct A)");
	UNIT_TEST_EQUAL(retspec->func.argv, 2);
	UNIT_TEST_EQUAL(retspec->func.ret->btype, SpecTypeInt);
	UNIT_TEST_EQUAL(retspec->func.arglist[0].type->btype, SpecTypeComplex);
	UNIT_TEST_EQUAL(retspec->func.arglist[0].type->comp.plevel, 1);
	UNIT_TEST_EQUAL(retspec->func.arglist[0].type->width, (get_size_of_btype(SpecTypePointer) * 45 * 78));
	UNIT_TEST_EQUAL(retspec->func.arglist[1].type->btype, SpecTypeStruct);
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[1].type->struc.struc_name, "A");
	UNIT_TEST_EQUAL(retspec->func.arglist[1].type->struc.size, 1);
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[1].type->struc.varlist[0].varname, "a");
	UNIT_TEST_EQUAL(retspec->func.arglist[1].type->struc.varlist[0].offset, 0);
	UNIT_TEST_EQUAL(retspec->func.arglist[1].type->struc.varlist[0].spec->btype, SpecTypeInt);
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[0].varname, "a");
	UNIT_TEST_STR_EQUAL(retspec->func.arglist[1].varname, "b");
	UNIT_TEST_EQUAL(retspec->func.ret->btype, SpecTypeInt);


	/****************testcase ?(hard to check)****************/
	reset_spec_state();
	yybuf = yy_scan_string("struct A {int a, *b, c[3];struct B {int **x[3][4], y;float z;} d, e, f;struct C {float _89;struct nested_in_C {int na, nb;float nc;} p_p;} xx;float oatt;} ;int *****array[123][12][4564][678];int init = 0;int main(struct A x) {int a[10][123][345][657];return 0;}");
	yyparse();
	yy_delete_buffer(yybuf);
	retspec = register_type_struct(find_child_node(astroot, StructDec));
	//print_ast(astroot);
	//print_spec(retspec);//checked by human

	UNIT_TEST_END;


	STATE_TEST_START;
	reset_spec_state();
	for(int i = 0; i < specptr - 2; i++) {
		STATE_TEST_EQUAL(specpool[i].btype, i/2);
		STATE_TEST_EQUAL(specpool[i].lval, i%2);
	}
	STATE_TEST_EQUAL(specpool[2*SpecTypeString].btype, SpecTypeComplex);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString].lval, SpecLvalue);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString].aslevel, 1);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString].comp.plevel, 1);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString].comp.spec, &specpool[2 * SpecTypeChar + 1]);

	STATE_TEST_EQUAL(specpool[2*SpecTypeString+1].btype, SpecTypeComplex);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString+1].lval, SpecRvalue);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString+1].aslevel, 1);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString+1].comp.plevel, 1);
	STATE_TEST_EQUAL(specpool[2*SpecTypeString+1].comp.spec, &specpool[2 * SpecTypeChar + 1]);
	STATE_TEST_END;
#else
	reset_spec_state();
#endif
	return;
}
