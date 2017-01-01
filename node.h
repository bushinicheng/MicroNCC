#ifndef __NODE_H__
#define __NODE_H__

//basic data type
enum {
	SpecTypeConst,
	SpecTypeVoid,
	SpecTypeChar,
	SpecTypeInt,
	SpecTypeUnsigned,
	SpecTypeFloat,
	//the above is no need to spec
	SpecTypeStruct,
	SpecTypeUnion,
	SpecTypeFunc,
	SpecTypeArray
};

struct tagSpec;

typedef struct tagSinArg {
	struct tagSpec *type;
	char *varname;
} SinArg;

typedef struct tagSpec {
	int btype;
	int width;
	int plevel;//default to be zero
	union {
		struct {
			struct tagSpec *ret;
			SinArg *arglist;
			size_t argv;
		} func;//func type

		struct {
			struct tagSpec *spec;//actual spec,such as `struct A`
			size_t *dim;
			size_t size;//dimension
		} array;//for array

		struct {
			char *struc_name;
			struct {
				char *var_name;
				struct tagSpec *spec;
			} *varlist;
			size_t size;
		} struc;//for structure
	} type;
} Spec;

typedef struct tagNode {
	struct tagNode *sibling;
	struct tagNode *child;
	struct tagNode *parent;//for reverse-travel

	/* semantic structure */
	int token;//syntax value like `Program` `TYPE` `INT`
	int reduce_rule;//semantic value like `AST_Exp_is_ID`

	/****************declared just for ID******************/
	/*id type*/
	Spec *idtype;//const or not const all don't have idval
	//for variable
	int base_type;//0 for code area
				  //1 for global data
				  //2 for local stack
	uintptr_t base_addr;
	size_t var_size;//structure need size
	/****************declared just for ID******************/

	//for constant, such as "hello", 12, 5.1
	int suptype;//such as INT for TYPE or float for NUM
	union {
		int i;float f;double llf;void *p;
		char* st;//may be the address of string or id
		uintptr_t da;//may be structure or function
	} supval;

	/* for debugging */
	int error;
	int lineno, column;
} Node, *PNode;

Spec *find_type_of_spec(struct tagNode *root);
Spec *register_type_function(struct tagNode *root);
Spec *register_type_complex_var(struct tagNode *root);
Spec *register_type_struct(struct tagNode *root);

#endif
