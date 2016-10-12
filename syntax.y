%{
#include <stdio.h>
#include "basic-dat.h"

%}

%union {
	Node *node;
	NodeInfo ni;
}

%token<yytokentype>
	RELOP ASSIGNOP 
	LP RP LB RB
	DELIM
	IF ELSE DO WHILE FOR RETURN /* inline key words */
	INT FLOAT STRUCT /* inline specifier */
	SPEC NUM STRING

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

%%

Program:           {/**/}
	   |ExtDefList {astroot=build_subast(@$, $1);}
;
