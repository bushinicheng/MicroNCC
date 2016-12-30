%{
#include "common.h"
#include "debug.h"
#include "ast.h"

int yylex();
int yyerror(const char *str, ...);

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
	BITAND BITOR BITNOR AND OR NOT
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
%left BITNOR
%left EQ NE
%left LT LE GE GT
%left ADD SUB
%left MULT DIV
%right NOT
%left DOT POINTER LB RB
%left LP RP

%type<pnd>
	Program
	ExtDefList
	ExtDef
	DefList
	Def
	StmtList
	Stmt
	DecList
	Dec
	VarDec
	Specifier
	StructSpecifier
	FuncDec
	DefArgList
	DefArg
	ArgList
	Arg
	CompSt
	Exp

%%

Program:ExtDefList {astroot=build_subast(AST_Program_is_ExtDefList, &@$, $1);}
;

ExtDefList:ExtDef {$$=build_subast(AST_ExtDefList_is_ExtDef, &@$, $1);}
		  |ExtDef ExtDefList {$$=build_subast(AST_ExtDefList_is_ExtDef_ExtDefList, &@$, $1, $2);}
;

ExtDef:Specifier FuncDec CompSt {$$=build_subast(AST_ExtDef_is_Specifier_FuncDec_CompSt, &@$, $1, $2, $3);}
	  |Def {$$=build_subast(AST_ExtDef_is_Def, &@$, $1);}
;

/*definition of function*/
FuncDec:ID LP RP {$$=build_subast(AST_FuncDec_is_ID_LP_RP, &@$, $1, $2, $3);}
	  |ID LP DefArgList RP {$$=build_subast(AST_FuncDec_is_ID_LP_DefArgList_RP, &@$, $1, $2, $3, $4);}
;

DefArgList:DefArg COMMA DefArgList {$$=build_subast(AST_DefArgList_is_DefArg_COMMA_DefArgList, &@$, $1, $2, $3);}
	   |DefArg {$$=build_subast(AST_DefArgList_is_DefArg, &@$, $1);}
;

DefArg:Specifier ID {$$=build_subast(AST_DefArg_is_Specifier_ID, &@$, $1, $2);}
;

CompSt:LC StmtList RC {$$=build_subast(AST_CompSt_is_LC_StmtList_RC, &@$, $1, $2, $3);}
	  |LC error StmtList RC {
		yyclearin;
		$$=build_subast(AST_CompSt_is_LC_StmtList_RC, &@$, $1, $3, $4);
		yydebug(@2.first_line, @2.last_column, 1, ERR_EXPECTED_STATEMENT);
		}
	  |LC StmtList error {
		$$=build_subast(AST_CompSt_is_LC_StmtList_RC, &@$, $1, $2, new_sym_node(RC, &@2));
		yyerr("%d:%d: error: missing '\x7d'\n", @2.last_line, @2.last_column);
		}
;

/* statement in function */
StmtList:Stmt StmtList {$$=build_subast(AST_StmtList_is_Stmt_StmtList, &@$, $1, $2);}
		|Stmt {$$=build_subast(AST_StmtList_is_Stmt, &@$, $1);}
;

Stmt:Exp SEMI {$$=build_subast(AST_Stmt_is_Exp_SEMI, &@$, $1, $2);}
	|Def {$$=build_subast(AST_Stmt_is_Def, &@$, $1);}
	|SEMI {}
	|RETURN Exp SEMI {$$=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &@$, $1, $2, $3);}
	|LC StmtList RC {$$=build_subast(AST_Stmt_is_LC_StmtList_RC, &@$, $1, $2, $3);}
	|IF LP Exp RP Stmt %prec LOWWER_THAN_ELSE {$$=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|IF LP Exp RP Stmt ELSE Stmt {$$=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &@$, $1, $2, $3, $4, $5, $6, $7);}
	|WHILE LP Exp RP Stmt {$$=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5);}
	|DO Stmt WHILE LP Exp RP SEMI {$$=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &@$, $1, $2, $3, $4, $5, $6, $7);}
	|FOR LP Exp SEMI Exp SEMI Exp RP Stmt {$$=build_subast(AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt, &@$, $1, $2, $3, $4, $5, $6, $7, $8, $9);}
	|Exp error SEMI {
		yyclearin;
		$$=build_subast(AST_Stmt_is_Exp_SEMI, &@$, $1, new_sym_node(SEMI, & @1));
		yydebug(@2.first_line, @2.first_column, 1, ERR_EXPECTED_SEMI);
	}
	|RETURN Exp error {
		$$=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &@$, $1, $2, new_sym_node(SEMI, & @2));
		yydebug(@2.first_line, @2.last_column, 1, ERR_MISSING_SEMI);
	}
	|LC StmtList error {
		$$=build_subast(AST_Stmt_is_LC_StmtList_RC, &@$, $1, $2, new_sym_node(RC, &@2));
		yyerr("%d:%d: error: missing '\x7d'\n", @$.first_line, @2.last_column);
	}
;

/*definition of varible*/
DefList:Def DefList {$$=build_subast(AST_DefList_is_Def_DefList, &@$, $1, $2);}
	   |Def {$$=build_subast(AST_DefList_is_Def, &@$, $1);}
;

Def:Specifier DecList SEMI {$$=build_subast(AST_Def_is_Specifier_DecList_SEMI, &@$, $1, $2, $3);}
   |Specifier SEMI {
		if($1->child->semanval != AST_StructSpecifier_is_STRUCT_LC_DefList_RC
		&& $1->child->semanval != AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC)
		{
			yydebug(@1.first_line, @1.last_column, 1, ERR_NULL_DECLARATION);
		}
		$$=build_subast(AST_Def_is_Specifier_SEMI, &@$, $1, $2);
	}
   |Specifier error {
		$$=build_subast(AST_Def_is_Specifier_SEMI, &@$, $1, new_sym_node(SEMI, & @1));
		yydebug(@$.first_line, @1.last_column, 1, ERR_MISSING_SEMI);
		}
   |Specifier DecList error {
		$$=build_subast(AST_Def_is_Specifier_DecList_SEMI, &@$, $1, $2, new_sym_node(SEMI, & @2));
		yydebug(@2.first_line, @2.last_column, 1, ERR_MISSING_SEMI);
	}
;

DecList:Dec COMMA DecList %prec ASSIGNOP {$$=build_subast(AST_DecList_is_Dec_COMMA_DecList, &@$, $1, $2, $3);}
	   |Dec {$$=build_subast(AST_DecList_is_Dec, &@$, $1);}
;

Dec:VarDec {$$=build_subast(AST_Dec_is_VarDec, &@$, $1);}
   |VarDec ASSIGNOP Exp {$$=build_subast(AST_Dec_is_VarDec_ASSIGNOP_Exp, &@$, $1, $2, $3);}
;

VarDec:ID {$$=build_subast(AST_VarDec_is_ID, &@$, $1);}
      |MULT VarDec {$$=build_subast(AST_VarDec_is_MULT_VarDec, &@$, $1, $2);}
	  |VarDec LB NUM RB {
		if($3->specval == 'f')
		{
			$3->specval = 'i';
			$3->exval.i = $3->exval.f;
			yyerr("%d: error type A: invalid dim\n", @$.first_line);
		}
		$$=build_subast(AST_VarDec_is_VarDec_LB_NUM_RB, &@$, $1, $2, $3, $4);
	}
;

/*specifier and struct*/
Specifier:TYPE {$$=build_subast(AST_Specifier_is_TYPE, &@$, $1);}
		 |StructSpecifier {$$=build_subast(AST_Specifier_is_StructSpecifier, &@$, $1);}
;

StructSpecifier:STRUCT ID {$$=build_subast(AST_StructSpecifier_is_STRUCT_ID, &@$, $1, $2);}
			   |STRUCT LC DefArgList RC {$$=build_subast(AST_StructSpecifier_is_STRUCT_LC_DefList_RC, &@$, $1, $2, $3, $4);}
			   |STRUCT ID LC DefArgList RC {$$=build_subast(AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC, &@$, $1, $2, $3, $4, $5);}
;

/*function call*/
ArgList:Arg COMMA ArgList {$$=build_subast(AST_ArgList_is_Arg_COMMA_ArgList, &@$, $1, $2, $3);}
	   |Arg {$$=build_subast(AST_ArgList_is_Arg, &@$, $1);}
;

Arg:Exp %prec ASSIGNOP {$$=build_subast(AST_Arg_is_Exp, &@$, $1);}
;

/*expression*/
Exp:ID {$$=build_subast(AST_Exp_is_ID, &@$, $1);}
   |ID LP ArgList RP {$$=build_subast(AST_Exp_is_ID_LP_ArgList_RP, &@$, $1, $2, $3, $4);}
   |NUM {$$=build_subast(AST_Exp_is_NUM, &@$, $1);}
   |ADD NUM {$$=build_subast(AST_Exp_is_ADD_NUM, &@$, $1, $2);}
   |SUB NUM {$$=build_subast(AST_Exp_is_SUB_NUM, &@$, $1, $2);}
   |MULT Exp {$$=build_subast(AST_Exp_is_MULT_Exp, &@$, $1, $2);}
   |BITAND Exp {$$=build_subast(AST_Exp_is_BITAND_Exp, &@$, $1, $2);}
   |BITNOR Exp {$$=build_subast(AST_Exp_is_BITNOR_Exp, &@$, $1, $2);}
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
   |Exp LB Exp error {
		yyclearin;
		$$=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &@$, $1, $2, $3, new_sym_node(RB, &@3));
		yydebug(@3.first_line, @3.last_column, 1, ERR_MISSING_RB);
	}
;
