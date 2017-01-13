# compiler work

##introduction
* build this project
 * `make`

##syntax of c11
```
%nonassoc LOWWER_THAN_ELSE
%nonassoc ELSE

%token
	ID NUM STRING LITERAL SIZEOF TYPE_NAME
	COMMA DOT PTR QOP COLON
	ASSIGNOP DIVE MULTE MODE ADDE SUBE LSHIFTE RSHIFTE ANDE XORE ORE
	LAND LOR OR XOR AND
	EQ NE LT LE GE GT
	LSHIFT RSHIFT ADD SUB MULT DIV MOD
	INC DEC LNOT NOT
	TYPEDEF EXTERN STATIC AUTO REGISTER CONST VOLATILE
	CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
	STRUCT UNION ENUM ELLIPSIS
	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
	LC RC LB RB LP RP SEMI
	BOOL INT8T INT16T INT32T INT64T UINT8T UINT16T UINT32T UINT64T
	FLOAT32T FLOAT64T
	SIZET UINTPTRT OFFT NIL TRUE FALSE

%left COMMA
%right ASSIGNOP DIVE MULTE MODE ADDE SUBE LSHIFTE RSHIFTE ANDE XORE ORE
%right QOP COLON
%left LOR
%left LAND
%left OR
%left XOR
%left AND
%left EQ NE
%left LT LE GE GT
%left LSHIFT RSHIFT
%left ADD SUB
%left MULT DIV MOD
%right INC DEC LNOT NOT SIZEOF
%left DOT PTR LB RB
%left LP RP

%type
	Program
	ExtDecln
	ExtDeclnList
	FuncDef
	ExpList
	Decln
	DeclnSpec
	InitorDeclrList
	InitorDeclr
	TypeSpec
	CompSpec
	CompType
	CompDeclnList
	CompDecln
	CompDeclrList
	CompDeclr
	EnumSpec
	EnumorList
	Enumor
	TypeQulfr
	Declr
	DirectDeclr
	StarList
	TypeQulfrList
	ParaTypeList
	ParaList
	ParaDecln
	IdList
	TypeName
	AbstDeclr
	DirectAbstDeclr
	Initor
	InitorList
	StmtList
	ExpStmt
	CompSt
	DeclnList
	Stmt
	Exp

%start Program
%%

Program
	:ExtDeclnList 
;

ExtDeclnList
	:ExtDecln 
	|ExtDeclnList ExtDecln 
;

ExtDecln
	:FuncDef 
	|Decln 
;

FuncDef
	:DeclnSpec Declr DeclnList CompSt 
	|DeclnSpec Declr CompSt 
	|Declr DeclnList CompSt 
	|Declr CompSt 
;

ExpList
	:Exp %prec ASSIGNOP 
	|ExpList COMMA Exp 
;

Decln
	:DeclnSpec SEMI 
	|DeclnSpec InitorDeclrList SEMI 
;

DeclnList
	:Decln 
	|DeclnList Decln 
;

DeclnSpec
	:TypeSpec 
	|TypeSpec DeclnSpec 
	|TypeQulfr 
	|TypeQulfr DeclnSpec 
;

InitorDeclrList
	:InitorDeclr 
	|InitorDeclrList COMMA InitorDeclr 
;

InitorDeclr
	:Declr 
	|Declr ASSIGNOP Initor 
;

TypeQulfr
	:TYPEDEF 
	|EXTERN 
	|STATIC 
	|AUTO 
	|REGISTER 
	|CONST 
	|VOLATILE 
;

TypeSpec
	:VOID 
	|BOOL 
	|CHAR 
	|SHORT 
	|INT 
	|LONG 
	|FLOAT 
	|DOUBLE 
	|SIGNED 
	|UNSIGNED 
	|INT8T 
	|INT16T 
	|INT32T 
	|INT64T 
	|UINT8T 
	|UINT16T 
	|UINT32T 
	|UINT64T 
	|FLOAT32T 
	|FLOAT64T 
	|UINTPTRT 
	|SIZET 
	|OFFT 
	|CompSpec 
	|EnumSpec 
	|TYPE_NAME 
;

CompSpec
	:CompType ID LC CompDeclnList RC 
	|CompType LC CompDeclnList RC 
	|CompType ID 
;

CompType
	:STRUCT 
	|UNION 
;

CompDeclnList
	:CompDecln 
	|CompDeclnList CompDecln 
;

CompDecln
	:DeclnSpec SEMI 
	|DeclnSpec CompDeclrList SEMI 
;

CompDeclrList
	:CompDeclr 
	|CompDeclrList COMMA CompDeclr 
;

CompDeclr
	:Declr 
	|COLON Exp 
	|Declr COLON Exp 
;

EnumSpec
	:ENUM LC EnumorList RC 
	|ENUM LC EnumorList COMMA RC 
	|ENUM ID LC EnumorList RC 
	|ENUM ID LC EnumorList COMMA RC 
	|ENUM ID 
;

EnumorList
	:Enumor 
	|EnumorList COMMA Enumor 
;

Enumor
	:ID 
	|ID ASSIGNOP Exp 
;

Declr
	:StarList DirectDeclr 
	|DirectDeclr 
;

DirectDeclr
	:ID 
	|LP Declr RP 
	|DirectDeclr LB Exp RB 
	|DirectDeclr LB RB 
	|DirectDeclr LP ParaTypeList RP 
	|DirectDeclr LP IdList RP 
	|DirectDeclr LP RP 
;

StarList
	:MULT 
	|MULT TypeQulfrList 
	|MULT StarList 
	|MULT TypeQulfrList StarList 
;

TypeQulfrList
	:TypeQulfr 
	|TypeQulfrList TypeQulfr 
;

ParaTypeList
	:ParaList 
	|ParaList COMMA ELLIPSIS 
;

ParaList
	:ParaDecln 
	|ParaList COMMA ParaDecln 
;

ParaDecln
	:DeclnSpec Declr 
	|DeclnSpec AbstDeclr 
	|DeclnSpec 
;

IdList
	:ID 
	|IdList COMMA ID 
;

TypeName
	:DeclnSpec 
	|DeclnSpec AbstDeclr 
;

AbstDeclr
	:StarList 
	|DirectAbstDeclr 
	|StarList DirectAbstDeclr 
;

DirectAbstDeclr
	:LP AbstDeclr RP 
	|LB RB 
	|LB Exp RB 
	|DirectAbstDeclr LB RB 
	|DirectAbstDeclr LB Exp RB 
	|LP RP 
	|LP ParaTypeList RP 
	|DirectAbstDeclr LP RP 
	|DirectAbstDeclr LP ParaTypeList RP 
;

Initor
	:Exp %prec ASSIGNOP 
	|LB Exp RB ASSIGNOP Exp %prec ASSIGNOP 
	|LC InitorList RC 
	|LC InitorList COMMA RC 
;

InitorList
	:Initor 
	|InitorList COMMA Initor 
;

StmtList
	:Stmt 
	|StmtList Stmt 
;

ExpStmt
	:Decln 
	|Exp SEMI 
	|SEMI 
;

CompSt
	:LC RC 
	|LC StmtList RC 
;

Stmt
	:SEMI 
	|Decln 
	|Exp SEMI 
	|CompSt 
	|GOTO ID SEMI 
	|ID COLON 
	|CONTINUE SEMI 
	|BREAK SEMI 
	|RETURN SEMI 
	|RETURN Exp SEMI 
	|IF LP Exp RP Stmt %prec LOWWER_THAN_ELSE 
	|IF LP Exp RP Stmt ELSE Stmt 
	|SWITCH LP Exp RP Stmt 
	|CASE Exp COLON Stmt 
	|DEFAULT COLON Stmt 
	|WHILE LP Exp RP Stmt 
	|DO Stmt WHILE LP Exp RP SEMI 
	|FOR LP ExpStmt ExpStmt RP Stmt 
	|FOR LP ExpStmt ExpStmt Exp RP Stmt 
;

Exp
	:ID 
	|NUM 
	|NIL 
	|TRUE 
	|FALSE 
	|STRING 
	|LITERAL 
	|LP Exp RP 
	|Exp LB Exp RB 
	|Exp LP RP 
	|Exp LP ExpList RP 
	|Exp DOT ID 
	|Exp PTR ID 
	|Exp INC 
	|Exp DEC 
	|INC Exp 
	|DEC Exp 
	|AND Exp 
	|MULT Exp 
	|ADD Exp 
	|SUB Exp 
	|NOT Exp 
	|LNOT Exp 
	|SIZEOF Exp 
	|SIZEOF LP TypeName RP 
	|LP TypeName RP Exp 
	|Exp MULT Exp 
	|Exp DIV Exp 
	|Exp MOD Exp 
	|Exp ADD Exp 
	|Exp SUB Exp 
	|Exp LSHIFT Exp 
	|Exp RSHIFT Exp 
	|Exp LT Exp 
	|Exp GT Exp 
	|Exp LE Exp 
	|Exp GE Exp 
	|Exp EQ Exp 
	|Exp NE Exp 
	|Exp AND Exp 
	|Exp XOR Exp 
	|Exp OR Exp 
	|Exp LAND Exp 
	|Exp LOR Exp 
	|Exp QOP Exp COLON Exp 
	|Exp ASSIGNOP Exp 
	|Exp MULTE Exp 
	|Exp DIVE Exp 
	|Exp MODE Exp 
	|Exp ADDE Exp 
	|Exp SUBE Exp 
	|Exp LSHIFTE Exp 
	|Exp RSHIFTE Exp 
	|Exp ANDE Exp 
	|Exp XORE Exp 
	|Exp ORE Exp 
	|Exp COMMA Exp 
;

```

##example
```
/*
 * // c style comment
 */

struct typeA {
	int a, b, *c, d[10][20][30][40];//arbitrary dimension of array
	struct typeB {
		int z;
		struct typeC {//arbitrary depth of nested struct
			int *p;
		} a, b, c;
	} **t[15];
};

int myfunc(struct typeA *a[2], int p, int z) {//arbitrary number of arguments
	int ret = p * z;
	if(p > z) {
		a[0]->a = 1;
		a[0][0].b = p & z;
	}

	return ret;
}

int main(int argc, char **argv) {
	return 0;
}

```
