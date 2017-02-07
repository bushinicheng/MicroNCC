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
	ID NUM STRING LITERAL SIZEOF TYPE_NAME
	COMMA DOT PTR QOP COLON
	ASSIGNOP DIVE MULTE MODE ADDE SUBE LSHIFTE RSHIFTE ANDE XORE ORE
	LAND LOR OR XOR AND
	EQ NE LT LE GE GT
	LSHIFT RSHIFT ADD SUB MULT DIV MOD
	INC DEC LNOT NOT
	TYPEDEF EXTERN STATIC AUTO REGISTER CONST VOLATILE
	STRUCT UNION ENUM ELLIPSIS
	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
	LC RC LB RB LP RP SEMI
	TYPE NIL TRUE FALSE
	CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
	BOOL INT8T INT16T INT32T INT64T UINT8T UINT16T UINT32T UINT64T
	FLOAT32T FLOAT64T SIZET OFFT UINTPTRT
	TypeQulfr EQUOP RELOP UNARYOP

%left COMMA
%right ASSIGNOP DIVE MULTE MODE ADDE SUBE LSHIFTE RSHIFTE ANDE XORE ORE EQUOP
%right QOP COLON
%left LOR
%left LAND
%left OR
%left XOR
%left AND
%left EQ NE
%left LT LE GE GT RELOP
%left LSHIFT RSHIFT
%left ADD SUB
%left MULT DIV MOD
%right INC DEC LNOT NOT SIZEOF
%left DOT PTR LB RB
%left LP RP

%type<pnd>
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
	:ExtDeclnList {astroot=build_subast(AST_Program_is_ExtDeclnList, &@$, $1);}
;

ExtDeclnList
	:ExtDecln {astroot=build_subast(AST_ExtDeclnList_is_ExtDecln, &@$, $1);}
	|ExtDeclnList ExtDecln {$$=build_subast(AST_ExtDeclnList_is_ExtDeclnList_ExtDecln, &@$, $1, $2);}
;

ExtDecln
	:FuncDef {$$=build_subast(AST_ExtDecln_is_FuncDef, &@$, $1);}
	|Decln {$$=build_subast(AST_ExtDecln_is_Decln, &@$, $1);}
;

FuncDef
	:DeclnSpec Declr DeclnList CompSt {$$=build_subast(AST_FuncDef_is_DeclnSpec_Declr_DeclnList_CompSt, &@$, $1, $2, $3, $4);}
	|DeclnSpec Declr CompSt {$$=build_subast(AST_FuncDef_is_DeclnSpec_Declr_CompSt, &@$, $1, $2, $3);}
	|Declr DeclnList CompSt {$$=build_subast(AST_FuncDef_is_Declr_DeclnList_CompSt, &@$, $1, $2, $3);}
	|Declr CompSt {$$=build_subast(AST_FuncDef_is_Declr_CompSt, &@$, $1, $2);}
;

ExpList
	:Exp %prec ASSIGNOP {$$=build_subast(AST_ExpList_is_Exp, &@$, $1);}
	|ExpList COMMA Exp {$$=build_subast(AST_ExpList_is_ExpList_COMMA_Exp, &@$, $1, $2, $3);}
;

DeclnList
	:Decln {$$=build_subast(AST_DeclnList_is_Decln, &@$, $1);}
	|DeclnList Decln {$$=build_subast(AST_DeclnList_is_DeclnList_Decln, &@$, $1, $2);}
;

Decln
	:DeclnSpec SEMI {$$=build_subast(AST_Decln_is_DeclnSpec_SEMI, &@$, $1, $2);}
	|DeclnSpec InitorDeclrList SEMI {$$=build_subast(AST_Decln_is_DeclnSpec_InitorDeclrList_SEMI, &@$, $1, $2, $3);}
;

DeclnSpec
	:TypeSpec {$$=build_subast(AST_DeclnSpec_is_TypeSpec, &@$, $1);}
	|TypeSpec DeclnSpec {$$=build_subast(AST_DeclnSpec_is_TypeSpec_DeclnSpec, &@$, $1, $2);}
	|TypeQulfr {$$=build_subast(AST_DeclnSpec_is_TypeQulfr, &@$, $1);}
	|TypeQulfr DeclnSpec {$$=build_subast(AST_DeclnSpec_is_TypeQulfr_DeclnSpec, &@$, $1, $2);}
;

InitorDeclrList
	:InitorDeclr {$$=build_subast(AST_InitorDeclrList_is_InitorDeclr, &@$, $1);}
	|InitorDeclrList COMMA InitorDeclr {$$=build_subast(AST_InitorDeclrList_is_InitorDeclrList_COMMA_InitorDeclr, &@$, $1, $2, $3);}
;

InitorDeclr
	:Declr {$$=build_subast(AST_InitorDeclr_is_Declr, &@$, $1);}
	|Declr ASSIGNOP Initor {$$=build_subast(AST_InitorDeclr_is_Declr_ASSIGNOP_Initor, &@$, $1, $2, $3);}
;

TypeSpec
	:TYPE {$$=build_subast(AST_TypeSpec_is_TYPE, &@$, $1);}
	|CompSpec {$$=build_subast(AST_TypeSpec_is_CompSpec, &@$, $1);}
	|EnumSpec {$$=build_subast(AST_TypeSpec_is_EnumSpec, &@$, $1);}
	|TYPE_NAME {$$=build_subast(AST_TypeSpec_is_TYPE_NAME, &@$, $1);}
;

CompSpec
	:CompType ID LC CompDeclnList RC {$$=build_subast(AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC, &@$, $1, $2, $3, $4, $5);}
	|CompType LC CompDeclnList RC {$$=build_subast(AST_CompSpec_is_CompType_LC_CompDeclnList_RC, &@$, $1, $2, $3, $4);}
	|CompType ID {$$=build_subast(AST_CompSpec_is_CompType_ID, &@$, $1, $2);}
;

CompType
	:STRUCT {$$=build_subast(AST_CompType_is_STRUCT, &@$, $1);}
	|UNION {$$=build_subast(AST_CompType_is_UNION, &@$, $1);}
;

CompDeclnList
	:CompDecln {$$=build_subast(AST_CompDeclnList_is_CompDecln, &@$, $1);}
	|CompDeclnList CompDecln {$$=build_subast(AST_CompDeclnList_is_CompDeclnList_CompDecln, &@$, $1, $2);}
;

CompDecln
	:DeclnSpec SEMI {$$=build_subast(AST_CompDecln_is_DeclnSpec_SEMI, &@$, $1, $2);}
	|DeclnSpec CompDeclrList SEMI {$$=build_subast(AST_CompDecln_is_DeclnSpec_CompDeclrList_SEMI, &@$, $1, $2, $3);}
;

CompDeclrList
	:CompDeclr {$$=build_subast(AST_CompDeclrList_is_CompDeclr, &@$, $1);}
	|CompDeclr COMMA CompDeclrList {$$=build_subast(AST_CompDeclrList_is_CompDeclr_COMMA_CompDeclrList, &@$, $1, $2, $3);}
;

CompDeclr
	:Declr {$$=build_subast(AST_CompDeclr_is_Declr, &@$, $1);}
	|COLON Exp {$$=build_subast(AST_CompDeclr_is_COLON_Exp, &@$, $1, $2);}
	|Declr COLON Exp {$$=build_subast(AST_CompDeclr_is_Declr_COLON_Exp, &@$, $1, $2, $3);}
;

EnumSpec
	:ENUM LC EnumorList RC {$$=build_subast(AST_EnumSpec_is_ENUM_LC_EnumorList_RC, &@$, $1, $2, $3, $4);}
	|ENUM LC EnumorList COMMA RC {$$=build_subast(AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC, &@$, $1, $2, $3, $4, $5);}
	|ENUM ID LC EnumorList RC {$$=build_subast(AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC, &@$, $1, $2, $3, $4, $5);}
	|ENUM ID LC EnumorList COMMA RC {$$=build_subast(AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC, &@$, $1, $2, $3, $4, $5, $6);}
	|ENUM ID {$$=build_subast(AST_EnumSpec_is_ENUM_ID, &@$, $1, $2);}
;

EnumorList
	:Enumor {$$=build_subast(AST_EnumorList_is_Enumor, &@$, $1);}
	|EnumorList COMMA Enumor {$$=build_subast(AST_EnumorList_is_EnumorList_COMMA_Enumor, &@$, $1, $2, $3);}
;

Enumor
	:ID {$$=build_subast(AST_Enumor_is_ID, &@$, $1);}
	|ID ASSIGNOP Exp {$$=build_subast(AST_Enumor_is_ID_ASSIGNOP_Exp, &@$, $1, $2, $3);}
;

Declr
	:StarList DirectDeclr {$$=build_subast(AST_Declr_is_StarList_DirectDeclr, &@$, $1, $2);}
	|DirectDeclr {$$=build_subast(AST_Declr_is_DirectDeclr, &@$, $1);}
;

DirectDeclr
	:ID {$$=build_subast(AST_DirectDeclr_is_ID, &@$, $1);}
	|LP Declr RP {$$=build_subast(AST_DirectDeclr_is_LP_Declr_RP, &@$, $1, $2, $3);}
	|DirectDeclr LB Exp RB {$$=build_subast(AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB, &@$, $1, $2, $3, $4);}
	|DirectDeclr LB RB {$$=build_subast(AST_DirectDeclr_is_DirectDeclr_LB_RB, &@$, $1, $2, $3);}
	|DirectDeclr LP ParaTypeList RP {$$=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP, &@$, $1, $2, $3, $4);}
	|DirectDeclr LP IdList RP {$$=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP, &@$, $1, $2, $3, $4);}
	|DirectDeclr LP RP {$$=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_RP, &@$, $1, $2, $3);}
;

StarList
	:MULT {$$=build_subast(AST_StarList_is_MULT, &@$, $1);}
	|MULT TypeQulfrList {$$=build_subast(AST_StarList_is_MULT_TypeQulfrList, &@$, $1, $2);}
	|MULT StarList {$$=build_subast(AST_StarList_is_MULT_StarList, &@$, $1, $2);}
	|MULT TypeQulfrList StarList {$$=build_subast(AST_StarList_is_MULT_TypeQulfrList_StarList, &@$, $1, $2, $3);}
;

TypeQulfrList
	:TypeQulfr {$$=build_subast(AST_TypeQulfrList_is_TypeQulfr, &@$, $1);}
	|TypeQulfrList TypeQulfr {$$=build_subast(AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr, &@$, $1, $2);}
;

ParaTypeList
	:ParaList {$$=build_subast(AST_ParaTypeList_is_ParaList, &@$, $1);}
	|ParaList COMMA ELLIPSIS {$$=build_subast(AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS, &@$, $1, $2, $3);}
;

ParaList
	:ParaDecln {$$=build_subast(AST_ParaList_is_ParaDecln, &@$, $1);}
	|ParaList COMMA ParaDecln {$$=build_subast(AST_ParaList_is_ParaList_COMMA_ParaDecln, &@$, $1, $2, $3);}
;

ParaDecln
	:DeclnSpec Declr {$$=build_subast(AST_ParaDecln_is_DeclnSpec_Declr, &@$, $1, $2);}
	|DeclnSpec AbstDeclr {$$=build_subast(AST_ParaDecln_is_DeclnSpec_AbstDeclr, &@$, $1, $2);}
	|DeclnSpec {$$=build_subast(AST_ParaDecln_is_DeclnSpec, &@$, $1);}
;

IdList
	:ID {$$=build_subast(AST_IdList_is_ID, &@$, $1);}
	|IdList COMMA ID {$$=build_subast(AST_IdList_is_IdList_COMMA_ID, &@$, $1, $2, $3);}
;

TypeName
	:DeclnSpec {$$=build_subast(AST_TypeName_is_DeclnSpec, &@$, $1);}
	|DeclnSpec AbstDeclr {$$=build_subast(AST_TypeName_is_DeclnSpec_AbstDeclr, &@$, $1, $2);}
;

AbstDeclr
	:StarList {$$=build_subast(AST_AbstDeclr_is_StarList, &@$, $1);}
	|DirectAbstDeclr {$$=build_subast(AST_AbstDeclr_is_DirectAbstDeclr, &@$, $1);}
	|StarList DirectAbstDeclr {$$=build_subast(AST_AbstDeclr_is_StarList_DirectAbstDeclr, &@$, $1, $2);}
;

DirectAbstDeclr
	:LP AbstDeclr RP {$$=build_subast(AST_DirectAbstDeclr_is_LP_AbstDeclr_RP, &@$, $1, $2, $3);}
	|LB RB {$$=build_subast(AST_DirectAbstDeclr_is_LB_RB, &@$, $1, $2);}
	|LB Exp RB {$$=build_subast(AST_DirectAbstDeclr_is_LB_Exp_RB, &@$, $1, $2, $3);}
	|DirectAbstDeclr LB RB {$$=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_RB, &@$, $1, $2, $3);}
	|DirectAbstDeclr LB Exp RB {$$=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_Exp_RB, &@$, $1, $2, $3, $4);}
	|LP RP {$$=build_subast(AST_DirectAbstDeclr_is_LP_RP, &@$, $1, $2);}
	|LP ParaTypeList RP {$$=build_subast(AST_DirectAbstDeclr_is_LP_ParaTypeList_RP, &@$, $1, $2, $3);}
	|DirectAbstDeclr LP RP {$$=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_RP, &@$, $1, $2, $3);}
	|DirectAbstDeclr LP ParaTypeList RP {$$=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_ParaTypeList_RP, &@$, $1, $2, $3, $4);}
;

Initor
	:Exp %prec ASSIGNOP {$$=build_subast(AST_Initor_is_Exp, &@$, $1);}
	|DOT ID ASSIGNOP Exp %prec ASSIGNOP {$$=build_subast(AST_Initor_is_DOT_ID_ASSIGNOP_Exp, &@$, $1, $2, $3, $4);}
	|LB Exp RB ASSIGNOP Exp %prec ASSIGNOP {$$=build_subast(AST_Initor_is_LB_Exp_RB_ASSIGNOP_Exp, &@$, $1, $2, $3, $4, $5);}
	|LC InitorList RC {$$=build_subast(AST_Initor_is_LC_InitorList_RC, &@$, $1, $2, $3);}
	|LC InitorList COMMA RC {$$=build_subast(AST_Initor_is_LC_InitorList_COMMA_RC, &@$, $1, $2, $3, $4);}
;

InitorList
	:Initor {$$=build_subast(AST_InitorList_is_Initor, &@$, $1);}
	|InitorList COMMA Initor {$$=build_subast(AST_InitorList_is_InitorList_COMMA_Initor, &@$, $1, $2, $3);}
;

StmtList
	:Stmt {$$=build_subast(AST_StmtList_is_Stmt, &@$, $1);}
	|StmtList Stmt {$$=build_subast(AST_StmtList_is_StmtList_Stmt, &@$, $1, $2);}
;

ExpStmt
	:Decln {$$=build_subast(AST_ExpStmt_is_Decln, &@$, $1);}
	|Exp SEMI {$$=build_subast(AST_ExpStmt_is_Exp_SEMI, &@$, $1, $2);}
	|SEMI {$$=build_subast(AST_ExpStmt_is_SEMI, &@$, $1);}
;

CompSt
	:LC RC {$$=build_subast(AST_CompSt_is_LC_RC, &@$, $1, $2);}
	|LC StmtList RC {$$=build_subast(AST_CompSt_is_LC_StmtList_RC, &@$, $1, $2, $3);}
;

Stmt
	:SEMI {$$=build_subast(AST_Stmt_is_SEMI, &@$, $1);}
	|Decln {$$=build_subast(AST_Stmt_is_Decln, &@$, $1);}
	|Exp SEMI {$$=build_subast(AST_Stmt_is_Exp_SEMI, &@$, $1, $2);}
	|CompSt {$$=build_subast(AST_Stmt_is_CompSt, &@$, $1);}
	|GOTO ID SEMI {$$=build_subast(AST_Stmt_is_GOTO_ID_SEMI, &@$, $1, $2, $3);}
	|ID COLON {$$=build_subast(AST_Stmt_is_ID_COLON, &@$, $1, $2);}
	|CONTINUE SEMI {$$=build_subast(AST_Stmt_is_CONTINUE_SEMI, &@$, $1, $2);}
	|BREAK SEMI {$$=build_subast(AST_Stmt_is_BREAK_SEMI, &@$, $1, $2);}
	|RETURN SEMI {$$=build_subast(AST_Stmt_is_RETURN_SEMI, &@$, $1, $2);}
	|RETURN Exp SEMI {$$=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &@$, $1, $2, $3);}
	|IF LP Exp RP Stmt %prec LOWWER_THAN_ELSE {$$=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|IF LP Exp RP Stmt ELSE Stmt {$$=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &@$, $1, $2, $3, $4, $5, $6, $7);}
	|SWITCH LP Exp RP Stmt {$$=build_subast(AST_Stmt_is_SWITCH_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|CASE Exp COLON Stmt {$$=build_subast(AST_Stmt_is_CASE_Exp_COLON_Stmt, &@$, $1, $2, $3, $4);}
	|DEFAULT COLON Stmt {$$=build_subast(AST_Stmt_is_DEFAULT_COLON_Stmt, &@$, $1, $2, $3);}
	|WHILE LP Exp RP Stmt {$$=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|DO Stmt WHILE LP Exp RP SEMI {$$=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &@$, $1, $2, $3, $4, $5, $6, $7);}
	|FOR LP ExpStmt ExpStmt RP Stmt {$$=build_subast(AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_RP_Stmt, &@$, $1, $2, $3, $4, $5, $6);}
	|FOR LP ExpStmt ExpStmt Exp RP Stmt {$$=build_subast(AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5, $6, $7);}
;

Exp
	:ID {$$=build_subast(AST_Exp_is_ID, &@$, $1);}
	|NUM {$$=build_subast(AST_Exp_is_NUM, &@$, $1);}
	|NIL {$$=build_subast(AST_Exp_is_NIL, &@$, $1);}
	|TRUE {$$=build_subast(AST_Exp_is_TRUE, &@$, $1);}
	|FALSE {$$=build_subast(AST_Exp_is_FALSE, &@$, $1);}
	|STRING {$$=build_subast(AST_Exp_is_STRING, &@$, $1);}
	|LITERAL {$$=build_subast(AST_Exp_is_LITERAL, &@$, $1);}
	|LP Exp RP {$$=build_subast(AST_Exp_is_LP_Exp_RP, &@$, $1, $2, $3);}
	|Exp LB Exp RB {$$=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &@$, $1, $2, $3, $4);}
	|Exp LP RP {$$=build_subast(AST_Exp_is_Exp_LP_RP, &@$, $1, $2, $3);}
	|Exp LP ExpList RP {$$=build_subast(AST_Exp_is_Exp_LP_ExpList_RP, &@$, $1, $2, $3, $4);}
	|Exp DOT ID {$$=build_subast(AST_Exp_is_Exp_DOT_ID, &@$, $1, $2, $3);}
	|Exp PTR ID {$$=build_subast(AST_Exp_is_Exp_PTR_ID, &@$, $1, $2, $3);}
	|Exp INC {$$=build_subast(AST_Exp_is_Exp_INC, &@$, $1, $2);}
	|Exp DEC {$$=build_subast(AST_Exp_is_Exp_DEC, &@$, $1, $2);}
	|INC Exp {$$=build_subast(AST_Exp_is_INC_Exp, &@$, $1, $2);}
	|DEC Exp {$$=build_subast(AST_Exp_is_DEC_Exp, &@$, $1, $2);}
	|AND Exp {$$=build_subast(AST_Exp_is_AND_Exp, &@$, $1, $2);}
	|MULT Exp {$$=build_subast(AST_Exp_is_MULT_Exp, &@$, $1, $2);}
	|ADD Exp {$$=build_subast(AST_Exp_is_ADD_Exp, &@$, $1, $2);}
	|SUB Exp {$$=build_subast(AST_Exp_is_SUB_Exp, &@$, $1, $2);}
	|NOT Exp {$$=build_subast(AST_Exp_is_NOT_Exp, &@$, $1, $2);}
	|LNOT Exp {$$=build_subast(AST_Exp_is_LNOT_Exp, &@$, $1, $2);}
	|SIZEOF Exp {$$=build_subast(AST_Exp_is_SIZEOF_Exp, &@$, $1, $2);}
	|SIZEOF LP TypeName RP {$$=build_subast(AST_Exp_is_SIZEOF_LP_TypeName_RP, &@$, $1, $2, $3, $4);}
	|LP TypeName RP Exp {$$=build_subast(AST_Exp_is_LP_TypeName_RP_Exp, &@$, $1, $2, $3, $4);}
	|Exp MULT Exp {$$=build_subast(AST_Exp_is_Exp_MULT_Exp, &@$, $1, $2, $3);}
	|Exp DIV Exp {$$=build_subast(AST_Exp_is_Exp_DIV_Exp, &@$, $1, $2, $3);}
	|Exp MOD Exp {$$=build_subast(AST_Exp_is_Exp_MOD_Exp, &@$, $1, $2, $3);}
	|Exp ADD Exp {$$=build_subast(AST_Exp_is_Exp_ADD_Exp, &@$, $1, $2, $3);}
	|Exp SUB Exp {$$=build_subast(AST_Exp_is_Exp_SUB_Exp, &@$, $1, $2, $3);}
	|Exp LSHIFT Exp {$$=build_subast(AST_Exp_is_Exp_LSHIFT_Exp, &@$, $1, $2, $3);}
	|Exp RSHIFT Exp {$$=build_subast(AST_Exp_is_Exp_RSHIFT_Exp, &@$, $1, $2, $3);}
	|Exp RELOP Exp {$$=build_subast(AST_Exp_is_Exp_RELOP_Exp, &@$, $1, $2, $3);}
	|Exp EQ Exp {$$=build_subast(AST_Exp_is_Exp_EQ_Exp, &@$, $1, $2, $3);}
	|Exp NE Exp {$$=build_subast(AST_Exp_is_Exp_NE_Exp, &@$, $1, $2, $3);}
	|Exp AND Exp {$$=build_subast(AST_Exp_is_Exp_AND_Exp, &@$, $1, $2, $3);}
	|Exp XOR Exp {$$=build_subast(AST_Exp_is_Exp_XOR_Exp, &@$, $1, $2, $3);}
	|Exp OR Exp {$$=build_subast(AST_Exp_is_Exp_OR_Exp, &@$, $1, $2, $3);}
	|Exp LAND Exp {$$=build_subast(AST_Exp_is_Exp_LAND_Exp, &@$, $1, $2, $3);}
	|Exp LOR Exp {$$=build_subast(AST_Exp_is_Exp_LOR_Exp, &@$, $1, $2, $3);}
	|Exp QOP Exp COLON Exp {$$=build_subast(AST_Exp_is_Exp_QOP_Exp_COLON_Exp, &@$, $1, $2, $3, $4, $5);}
	|Exp ASSIGNOP Exp {$$=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &@$, $1, $2, $3);}
	|Exp EQUOP Exp {$$=build_subast(AST_Exp_is_Exp_EQUOP_Exp, &@$, $1, $2, $3);}
	|Exp COMMA Exp {$$=build_subast(AST_Exp_is_Exp_COMMA_Exp, &@$, $1, $2, $3);}
;
