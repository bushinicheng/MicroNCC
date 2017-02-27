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
	SpecTypeVoid = 11,
	/*-------type for semantic errors-------*/
	SpecTypeBad = 12,//fail to deduce type
	SpecTypeUnknown = 13,//declarator
	SpecBTSeparator,
	//the above must be registered firstly
	SpecTypePointer,//pointer type
	SpecTypeArray,
	SpecTypeComplex,//pointer array
	SpecTypeFunction,
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

typedef struct vi_t {
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
} vi_t;

typedef struct imm_t {
	//FIXME
	void *buf;
	size_t bufsize;
	off_t *offarr;
	size_t *sizearr;
	size_t nr_var;
} imm_t;

typedef struct exp_const_part_t{
	//FIXME
	/* note: some collision in AST node
	 *    Enumor->_32 and Enumor->t
	 *    TypeSpec->t(combine type)
	 *    DeclnSpec->t(combine type), DeclnSpec->ex(qulfr)
	 *    TypeQulfr->ex(qulfr)
	 *
	 *    StarList->t(pointer level), StarList->ex(qulfr)
	 *    TypeQulfrList->ex(qulfr)
	 *    TypeQulfr->ex(qulfr)
	 *
	 *    Declr->ex(qulfr), Declr->id
	 *    DirectDeclr->ex(qulfr), DirectDeclr->id
	 *
	 *    IdList->cnt, IdList->pid
	 *    ParaList->cnt, ParaList->pid
	 *    ParaTypeList->pid
	 *
	 *    ParaDecln->id
	 *
	 *    CompDecln->cnt
	 *    CompDeclr->id, CompDeclr->cnt
	 *
	 *    ID->id
	 *    for `Exp` node, use of member variable can be identified
	 *      by dt.
	 *    Exp->t(const or not), Exp->_32(value), Exp->str
	 */
	union {
		int t; //sometimes store extra information of tree node
		char *id;
		char *str;
		char **pid;
		struct type_t *type;
		imm_t *mm;
	};

	union {
		int8_t _8;int16_t _16;int32_t _32;int64_t _64;
		uint8_t _u8;uint16_t _u16;uint32_t _u32;uint64_t _u64;
		float _f32; double _f64;
		int i;float f;double llf;
		/*---------------------------------------------------*/
		int ex;
		int cnt;
		off_t off;
	};
} exp_const_part_t;

typedef struct type_t {
	int bt;
	int w;
	char *format_string;//format_string
	union {
		//ex. int **a[10][20]; type(a) is complex
		struct {
			struct type_t *dt;//actual spec,such as `struct A`
			size_t *dim;//dimension array:a[2][3][4]=>[2,3,4]
			size_t size;//length of(dim)
			           //works if bt == SpecTypeArray
					   //  or bt == SpecTypeComp
			int pl;//pointer level, works if bt == SpecTypePointer
			           //or bt == SpecTypeComplex
					   //must not be zero(not pointer)
			int nil;//eg. int a[]; int a[][2][3];
		} comp;//complex variable, array or pointer or both

		struct {
			struct type_t *ret;
			struct type_t **argv;
			int ellipsis;//int func(int a, int b, ...)
			size_t argc;
		} func;//func type

		struct {
			char *id;//struct name
			struct {
				char *id;//member name
				off_t off;//offset in bits, for union
				          //  it works only for anonymous struct
				size_t w;//bits
				struct type_t *dt;
			} *argv;
			size_t size;
		} uos;//union or struct
	};
} type_t;

typedef struct node_t {
	struct node_t *sibling;
	struct node_t *child;
	struct node_t *parent;//for reverse-travel

	/* semantic structure */
	int token;//syntax value like `Program` `TYPE` `INT`
	int production;//semantic reduce rule like `AST_Exp_is_ID`

	//dt + vi for id
	//dt + vi + cv for exp
	//for ID node, dt donates id's type, if id is constant, cv.t will indicate this
	//for Exp node, the same as above
	int lrv;//temporary strategy, left or right value
	type_t *dt;//data type, dt->bt reveal which value will be use in cv
	vi_t *vi;//for register allocation
	exp_const_part_t cv;//constant value

	/* for debugging */
	int error;
	int lineno, column;
} node_t;

/* function alloc a new type descriptor */
type_t *new_spec();

/* function return a string formating the type descriptor*/
char *type_format(type_t *type);
/* similar to `type_format`, plus the function format struct */
char *uos_format(type_t *type);

/* return type relation of given two types */
int get_type_relation(int btA, int btB);

/* return a pointer point to a type decriptor with bt `btype` */
type_t *convert_btype_to_pointer(uint32_t btype);

/* covert combine-type to `bt` */
int convert_ctype2type(int ct);

typedef void (*SemanFunc)(node_t *);

/* analyse syntax of a single production */
void syntax_analysis(node_t *root);

#endif
