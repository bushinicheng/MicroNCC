#ifndef __NODE_H__
#define __NODE_H__

//basic data type
enum {
	/*number*/
	SpecTypeInt8 = 0,//also SpecTypeChar
	SpecTypeUint8 = 1,//also SpecTypeBool
	SpecTypeInt16 = 2,
	SpecTypeUint16 = 3,
	SpecTypeInt32 = 4,
	SpecTypeUint32 = 5,
	SpecTypeInt64 = 6,
	SpecTypeUint64 = 7,
	SpecTypeFloat32 = 8,
	SpecTypeFloat64 = 9,
	SpecTypeString = 10, //char *s="hello";equivalent to `char *`
	//
	SpecTypeConst,//not data type
	SpecTypeVoid,//special data type
	/*number*/
	SpecTypePointer,//pointer type
	SpecTypeArray,
	SpecTypeComplex,//pointer array
	//the above must be registered firstly
	SpecTypeFunc,
	SpecTypeStruct,
	SpecTypeUnion,
	SpecTypeQulfr,
	SpecTypeRen,
};

//unary op:! ~ & ++ -- +a -a
enum {
	CAssign = 1,//a=b
	CAddSub = 2,//a+b,a-b,a++,a--,++a,--a,a+=b,a-=b
	CMultDiv = 4,//a*b,a/b,a*=b,a/=b
	CBitop = 8,//a&b,a|b,a^b,~a,a&=b,a|=b,a^=b,a<<b,a>>b,a<<=b,a>>=b
	CRelop = 16,//a<b,a>b,a<=b,a>=b,a==b,a!=b
	CLogic = 32,//a && b, a || b, !a
	CMoreAccurate = 64,//both 1 means eq
	CLessAccurate = 128,//both 0 means unable to compare
};

enum {
	//qualifier
	QulfrTypedef = 1,
	QulfrExtern = 2,
	QulfrStatic = 4,
	QulfrAuto = 8,
	QulfrRegister = 16,
	//class storage
	QulfrConst = 32,
	QulfrVolatile = 64,
};

enum {
	CombineTypeSigned = 1,
	CombineTypeUnsigned = 2,
	CombineTypeShort = 4,
	CombineTypeChar = 8,
	CombineTypeInt = 16,
	CombineTypeLong = 32,
	CombineTypeLongLong = 64,
	CombineTypeFloat = 128,
	CombineTypeDouble = 256,
};

enum {
	SpecLvalue = 0,
	SpecRvalue = 1,
};

struct tagSpec;

typedef struct tagSinArg {
	struct tagSpec *t;//type pointer
	char *vn;//var name
} SinArg;

typedef struct tagVarAddr {
	//for variable
	int bt;//0 for code area
				  //1 for global data
				  //2 for local stack
				  //3 for register
	uintptr_t ba;//base addr
	size_t vs;//variable size, structure need size
	uint32_t ref;
	off_t off;
} VarAddr;

typedef struct tagSpecConstValue{
	//warning:string is not constant
	//        string == char *[no const]
	int st; //suptype
			//SpecTypeInt32, ...
			//SpecTypeUint32, ...
			//SpecTypeFloat32, ...
	union {
		int8_t _8;int16_t _16;int32_t _32;int64_t _64;
		uint8_t _u8;uint16_t _u16;uint32_t _u32;uint64_t _u64;
		float _f32; double _f64;
		int i;float f;double llf;void *p;
		char* st;// the address of string or id
	} sv;//supval
} SpecConstValue;

typedef struct tagSpec {
	int bt;
	int w;
	int qulfr;
	char *format_string;//format_string
	bool leftvalue;//default to be zero
			//0 for lval, 1 for rval
	bool actionlevel;//default to be zero
			//0 for global declaration, 1 for local declaration
	union {
		struct {
			struct tagSpec *dt;
		} aut;//wait for fill, auto a = 456;

		//ex. int a[10][20];
		struct {
			struct tagSpec *dt;//dst type, such as `struct A`
			size_t *dim;//dimension array:a[2][3][4]=>[2,3,4]
			size_t size;//length of(dim)
		} arr;//complex variable, array or pointer or both

		//ex. int ***p = NULL; high level pointer is meaningless
		struct {
			struct tagSpec *dt;//actual spec,such as `struct A`
			int pl;//pointer level
		} ptr;//complex variable, array or pointer or both

		struct {
			struct tagSpec *ret;
			SinArg *argv;
			size_t argc;
		} func;//func type

		struct {
			char *sn;//struct name
			struct {
				char *vn;//var name
				off_t off;//offset of current var in struct
				struct tagSpec *dt;
			} *argv;
			size_t size;
		} struc;//for structure

		//ex. int **a[10][20]; type(a) is complex
		struct {
			struct tagSpec *spec;//actual spec,such as `struct A`
			size_t *dim;//dimension array:a[2][3][4]=>[2,3,4]
			size_t size;//length of(dim)
			int pl;//pointer level
					   //must not be zero(not pointer)
		} comp;//complex variable, array or pointer or both
	};
} Spec;

typedef struct tagNode {
	struct tagNode *sibling;
	struct tagNode *child;
	struct tagNode *parent;//for reverse-travel

	/* semantic structure */
	int token;//syntax value like `Program` `TYPE` `INT`
	int reduce_rule;//semantic value like `AST_Exp_is_ID`

	/*id type*/
	Spec *dt;//data type
	VarAddr *va;
	SpecConstValue cv;//constant value

	/* for debugging */
	int error;
	int lineno, column;
} Node, *PNode;

Spec *new_spec();
Spec *copy_spec(Spec *s);
char *type_format(Spec *type);
bool compare_type(Spec *s, Spec *t);
int get_type_relation(int btA, int btB);
size_t get_size_of_btype(int btype);
Spec *get_spec_by_btype(uint32_t btype, int lr);
Spec *get_spec_of_const(Spec *const_spec);
bool type_is_compatible(Spec *typeA, Spec *typeB);
Spec *find_type_of_spec(struct tagNode *root);
Spec *find_type_of_struct_member(Spec *type, char *member, off_t *off);
Spec *register_type_function(struct tagNode *root);
Spec *register_type_struct(struct tagNode *root);
Spec *register_type_complex_var(Node *root, char **varname);
Spec *register_complex_var_with_type(Spec *type, Node *root, char **varname);

bool type_is_bit(Spec *type);
bool type_is_float(Spec *type);
bool type_is_num(Spec *type);
Spec *type_more_accurate(Spec *typeA, Spec *typeB);

typedef void (*SemanFunc)(Node *);
void syntax_analysis(Node *root);

#endif
