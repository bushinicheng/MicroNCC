%{
#include <stdlib.h>
#include <stdio.h>
#include "basic-dat.h"
#include "syntax.h"
#include "common.h"
#include "component.h"

int yycolumn = 1;

#ifdef __DEBUG__
#define patternlog(a) \
	printf("{%s,\t%s}\n", a, yytext)
#else
#define patternlog(a) do{}while(0)
#endif

%}

%option noyywrap

float            [+-]?(([0-9]+\.([0-9]+)?)|(([0-9]+)?\.([0-9]+)))([eE][+-]?[0-9]+)?
int              [+-]?[1-9][0-9]+
hex              0[xX][0-9a-fA-F]+
oct              0[1-7][0-7]*
invalidnum       [0-9][_a-zA-Z0-9\.]*
string           (\"([^\"]*(\\\")?)*\"[ \t\r\n]*)+
blank            [ \t\r\n]+
id               [_a-zA-Z][_a-zA-Z0-9]*
end              [^_a-zA-Z]
multiplecomment  (?s:\/\*([^\*]|\*[^\/])*\*\/)
singlecomment    \/\/.*$

%%
"="                {patternlog("ASSIGN");return ASSIGNOP;}
"=="               {patternlog("EQ");return EQ;}
"<"                {patternlog("LT");return LT;}
"<="               {patternlog("LE");return LE;}
"<>"               {patternlog("NE");return NE;}
">"                {patternlog("GT");return GT;}
">="               {patternlog("GE");return GE;}
"("                {patternlog("LP");return LP;}
")"                {patternlog("RP");return RP;}
"["                {patternlog("LB");return LB;}
"]"                {patternlog("RB");return RB;}
"{"                {patternlog("LC");return LC;}
"}"                {patternlog("RC");return RC;}
"."                {patternlog("DOT");return DOT;}
","                {patternlog("COMMA");return COMMA;}
";"                {patternlog("SEMI");return SEMI;}
if                 {patternlog("IF");return IF;}
else               {patternlog("ELSE");return ELSE;}
do                 {patternlog("DO");return DO;}
while              {patternlog("WHILE");return WHILE;}
for                {patternlog("FOR");return FOR;}
int                {patternlog("INT");return INT;}
float              {patternlog("FLOAT");return FLOAT;}
struct             {patternlog("FLOAT");return STRUCT;}
{int}              {patternlog("NUM:i");atoi(yytext);return NUM;}
{hex}              {patternlog("NUM:x");atoi(yytext);return NUM;}
{oct}              {patternlog("NUM:o");atoi(yytext);return NUM;}
{blank}            {/*do nothing*/}
{float}            {patternlog("NUM:f");atof(yytext);return NUM;}
{invalidnum}       {patternlog("NUM:v");atoi(yytext);return NUM;}
{string}           {patternlog("STR");register_string(yytext);return STRING;}
{id}               {patternlog("ID");register_id(yytext);return ID;}
{multiplecomment}  {patternlog("MC");/*do nothing*/}
{singlecomment}    {patternlog("SC");/*do nothing*/}

%%

int main()
{
	int init_component();
	init_component();
    while(yylex()>0);
    return 0;
}
