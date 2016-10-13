%{
#include <stdlib.h>
#include <stdio.h>
#include "syntax.h"
#include "common.h"
#include "component.h"

int installFloat(float);
int installInt(int);

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
int                {patternlog("INT");return SPEC;}
float              {patternlog("FLOAT");return SPEC;}
{blank}            {/*do nothing*/}
{float}            {patternlog("NUM:f");installFloat(atof(yytext));return NUM;}
{int}              {patternlog("NUM:i");installInt(atoi(yytext));return NUM;}
{hex}              {patternlog("NUM:x");installInt(atoi(yytext));return NUM;}
{oct}              {patternlog("NUM:o");installInt(atoi(yytext));return NUM;}
{invalidnum}       {patternlog("NUM:v");installInt(atoi(yytext));return NUM;}
{string}           {patternlog("STR");register_string(yytext);return STRING;}
{id}               {patternlog("ID");register_id(yytext);return ID;}
{multiplecomment}  {patternlog("MC");/*do nothing*/}
{singlecomment}    {patternlog("SC");/*do nothing*/}

%%

int installFloat(float number)
{
    return 0;
}

int installInt(int number)
{
    return 0;
}

int main()
{
	int init_component();
	init_component();
    while(yylex()>0);
    return 0;
}
