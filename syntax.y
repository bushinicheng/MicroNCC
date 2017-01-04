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

%nonassoc LOWWEST
%nonassoc LOWWER_THAN_ELSE
%nonassoc ELSE

%token<pnd>
	LT LE NE EQ GE GT
	BITAND BITOR BITNOT AND OR NOT
	ADD SUB MULT DIV
	RELOP ASSIGNOP 
	LP RP LB RB LC RC
	DOT COMMA SEMI POINTER
	IF ELSE DO WHILE FOR RETURN /* inline key words */
	TYPE INT CHAR FLOAT ENUM STRUCT /* inline specifier */
	NUM STRING
	ID

%left COMMA
%left ASSIGNOP
%left OR
%left AND
%left BITOR
%left BITAND
%left BITNOT
%left EQ NE
%left LT LE GE GT
%left ADD SUB
%left MULT DIV
%right NOT
%left DOT POINTER LB RB
%left LP RP

%type<pnd>
	Program
	BlockList
	Block
	FuncDec
    FuncDefArgList
    FuncDefArg
    FuncCallArgList
    FuncCallArg
	IdList
	VarDef
	StmtList
	Stmt
	DecList
	Dec
	VarDec
	Specifier
	StructDec
	StructDecVar
	StructDecVarList
	CompSt
	Exp

%%

Program:BlockList {astroot=build_subast(AST_Program_is_BlockList, &@$, $1);}
;

BlockList:Block {$$=build_subast(AST_BlockList_is_Block, &@$, $1);}
		 |Block BlockList {$$=build_subast(AST_BlockList_is_Block_BlockList, &@$, $1, $2);}
;

Block:Specifier FuncDec CompSt {$$=build_subast(AST_Block_is_Specifier_FuncDec_CompSt, &@$, $1, $2, $3);}
	 |StructDec IdList SEMI {$$=build_subast(AST_Block_is_StructDec_IdList_SEMI, &@$, $1, $2, $3);}
	 |StructDec SEMI {$$=build_subast(AST_Block_is_StructDec_SEMI, &@$, $1, $2);}
	 |VarDef {$$=build_subast(AST_Block_is_VarDef, &@$, $1);}
;

IdList:VarDec COMMA IdList {$$=build_subast(AST_IdList_is_VarDec_COMMA_IdList, &@$, $1, $2, $3);}
	  |VarDec {$$=build_subast(AST_IdList_is_VarDec, &@$, $1);}
;

/*only for Struct Spec*/
StructDec:STRUCT ID LC StructDecVarList RC {$$=build_subast(AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC, &@$, $1, $2, $3, $4, $5);}
;

StructDecVarList:StructDecVar StructDecVarList {$$=build_subast(AST_StructDecVarList_is_StructDecVar_StructDecVarList, &@$, $1, $2);}
				|StructDecVar {$$=build_subast(AST_StructDecVarList_is_StructDecVar, &@$, $1);}
;

StructDecVar:Specifier IdList SEMI {$$=build_subast(AST_StructDecVar_is_Specifier_IdList_SEMI, &@$, $1, $2, $3);}
            |StructDec IdList SEMI {$$=build_subast(AST_StructDecVar_is_StructDec_IdList_SEMI, &@$, $1, $2, $3);}
;

/*args rules only for function*/
FuncDec:ID LP RP {$$=build_subast(AST_FuncDec_is_ID_LP_RP, &@$, $1, $2, $3);}
	   |ID LP FuncDefArgList RP {$$=build_subast(AST_FuncDec_is_ID_LP_FuncDefArgList_RP, &@$, $1, $2, $3, $4);}
;

FuncDefArgList:FuncDefArg COMMA FuncDefArgList {$$=build_subast(AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList, &@$, $1, $2, $3);}
	          |FuncDefArg {$$=build_subast(AST_FuncDefArgList_is_FuncDefArg, &@$, $1);}
;

FuncDefArg:Specifier VarDec {$$=build_subast(AST_FuncDefArg_is_Specifier_VarDec, &@$, $1, $2);}
;

CompSt:LC StmtList RC {$$=build_subast(AST_CompSt_is_LC_StmtList_RC, &@$, $1, $2, $3);}
;

/* statement in function */
StmtList:Stmt StmtList {$$=build_subast(AST_StmtList_is_Stmt_StmtList, &@$, $1, $2);}
		|Stmt {$$=build_subast(AST_StmtList_is_Stmt, &@$, $1);}
;

Stmt:Exp SEMI {$$=build_subast(AST_Stmt_is_Exp_SEMI, &@$, $1, $2);}
	|VarDef {$$=build_subast(AST_Stmt_is_VarDef, &@$, $1);}
	|CompSt {$$=build_subast(AST_Stmt_is_CompSt, &@$, $1);}
	|SEMI {}
	|RETURN Exp SEMI {$$=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &@$, $1, $2, $3);}
	|IF LP Exp RP Stmt %prec LOWWER_THAN_ELSE {$$=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|IF LP Exp RP Stmt ELSE Stmt {$$=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &@$, $1, $2, $3, $4, $5, $6, $7);}
	|WHILE LP Exp RP Stmt {$$=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|DO Stmt WHILE LP Exp RP SEMI {$$=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &@$, $1, $2, $3, $4, $5, $6, $7);}
	|FOR LP Exp SEMI Exp SEMI Exp RP Stmt {$$=build_subast(AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5, $6, $7, $8, $9);}
;

/*definition of varible:just used in stmt*/
VarDef:Specifier DecList SEMI {$$=build_subast(AST_VarDef_is_Specifier_DecList_SEMI, &@$, $1, $2, $3);}
;

/*init value for VarDef only!!!*/
DecList:Dec COMMA DecList %prec ASSIGNOP {$$=build_subast(AST_DecList_is_Dec_COMMA_DecList, &@$, $1, $2, $3);}
	   |Dec {$$=build_subast(AST_DecList_is_Dec, &@$, $1);}
;

Dec:VarDec {$$=build_subast(AST_Dec_is_VarDec, &@$, $1);}
   |VarDec ASSIGNOP Exp {$$=build_subast(AST_Dec_is_VarDec_ASSIGNOP_Exp, &@$, $1, $2, $3);}
;

VarDec:ID {$$=build_subast(AST_VarDec_is_ID, &@$, $1);}
      |MULT VarDec {$$=build_subast(AST_VarDec_is_MULT_VarDec, &@$, $1, $2);}
	  |VarDec LB NUM RB {
		if($3->idtype->cons.suptype == 'f')
		{
			$3->idtype->cons.suptype = 'i';
			$3->idtype->cons.supval.i = $3->idtype->cons.supval.f;
			yyerr("%d: error type A: invalid dim\n", @$.first_line);
		}
		$$=build_subast(AST_VarDec_is_VarDec_LB_NUM_RB, &@$, $1, $2, $3, $4);
	}
;

/*specifier and struct*/
Specifier:TYPE {$$=build_subast(AST_Specifier_is_TYPE, &@$, $1);}
		 |STRUCT ID {$$=build_subast(AST_Specifier_is_STRUCT_ID, &@$, $1, $2);}
;

/*function call*/
FuncCallArgList:FuncCallArg COMMA FuncCallArgList {$$=build_subast(AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList, &@$, $1, $2, $3);}
	           |FuncCallArg {$$=build_subast(AST_FuncCallArgList_is_FuncCallArg, &@$, $1);}
;

FuncCallArg:Exp %prec ASSIGNOP {$$=build_subast(AST_FuncCallArg_is_Exp, &@$, $1);}
;

/*expression*/
Exp:ID {$$=build_subast(AST_Exp_is_ID, &@$, $1);}
   |ID LP RP {$$=build_subast(AST_Exp_is_ID_LP_RP, &@$, $1, $2, $3);}
   |ID LP FuncCallArgList RP {$$=build_subast(AST_Exp_is_ID_LP_FuncCallArgList_RP, &@$, $1, $2, $3, $4);}
   |NUM {$$=build_subast(AST_Exp_is_NUM, &@$, $1);}
   |ADD NUM {$$=build_subast(AST_Exp_is_ADD_NUM, &@$, $1, $2);}
   |SUB NUM {$$=build_subast(AST_Exp_is_SUB_NUM, &@$, $1, $2);}
   |MULT Exp {$$=build_subast(AST_Exp_is_MULT_Exp, &@$, $1, $2);}
   |BITAND Exp {$$=build_subast(AST_Exp_is_BITAND_Exp, &@$, $1, $2);}
   |BITNOT Exp {$$=build_subast(AST_Exp_is_BITNOT_Exp, &@$, $1, $2);}
   |NOT Exp {$$=build_subast(AST_Exp_is_NOT_Exp, &@$, $1, $2);}
   |STRING {$$=build_subast(AST_Exp_is_STRING, &@$, $1);}
   |Exp ASSIGNOP Exp {$$=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &@$, $1, $2, $3);}
   |Exp COMMA Exp {$$=build_subast(AST_Exp_is_Exp_COMMA_Exp, &@$, $1, $2, $3);}
   |Exp DOT ID {$$=build_subast(AST_Exp_is_Exp_DOT_ID, &@$, $1, $2, $3);}
   |Exp POINTER ID {$$=build_subast(AST_Exp_is_Exp_POINTER_ID, &@$, $1, $2, $3);}
   |Exp ADD Exp {$$=build_subast(AST_Exp_is_Exp_ADD_Exp, &@$, $1, $2, $3);}
   |Exp SUB Exp {$$=build_subast(AST_Exp_is_Exp_SUB_Exp, &@$, $1, $2, $3);}
   |Exp MULT Exp {$$=build_subast(AST_Exp_is_Exp_MULT_Exp, &@$, $1, $2, $3);}
   |Exp DIV Exp {$$=build_subast(AST_Exp_is_Exp_DIV_Exp, &@$, $1, $2, $3);}
   |Exp EQ Exp {$$=build_subast(AST_Exp_is_Exp_EQ_Exp, &@$, $1, $2, $3);}
   |Exp LT Exp {$$=build_subast(AST_Exp_is_Exp_LT_Exp, &@$, $1, $2, $3);}
   |Exp LE Exp {$$=build_subast(AST_Exp_is_Exp_LE_Exp, &@$, $1, $2, $3);}
   |Exp NE Exp {$$=build_subast(AST_Exp_is_Exp_NE_Exp, &@$, $1, $2, $3);}
   |Exp GT Exp {$$=build_subast(AST_Exp_is_Exp_GT_Exp, &@$, $1, $2, $3);}
   |Exp GE Exp {$$=build_subast(AST_Exp_is_Exp_GE_Exp, &@$, $1, $2, $3);}
   |Exp AND Exp {$$=build_subast(AST_Exp_is_Exp_AND_Exp, &@$, $1, $2, $3);}
   |Exp OR Exp {$$=build_subast(AST_Exp_is_Exp_OR_Exp, &@$, $1, $2, $3);}
   |Exp BITAND Exp {$$=build_subast(AST_Exp_is_Exp_BITAND_Exp, &@$, $1, $2, $3);}
   |Exp BITOR Exp {$$=build_subast(AST_Exp_is_Exp_BITOR_Exp, &@$, $1, $2, $3);}
   |LP Exp RP {$$=build_subast(AST_Exp_is_LP_Exp_RP, &@$, $1, $2, $3);}
   |Exp LB Exp RB {$$=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &@$, $1, $2, $3, $4);}
;
