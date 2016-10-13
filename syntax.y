%{
#include <stdio.h>
#include "basic-dat.h"
%}

%union {
	Node *node;
	NodeInfo ni;
}

%token<YYTOKENTYPE>
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

%type<node>
	Program
	ExtDefList
	ExtDef
	DefList
	Def
	StmtList
	Stmt
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

Program:ExtDefList {}
;

ExtDefList:ExtDef ExtDefList
		  |ExtDef
;

ExtDef:Specifier FuncDec CompSt
	  |Specifier SEMI
;

/*definition of function*/
FuncDec:ID LP RP
	  |ID LP ArgList RP
;

ArgList:Arg COMMA ArgList
	   |Arg
;

Arg:Specifier ID;

CompSt:LC DefList StmtList RC
;

/* statement in function */
StmtList:Stmt StmtList
		|Stmt;

Stmt:Exp SEMI
;

/*definition of varible*/
DefList:Def DefList
	   |Def
       | /*no action*/;

Def:Specifier DecList SEMI;

DecList:Dec COMMA DecList
	   |Dec
       | /*no action*/;

Dec:VarDec
   |VarDec ASSIGNOP Exp;

VarDec:ID;

/*specifier and struct*/
Specifier:TYPE
		  |StructSpecifier;

TYPE:INT
	|FLOAT;

StructSpecifier:STRUCT Tag
			   |STRUCT OptTag LC DefList RC;

Tag:ID;

OptTag:ID;

/*expression*/
Exp:ID;
