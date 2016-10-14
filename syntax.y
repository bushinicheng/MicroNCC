%{
#include <stdio.h>
#include "basic-dat.h"
#include "ast.h"

int yylex();
int yyerror(const char *str);

%}

%union {
	Node *pnd;
}

%token<pnd>
	LT LE NE EQ GE GT
	RELOP ASSIGNOP 
	LP RP LB RB LC RC
	DOT COMMA SEMI
	IF ELSE DO WHILE FOR RETURN /* inline key words */
	INT FLOAT STRUCT /* inline specifier */
	NUM STRING
	ID

%left PLUS SUB
%left MULTI DIVL

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
	TYPE
	FuncDec
	ArgList
	Arg
	CompSt
	Tag
	OptTag
	Exp

%%

Program:ExtDefList {astroot=build_subast(AST_Program_is_ExtDefList, $1);}
;

ExtDefList:ExtDef ExtDefList {$$=build_subast(AST_ExtDefList_is_ExtDef_ExtDefList, $1, $2);}
		  |ExtDef {$$=build_subast(AST_ExtDefList_is_ExtDef, $1);}
;

ExtDef:Specifier FuncDec CompSt {$$=build_subast(AST_ExtDef_is_Specifier_FuncDec_CompSt, $1, $2, $3);}
	  |Specifier SEMI {$$=build_subast(AST_ExtDef_is_Specifier_SEMI, $1, $2);}
	  |DefList {$$=build_subast(AST_ExtDef_is_DefList, $1);}
;

/*definition of function*/
FuncDec:ID LP RP {$$=build_subast(AST_FuncDec_is_ID_LP_RP, $1, $2, $3);}
	  |ID LP ArgList RP {$$=build_subast(AST_FuncDec_is_ID_LP_ArgList_RP, $1, $2, $3, $4);}
;

ArgList:Arg COMMA ArgList {$$=build_subast(AST_ArgList_is_Arg_COMMA_ArgList, $1, $2, $3);}
	   |Arg {$$=build_subast(AST_ArgList_is_Arg, $1);}
;

Arg:Specifier ID {$$=build_subast(AST_Arg_is_Specifier_ID, $1, $2);}
;

CompSt:LC DefList StmtList RC {$$=build_subast(AST_CompSt_is_LC_DefList_StmtList_RC, $1, $2, $3, $4);}
;

/* statement in function */
StmtList:Stmt StmtList {$$=build_subast(AST_StmtList_is_Stmt_StmtList, $1, $2);}
		|Stmt {$$=build_subast(AST_StmtList_is_Stmt, $1);}
;

Stmt:Exp SEMI {$$=build_subast(AST_Stmt_is_Exp_SEMI, $1, $2);}
;

/*definition of varible*/
DefList:Def DefList {$$=build_subast(AST_DefList_is_Def_DefList, $1, $2);}
	   |Def {$$=build_subast(AST_DefList_is_Def, $1);}
       | {$$=build_subast(AST_DefList_is_None);}
;

Def:Specifier DecList SEMI {$$=build_subast(AST_Def_is_Specifier_DecList_SEMI, $1, $2, $3);}
;

DecList:Dec COMMA DecList {$$=build_subast(AST_DecList_is_Dec_COMMA_DecList, $1, $2, $3);}
	   |Dec {$$=build_subast(AST_DecList_is_Dec, $1);}
       | {$$=build_subast(AST_DecList_is_None);}
;

Dec:VarDec {$$=build_subast(AST_Dec_is_VarDec, $1);}
   |VarDec ASSIGNOP Exp {$$=build_subast(AST_Dec_is_VarDec_ASSIGNOP_Exp, $1, $2, $3);}
;

VarDec:ID {$$=build_subast(AST_VarDec_is_ID, $1);}
;

/*specifier and struct*/
Specifier:TYPE {$$=build_subast(AST_Specifier_is_TYPE, $1);}
		  |StructSpecifier {$$=build_subast(AST_Specifier_is_StructSpecifier, $1);}
;

TYPE:INT {$$=build_subast(AST_TYPE_is_INT, $1);}
	|FLOAT {$$=build_subast(AST_TYPE_is_FLOAT, $1);}
;

StructSpecifier:STRUCT Tag {$$=build_subast(AST_StructSpecifier_is_STRUCT_Tag, $1, $2);}
			   |STRUCT OptTag LC DefList RC {$$=build_subast(AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC, $1, $2, $3, $4, $5);}
;

Tag:ID {$$=build_subast(AST_Tag_is_ID, $1);}
;

OptTag:ID {$$=build_subast(AST_OptTag_is_ID, $1);}
;

/*expression*/
Exp:ID {$$=build_subast(AST_Exp_is_ID, $1);}
   |NUM {$$=build_subast(AST_Exp_is_NUM, $1);}
   |STRING {$$=build_subast(AST_Exp_is_STRING, $1);}
   |Exp ASSIGNOP Exp {$$=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, $1, $2, $3);}
;
