%{
#include <stdlib.h>
#include <stdio.h>
#include "basic-dat.h"
#include "syntax.h"
#include "common.h"
#include "component.h"
#include "ast.h"
#include "error.h"

#define MAX_SIZE 1024

int yycolumn = 1;
static char yylinetext[MAX_SIZE];

#ifdef __DEBUG_LEX__
#define logd(a) \
	do{printf("{%s,%s}\n", a, yytext);strcat(yylinetext, yytext);}while(0)
#else
#define logd(a) do{strcat(yylinetext, yytext);}while(0)
#endif

#define YY_USER_ACTION do { \
		yycolumn += yyleng; \
	} while(0);

static int symbol(int lexval);
static int num(int specval);
static int reg(int lexval);

%}

%option noyywrap

float            [+-]?(([0-9]+\.([0-9]+)?)|(([0-9]+)?\.([0-9]+)))([eE][+-]?[0-9]+)?
int              [+-]?[1-9][0-9]*
hex              0[xX][0-9a-fA-F]+
oct              0[1-7][0-7]*
invalidnum       \.*[0-9][_a-zA-Z0-9\.]*
string           (\"([^\"]*(\\\")?)*\"[ \t\r\n]*)+
blank            [ \t\r]+
newline          [\n]+
id               [_a-zA-Z][_a-zA-Z0-9]*
multiplecomment  (?s:\/\*([^\*]|\*[^\/])*\*\/)
singlecomment    \/\/.*$

%%
"="                 {logd("AS");	return symbol(ASSIGNOP);}
"=="                {logd("EQ");	return symbol(EQ);}
"<"                 {logd("LT");	return symbol(LT);}
"<="                {logd("LE");	return symbol(LE);}
"!="                {logd("NE");	return symbol(NE);}
">"                 {logd("GT");	return symbol(GT);}
">="                {logd("GE");	return symbol(GE);}

"+"                 {logd("ADD");	return symbol(ADD);}
"-"                 {logd("SUB");	return symbol(SUB);}
"*"                 {logd("MULT");	return symbol(MULT);}
"/"                 {logd("DIV");	return symbol(DIV);}

"("                 {logd("LP");	return symbol(LP);}
")"                 {logd("RP");	return symbol(RP);}
"["                 {logd("LB");	return symbol(LB);}
"]"                 {logd("RB");	return symbol(RB);}
"{"                 {logd("LC");	return symbol(LC);}
"}"                 {logd("RC");	return symbol(RC);}
"."                 {logd("DOT");	return symbol(DOT);}
"->"                {logd("PT");	return symbol(POINTER);}
","                 {logd("COMMA");	return symbol(COMMA);}
";"                 {logd("SEMI");	return symbol(SEMI);}

if                  {logd("IF");	return symbol(IF);}
else                {logd("ELSE");	return symbol(ELSE);}
do                  {logd("DO");	return symbol(DO);}
while               {logd("WHILE");	return symbol(WHILE);}
for                 {logd("FOR");	return symbol(FOR);}
int                 {logd("INT");	return symbol(INT);}
float               {logd("FLOAT");	return symbol(FLOAT);}
struct              {logd("STRUCT");return symbol(STRUCT);}

{int}               {logd("NUM:i");	return num('i');}
{hex}               {logd("NUM:x");	return num('x');}
{oct}               {logd("NUM:o");	return num('o');}
{float}             {logd("NUM:f");	return num('f');}

{invalidnum}        {
						logd("NUM:v");
						yyerrlex(yylineno, yycolumn-yyleng+1, yyleng, ERR_INVALID_NUM, yylinetext);
						return symbol(NUM);
					}
{string}            {logd("STR");	return reg(STRING);}
{id}                {logd("ID");		return reg(ID);}
{blank}             {strcat(yylinetext, yytext);/*do nothing*/}
{newline}           {
						yylineno ++;
						yycolumn = 0;
						yylinetext[0] = 0;
					}
{multiplecomment}   {logd("MC");	/*do nothing*/}
{singlecomment}     {logd("SC");	/*do nothing*/}

%%

static int symbol(int lexval)
{
	Node *pnd = new_node();
	pnd->lexval = lexval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return lexval;
}

static int num(int specval)
{
	int lexval = NUM;
	char *pstr = yytext;
	Node *pnd = new_node();
	pnd->lexval = lexval;
	pnd->specval = specval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;

	switch(specval)
	{
	case 'i':
		pnd->exval.i = next_number(&pstr, 10);
		break;
	case 'o':
		pstr++;
		pnd->exval.i = next_number(&pstr, 8);
		break;
	case 'x':
		pstr+=2;
		pnd->exval.i = next_number(&pstr, 16);
		break;
	case 'f':
		pnd->exval.f = atof(pstr);
		break;
	}

	return lexval;
}

static int reg(int lexval)
{
	Node *pnd = new_node();
	pnd->lexval = lexval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;

	switch(lexval)
	{
	case ID:
		pnd->exval.st = register_id(yytext);
		break;
	case STRING:
		pnd->exval.st = register_string(yytext);
		break;
	}

	return lexval;
}
