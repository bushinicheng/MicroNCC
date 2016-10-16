%{
#include "common.h"
#include "basic-dat.h"
#include "syntax.h"
#include "component.h"
#include "ast.h"

#define MAX_SIZE 1024

int yycolumn = 1;
static char yylinetext[MAX_SIZE];

#ifdef __DEBUG_LEX__
#define plog(a) \
	do{printf("{%s,%s}\n", a, yytext);strcat(yylinetext, yytext);}while(0)
#else
#define plog(a) do{strcat(yylinetext, yytext);}while(0)
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
int              [+-]?([1-9][0-9]*|0)
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
"="                 {plog("AS");	return symbol(ASSIGNOP);}
"=="                {plog("EQ");	return symbol(EQ);}
"<"                 {plog("LT");	return symbol(LT);}
"<="                {plog("LE");	return symbol(LE);}
"!="                {plog("NE");	return symbol(NE);}
">"                 {plog("GT");	return symbol(GT);}
">="                {plog("GE");	return symbol(GE);}

"+"                 {plog("ADD");	return symbol(ADD);}
"-"                 {plog("SUB");	return symbol(SUB);}
"*"                 {plog("MULT");	return symbol(MULT);}
"/"                 {plog("DIV");	return symbol(DIV);}

"("                 {plog("LP");	return symbol(LP);}
")"                 {plog("RP");	return symbol(RP);}
"["                 {plog("LB");	return symbol(LB);}
"]"                 {plog("RB");	return symbol(RB);}
"{"                 {plog("LC");	return symbol(LC);}
"}"                 {plog("RC");	return symbol(RC);}
"."                 {plog("DOT");	return symbol(DOT);}
"->"                {plog("PT");	return symbol(POINTER);}
","                 {plog("COMMA");	return symbol(COMMA);}
";"                 {plog("SEMI");	return symbol(SEMI);}

if                  {plog("IF");	return symbol(IF);}
else                {plog("ELSE");	return symbol(ELSE);}
do                  {plog("DO");	return symbol(DO);}
while               {plog("WHILE");	return symbol(WHILE);}
for                 {plog("FOR");	return symbol(FOR);}
int                 {plog("INT");	return symbol(INT);}
float               {plog("FLOAT");	return symbol(FLOAT);}
struct              {plog("STRUCT");return symbol(STRUCT);}

{int}               {plog("NUM:i");	return num('i');}
{hex}               {plog("NUM:x");	return num('x');}
{oct}               {plog("NUM:o");	return num('o');}
{float}             {plog("NUM:f");	return num('f');}

{invalidnum}        {
						plog("NUM:v");
						yyerrlex(yylineno, yycolumn-yyleng+1, yyleng, ERR_INVALID_NUM, yylinetext);
						return symbol(NUM);
					}
{string}            {plog("STR");	return reg(STRING);}
{id}                {plog("ID");	return reg(ID);}
{blank}             {strcat(yylinetext, yytext);/*do nothing*/}
{newline}           {
						yylineno ++;
						yycolumn = 0;
						yylinetext[0] = 0;
					}
{multiplecomment}   {plog("MC");	/*do nothing*/}
{singlecomment}     {plog("SC");	/*do nothing*/}
.					{
						plog("UB");
						yyerrlex(yylineno, yycolumn-yyleng+1, yyleng, ERR_UNKNOWN_TOKEN, yylinetext);
					}

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
