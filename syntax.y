%{
#include "common.h"

int yylex();
int yyerror(const char *str, ...);

extern Node *astroot;
%}

%locations

%union {
	Node *pnd;
}

%nonassoc LOWWER_THAN_ELSE
%nonassoc ELSE

%token<pnd>
	ID NUM STRING LITERAL SIZEOF
	PTR INC DEC LSHIFT RSHIFT LE GE EQ NE
	AND OR MULTE DIVE MODE ADDE
	SUBE LSHIFTE RSHIFTE ANDE
	XORE ORE TYPE_NAME
	TYPEDEF EXTERN STATIC AUTO REGISTER
	CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
	STRUCT UNION ENUM ELLIPSIS
	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
	LC RC LB RB LP RP SEMI

%left COMMA
%right ASSIGN DIVE MULTE MODE ADDE SUBE LSHIFTE RSHIFTE ANDE XORE ORE
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

%start Program
%%

Program
	:ExtDecln
	|Program ExtDecln
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
	:Exp %prec ASSIGN
	|ExpList COMMA Exp
;

Decln
	:DeclnSpec SEMI
	|DeclnSpec InitDeclrList SEMI
;

DeclnSpec
	:ClassSpec
	|ClassSpec DeclnSpec
	|TypeSpec
	|TypeSpec DeclnSpec
	|TypeQulfr
	|TypeQulfr DeclnSpec
;

InitDeclrList
	:InitDeclr 
	|InitDeclrList COMMA InitDeclr
;

InitDeclr
	:Declr
	|Declr ASSIGN Init
;

ClassSpec
	:TYPEDEF
	|EXTERN
	|STATIC
	|AUTO
	|REGISTER
;

TypeSpec
	:VOID
	|CHAR
	|SHORT
	|INT
	|LONG
	|FLOAT
	|DOUBLE
	|SIGNED
	|UNSIGNED
	|CompSpec
	|EnumSpec
	|TYPE_NAME
;

CompSpec
	:CompType ID LC StructDeclnList RC
	|CompType LC StructDeclnList RC
	|CompType ID
;

CompType
	:STRUCT
	|UNION
;

StructDeclnList
	:StructDecln
	|StructDeclnList StructDecln
;

StructDecln
	:SpecQulfrList StructDeclrList SEMI
;

SpecQulfrList
	:TypeSpec SpecQulfrList
	|TypeSpec
	|TypeQulfr SpecQulfrList
	|TypeQulfr
;

StructDeclrList
	:StructDeclr
	|StructDeclrList COMMA StructDeclr
;

StructDeclr
	:Declr
	|COLON Exp
	|Declr COLON Exp
;

EnumSpec
	:ENUM LC EnumorList RC
	|ENUM ID LC EnumorList RC
	|ENUM ID
;

EnumorList
	:Enumor
	|EnumorList COMMA Enumor
;

Enumor
	:ID
	|ID ASSIGN Exp
;

TypeQulfr
	:CONST
	|VOLATILE
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
	:SpecQulfrList
	|SpecQulfrList AbstDeclr
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

Init
	:Exp %prec ASSIGN
	|LC InitList RC
	|LC InitList COMMA RC
;

InitList
	:Init
	|InitList COMMA Init
;

StmtList
	:Stmt
	|StmtList Stmt
;

ExpStmt
	:Exp SEMI
	|SEMI
;

CompSt
	:LC RC
	|LC StmtList RC
;

DeclnList
	:Decln
	|DeclnList Decln
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
	|Exp ASSIGN Exp
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

%%
