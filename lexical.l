%{
#include <stdlib.h>
#include <stdio.h>
#include "syntax.h"

int installFloat(float);
int installInt(int);

int yycolumn = 1;

#define patternlog(a) \
	printf("(%s,%s)\t", a, yytext)

%}

%option noyywrap
%x NUM

float         [+-]?(([0-9]+\.([0-9]+)?)|(([0-9]+)?\.([0-9]+)))([eE][+-]?[0-9]+)?
int           [+-]?[0-9]+
hex           0[xX][0-9]+
oct           0[1-7][0-7]*
invalidnum    [0-9][_a-zA-Z0-9\.]*
string        (\"([^\"]*(\\\")?)*\")+
blank         [ \t\r\n]+
id            [_a-zA-Z][_a-zA-Z0-9]*
end           [^_a-zA-Z]
multicomment  (?s:\/\*([^\*]|\*[^\/])*\*\/)
singlecomment \/\/.*$

%%
"="              {patternlog("=");return ASSIGNOP;}
"=="             {patternlog("==");return EQ;}
"<"              {patternlog("<");return LT;}
"<="             {patternlog("<=");return LE;}
"<>"             {patternlog("<>");return NE;}
">"              {patternlog(">");return GT;}
">="             {patternlog(">=");return GE;}
"("              {patternlog("(");return LP;}
")"              {patternlog(")");return RP;}
"{"              {patternlog("{");return LB;}
"}"              {patternlog("}");return RB;}
";"              {patternlog(";");return DELIM;}
if               {patternlog("IF");return IF;}
else             {patternlog("ELSE");return ELSE;}
do               {patternlog("DO");return DO;}
while            {patternlog("WHILE");return WHILE;}
for              {patternlog("FOR");return FOR;}
int              {patternlog("INT");return SPEC;}
float            {patternlog("FLOAT");return SPEC;}
{blank}          {/*do nothing*/}
{float}          {patternlog("NUM:f");installFloat(atof(yytext));return NUM;}
{int}            {patternlog("NUM:i");installInt(atoi(yytext));return NUM;}
{hex}            {patternlog("NUM:x");installInt(atoi(yytext));return NUM;}
{oct}            {patternlog("NUM:o");installInt(atoi(yytext));return NUM;}
{invalidnum}     {patternlog("NUM:v");installInt(atoi(yytext));return NUM;}
{string}         {patternlog("STR");return STRING;}
{id}             {patternlog("ID");return ID;}
{multicomment}   {patternlog("MC");/*do nothing*/}
{singlecomment}  {patternlog("SC");/*do nothing*/}

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
    while(yylex()>0);
    return 0;
}
