#ifndef __NODE_H__
#define __NODE_H__

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
	SpecTypeFunc,
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

typedef struct tagSpec {
	bool lval;//default to be zero
			//0 for lval, 1 for rval
	bool aslevel;//default to be zero
			//0 for global declaration, 1 for local declaration
	int btype;
	int width;
	char *format_string;
	union {
		struct {
			struct tagSpec *ret;
			SinArg *arglist;
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
			union {
				int i;float f;double llf;void *p;
				char* st;// the address of string or id
				uintptr_t da;//dest addr of structure or function
			} supval;
		} cons; //constant value
	};
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
	Spec *idtype;//specify the type of identifier
	//for variable
	int base_type;//0 for code area
				  //1 for global data
				  //2 for local stack
				  //3 for register
	uintptr_t base_addr;
	size_t var_size;//structure need size
	/****************declared just for ID******************/

	/* for debugging */
	int error;
	int lineno, column;
} Node, *PNode;

Spec *new_spec();
Spec *copy_spec(Spec *s);
char *type_format(Spec *type);
bool compare_type(Spec *s, Spec *t);
size_t get_size_of_btype(int btype);
Spec *get_spec_by_btype(int btype, int lr);
Spec *get_spec_of_const(Spec *const_spec);
bool type_is_compatible(Spec *typeA, Spec *typeB);
Spec *find_type_of_spec(struct tagNode *root);
Spec *find_type_of_struct_member(Spec *type, char *member);
Spec *register_type_function(struct tagNode *root);
Spec *register_type_struct(struct tagNode *root);
Spec *register_type_complex_var(Node *root, char **varname);
Spec *register_complex_var_with_type(Spec *type, Node *root, char **varname);

bool type_is_bit(Spec *type);
bool type_is_float(Spec *type);
bool type_is_num(Spec *type);
Spec *type_more_accurate(Spec *typeA, Spec *typeB);


#endif
