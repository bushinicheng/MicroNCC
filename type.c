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
		case SpecTypeInt8:     return 1;
		case SpecTypeInt32:      return 4;
		case SpecTypeUint32: return 4;
		case SpecTypeFloat32:    return 4;
		case SpecTypePointer:  return 4;
	}
	return 0;
}


/*
 * function:
 *   return a new spec pointer point to a clean spec element
 */
Spec *new_spec() {
	wt_assert(specptr < MAX_SIZE);
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
		case 'i':return get_spec_by_btype(SpecTypeInt32, SpecRvalue);
		case 'u':return get_spec_by_btype(SpecTypeUint32, SpecRvalue);
		case 'f':return get_spec_by_btype(SpecTypeFloat32, SpecRvalue);
		case 's':return get_spec_by_btype(SpecTypeString, SpecLvalue);
		case 'c':return get_spec_by_btype(SpecTypeInt8, SpecRvalue);
		default:wt_assert(0);
	}
	return NULL;
}

bool type_is_bit(Spec *type) {
	if(!type) return false;
	switch(type->btype) {
		case SpecTypeUint8:     return true;
		case SpecTypeInt8:     return true;
		case SpecTypeInt32:      return true;
		case SpecTypeUint32: return true;
	}

	if(type->btype == SpecTypeConst && type->cons.suptype == 'i') {
		return true;
	}

	return false;
}

bool type_is_float(Spec *type) {
	if(!type) return false;
	if(type->btype == SpecTypeFloat32) return true;
	if(type->btype == SpecTypeConst
	&& type->cons.suptype == 'f')
		return true;
	return false;
}

bool type_is_num(Spec *type) {
	return type_is_bit(type) || type_is_float(type);
}

bool type_is_compatible(Spec *typeA, Spec *typeB) {
	bool is_a_number = type_is_num(typeA);
	bool is_b_number = type_is_num(typeB);
	if(is_a_number && is_b_number) return true;
	return false;
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
			return get_spec_by_btype(SpecTypeFloat32, SpecRvalue);
		}else if(typeA->cons.suptype == 'i'
		      || typeB->cons.suptype == 'i') {
			return get_spec_by_btype(SpecTypeInt32, SpecRvalue);
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
 *   RESTRICTION: token = TypeSpec
 * OUT[0]:
 *   struct tagSpec *
 *   type of input node
 * function:
 *   find corresponding type of AST's `TypeSpec` node
 */
Spec *find_type_of_spec(Node *root) {
	if(!root) return NULL;
	wt_assert(root->token == TypeSpec);
	char *struct_id = NULL;
	
	if(root->token == TypeSpec) {
		switch(get_child_node_w(root, TypeSpec)->idtype->cons.suptype){
			case CHAR:
				return get_spec_by_btype(SpecTypeInt8, SpecLvalue);
			case INT:
				return get_spec_by_btype(SpecTypeInt32, SpecLvalue);
			case FLOAT:
				return get_spec_by_btype(SpecTypeFloat32, SpecLvalue);
			default:
				yyerr("error type B:type `%s` not supported!\n",\
						type_format(get_child_node_w(root, TypeSpec)->idtype));
				return NULL;
		}
	} else {//AST_TypeSpec_is_STRUCT_ID
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
		case SpecTypeUint8:
		case SpecTypeInt8:
		case SpecTypeInt32:
		case SpecTypeUint32:
		case SpecTypeFloat32:
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
	t->format_string = NULL;
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
	if(type->format_string) return type->format_string;
	switch(type->btype) {
		case SpecTypeConst: 
			if(type->cons.suptype == 's')
				type->format_string = "string";
			else
				type->format_string = "constant";
			break;
		case SpecTypeVoid:     type->format_string = "void";break;
		case SpecTypeUint8:     type->format_string = "bool";break;
		case SpecTypeInt8:     type->format_string = "char";break;
		case SpecTypeInt32:      type->format_string = "int";break;
		case SpecTypeUint32: type->format_string = "unsigned";break;
		case SpecTypeFloat32:    type->format_string = "float";break;
		case SpecTypeStruct:
			type->format_string = sformat("struct %s", type->struc.struc_name);
			break;
	}

	if(type->btype == SpecTypeFunc)	{
		char **args_str = (char **)get_memory_pointer();
		require_memory(type->func.argv * sizeof(char *));
		char *ret_str = type_format(type->func.ret);
		for(int i = 0; i < type->func.argv; i++) {
			args_str[i] = type_format(type->func.arglist[i].type);
		}
		type->format_string = sformat("%s (%s)", ret_str, strjoin(args_str, type->func.argv, ", "));
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
		type->format_string = sformat("%s %s%s", rawtype_str, star_str, arr_str);
	}

	return type->format_string;
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
			wt_assert(0);
			break;
		case SpecTypeComplex:
			if(s->comp.plevel != t->comp.plevel)
				return false;
			else if(!compare_type(s->comp.spec, t->comp.spec))
				return false;
			else if(s->comp.size != t->comp.size)
				return false;
			for(int i = 0; i < s->comp.size; i++) {
				if(s->comp.dim[i] != t->comp.dim[i])
					return false;
			}
			break;
		case SpecTypeStruct:
			if(s != t) return false;
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
 * Block:TypeSpec FuncDec CompSt
 *
 * FuncDec:ID LP RP
 *        |ID LP FuncDefArgList RP
 *
 * FuncDefArgList:FuncDefArg COMMA FuncDefArgList
 *               |FuncDefArg
 *
 * FuncDefArg:TypeSpec Decln
 *
 * TypeSpec:TypeSpec
 *          |STRUCT ID
 * */


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
	btype_register(SpecTypeInt8,     1, SpecLvalue);
	btype_register(SpecTypeInt8,     1, SpecRvalue);
	btype_register(SpecTypeUint8,    1, SpecLvalue);
	btype_register(SpecTypeUint8,    1, SpecRvalue);
	btype_register(SpecTypeInt16,    2, SpecLvalue);
	btype_register(SpecTypeInt16,    2, SpecRvalue);
	btype_register(SpecTypeUint16,   2, SpecLvalue);
	btype_register(SpecTypeUint16,   2, SpecRvalue);
	btype_register(SpecTypeInt32,    4, SpecLvalue);
	btype_register(SpecTypeInt32,    4, SpecRvalue);
	btype_register(SpecTypeUint32,   4, SpecLvalue);
	btype_register(SpecTypeUint32,   4, SpecRvalue);
	btype_register(SpecTypeInt64,    8, SpecLvalue);
	btype_register(SpecTypeInt64,    8, SpecRvalue);
	btype_register(SpecTypeUint64,   8, SpecLvalue);
	btype_register(SpecTypeUint64,   8, SpecRvalue);
	btype_register(SpecTypeFloat32,  4, SpecLvalue);
	btype_register(SpecTypeFloat32,  4, SpecRvalue);
	btype_register(SpecTypeFloat64,  8, SpecLvalue);
	btype_register(SpecTypeFloat64,  8, SpecRvalue);
	specpool[specptr].lval = SpecLvalue;
	specpool[specptr].btype = SpecTypeComplex;
	specpool[specptr].comp.spec = &specpool[2 * SpecTypeInt8];
	specpool[specptr].comp.plevel = 1;
	specpool[specptr].aslevel = 1;
	specptr ++;
	specpool[specptr].lval = SpecRvalue;
	specpool[specptr].btype = SpecTypeComplex;
	specpool[specptr].comp.spec = &specpool[2 * SpecTypeInt8];
	specpool[specptr].comp.plevel = 1;
	specpool[specptr].aslevel = 1;
	specptr ++;
}

void init_spec() {
	reset_spec_state();
}
