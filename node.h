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
	/*number*/
	SpecTypeString = 10, //char *s="hello";equivalent to `char *`
	//the above must be registered firstly
	SpecTypeVoid,
	SpecTypePointer,//pointer type
	SpecTypeArray,
	SpecTypeComplex,//pointer array
	SpecTypeFunc,
	SpecTypeStruct,
	SpecTypeUnion,
	SpecTypeEnd,
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
	CombineTypeDouble = 128,
	CombineInvalid = 256,
};

enum {
	PrConstId,
	PrVariableId,
	PrConstValue,
	PrRunTimeConst,
	PrHalfConst,
};

enum {
	SpecLvalue = 0,
	SpecRvalue = 1,
};

typedef struct VarInfo {
	//for variable
	int bt;//0 for code area
				  //1 for global data
				  //2 for local stack
				  //3 for register
				  //4 for const
	uintptr_t ba;//base addr
	size_t vs;//variable size, structure need size
	uint32_t ref;
	off_t off;
	int qulfr;
} VarInfo;

typedef struct InitorMemoryMap {
	//FIXME
	void *buf;
	size_t bufsize;
	off_t *offarr;
	size_t *sizearr;
	size_t nr_var;
} InitorMemoryMap;

struct Spec;

typedef struct ExpConstPart{
	//warning:string is not constant
	//        string == char *[no const]
	union {
		int t; //sometimes store extra information of tree node
				//for example, `Const` or `Extern` or ... in `Qulfr` node 
				//if node->dt != NULL, t donates the const attribute
		struct Spec *type;
		InitorMemoryMap *mm;
	};

	union {
		int8_t _8;int16_t _16;int32_t _32;int64_t _64;
		uint8_t _u8;uint16_t _u16;uint32_t _u32;uint64_t _u64;
		float _f32; double _f64;
		int i;float f;double llf;void *p;
		char* str;// the address of string or id
		char **pstr;
		int ex;
	};
} ExpConstPart;

typedef struct Spec {
	int bt;
	int w;
	char *format_string;//format_string
	union {
		//ex. int a[10][20];
		struct {
			struct Spec *dt;//dst type, such as `struct A`
			size_t *dim;//dimension array:a[2][3][4]=>[2,3,4]
			size_t size;//length of(dim)
		} arr;//complex variable, array or pointer or both

		//ex. int ***p = NULL; high level pointer is meaningless
		struct {
			struct Spec *dt;//actual spec,such as `struct A`
			int pl;//pointer level
		} ptr;//complex variable, array or pointer or both

		struct {
			struct Spec *ret;
			struct Spec **argv;
			int ellipsis;//int func(int a, int b, ...)
			size_t argc;
		} func;//func type

		struct {
			char *sn;//struct name
			struct {
				char *id;//member name
				off_t off;//offset in bits
				size_t size;//bits
				struct Spec *dt;
			} *argv;
			size_t size;
		} struc;//for structure

		//ex. int **a[10][20]; type(a) is complex
		struct {
			struct Spec *dt;//actual spec,such as `struct A`
			size_t *dim;//dimension array:a[2][3][4]=>[2,3,4]
			size_t size;//length of(dim)
			int pl;//pointer level
					   //must not be zero(not pointer)
		} comp;//complex variable, array or pointer or both
	};
} Spec;

typedef struct Node {
	struct Node *sibling;
	struct Node *child;
	struct Node *parent;//for reverse-travel

	/* semantic structure */
	int token;//syntax value like `Program` `TYPE` `INT`
	int reduce_rule;//semantic reduce rule like `AST_Exp_is_ID`

	//dt + vi for id
	//dt + vi + cv for exp
	//for ID node, dt donates id's type, if id is constant, cv.t will indicate this
	//for Exp node, the same as above
	int lrv;//temporary strategy, left or right value
	Spec *dt;//data type, dt->bt reveal which value will be use in cv
	VarInfo *vi;//for register allocation
	ExpConstPart cv;//constant value

	/* for debugging */
	int error;
	int lineno, column;
} Node;

Spec *new_spec();
char *type_format(Spec *type);
int get_type_relation(int btA, int btB);
Spec *get_spec_by_btype(uint32_t btype);
int convert_ctype2type(int ct);

typedef void (*SemanFunc)(Node *);
void syntax_analysis(Node *root);

#endif
