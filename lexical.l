%{
#include "common.h"
#include "basic-dat.h"
#include "syntax.h"
#include "ast.h"

/*data structure for registering string and identifier*/
#define STRBUF_SIZE (1024*1024*2)

char strbuf[STRBUF_SIZE]; 
static int strbuf_p = 0;;

/*function declaration*/
int strcnt(const char *strin, char ch);
int next_number(char **str, int base);
char* register_string(const char *str);
char* register_id(const char *text);
int init_component();

/*lexerr*/
#define MAX_SIZE 1024

static int yycolumn = 1;
char yylinetext[MAX_SIZE];

#ifdef __DEBUG_LEX__
#define tokout(a) \
	do{printf("{%s,%s}\n", a, yytext);strcat(yylinetext, yytext);}while(0)
#else
#define tokout(a) do{strcat(yylinetext, yytext);}while(0)
#endif

extern YYLTYPE yylloc;

#define YY_USER_ACTION do { \
		yylloc.first_line = yylloc.last_line = yylineno; \
		yylloc.first_column = yycolumn; \
		yylloc.last_column = yycolumn+yyleng-1; \
		yycolumn += yyleng; \
	} while(0);

static int symbol(int lexval);
static int type(int specval);
static int num(int specval);
static int reg(int lexval);

%}

%option yylineno
%option noyywrap

float            (([0-9]+\.([0-9]+)?)|(([0-9]+)?\.([0-9]+)))([eE][+-]?[0-9]+)?
int              ([1-9][0-9]*|0)
hex              0[xX][0-9a-fA-F]+
oct              0[1-7][0-7]*
invalidnum       \.*[0-9][_a-zA-Z0-9\.]*
string           (\"([^\"]*(\\\")?)*\"[ \t\r\n]*)+
blank            [ \t\r]+
newline          \n+
id               [_a-zA-Z][_a-zA-Z0-9]*
blockcomment     (?s:\/\*([^\*]|\*[^\/])*\*\/)
linecomment      \/\/.*$
invalidcomment   \/\*([^\*]|\*[^\/])*$

%%
"="                 {tokout("AS");		return symbol(ASSIGNOP);}
"=="                {tokout("EQ");		return symbol(EQ);}
"<"                 {tokout("LT");		return symbol(LT);}
"<="                {tokout("LE");		return symbol(LE);}
"!="                {tokout("NE");		return symbol(NE);}
">"                 {tokout("GT");		return symbol(GT);}
">="                {tokout("GE");		return symbol(GE);}

"+"                 {tokout("ADD");		return symbol(ADD);}
"-"                 {tokout("SUB");		return symbol(SUB);}
"*"                 {tokout("MULT");	return symbol(MULT);}
"/"                 {tokout("DIV");		return symbol(DIV);}

"&"                 {tokout("BITAND");	return symbol(BITAND);}
"|"                 {tokout("BITOR");	return symbol(BITOR);}
"&&"                {tokout("AND");		return symbol(AND);}
"||"                {tokout("OR");		return symbol(OR);}
"!"                 {tokout("NOT");		return symbol(NOT);}

"("                 {tokout("LP");		return symbol(LP);}
")"                 {tokout("RP");		return symbol(RP);}
"["                 {tokout("LB");		return symbol(LB);}
"]"                 {tokout("RB");		return symbol(RB);}
"{"                 {tokout("LC");		return symbol(LC);}
"}"                 {tokout("RC");		return symbol(RC);}
"."                 {tokout("DOT");		return symbol(DOT);}
"->"                {tokout("PT");		return symbol(POINTER);}
","                 {tokout("COMMA");	return symbol(COMMA);}
";"                 {tokout("SEMI");	return symbol(SEMI);}

if                  {tokout("IF");		return symbol(IF);}
else                {tokout("ELSE");	return symbol(ELSE);}
do                  {tokout("DO");		return symbol(DO);}
while               {tokout("WHILE");	return symbol(WHILE);}
for                 {tokout("FOR");		return symbol(FOR);}
int                 {tokout("INT");		return type(INT);}
char                {tokout("CHAR");	return type(CHAR);}
float               {tokout("FLOAT");	return type(FLOAT);}
struct              {tokout("STRUCT");	return symbol(STRUCT);}
return              {tokout("RETURN");	return symbol(RETURN);}

{int}               {tokout("NUM:i");	return num('i');}
{hex}               {tokout("NUM:x");	return num('x');}
{oct}               {tokout("NUM:o");	return num('o');}
{float}             {tokout("NUM:f");	return num('f');}

{invalidnum}        {
						tokout("NUM:v");
						yyerrlex(yylineno, yycolumn-yyleng, yyleng, ERR_INVALID_NUM);
						return symbol(NUM);
					}
{string}            {tokout("STR");		return reg(STRING);}
{id}                {tokout("ID");		return reg(ID);}
{blank}             {strcat(yylinetext, yytext);/*do nothing*/}
{newline}           {
						yycolumn = 1;
						yylinetext[0] = 0;
					}
{blockcomment}      {tokout("MC");	/*do nothing*/}
{linecomment}       {tokout("SC");	/*do nothing*/}
{invalidcomment}    {
						tokout("IC");
						extern int curlineno;
						logd("%d: error type A: invalid comment\n", curlineno);
					}
.					{
						tokout("UB");
						yyerrlex(yylineno, yycolumn-yyleng, yyleng, ERR_UNKNOWN_TOKEN);
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

static int type(int specval)
{
	int lexval = TYPE;
	Node *pnd = new_node();
	pnd->lexval = lexval;
	pnd->specval = specval;
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

int double_buffer(void **buf, int size)
{
	void *tbuf = malloc(size * 2);
	memcpy(tbuf, *buf, size);
	free(*buf);
	*buf = tbuf;
	return 0;
}

int next_number(char **str, int base)
{
	int retval = 0;
	/* 0xff,088,255 at most 4 nums */
	for(int i = 0; i < 3; i++)
	{
		bool cur_valid = false;
		int ch = *(str[0]++);
		switch(base)
		{
			case 16:
				if(('0' <= ch && ch <= '9')
					|| ('a' <= ch && ch <= 'f')
					|| ('A' <= ch && ch <= 'F'))
				{
					if('0' <= ch && ch <= '9')
						retval = retval*16+ch-'0';
					else if('a' <= ch && ch <= 'f')
						retval = retval*16+ch+10-'a';
					else if('A' <= ch && ch <= 'F')
						retval = retval*16+ch+10-'A';
					cur_valid = true;
				}
				break;
			case 1:case 2:case 3:case 4:case 5:
			case 6:case 7:case 8:case 9:case 10:
				if('0' <= ch && ch < '0' + base)
				{
					retval = retval*base+ch-'0';
					cur_valid = true;
				}
				break;
		}
		if(!cur_valid) {str[0]--;break;}
		if(retval > 256) break;
	}
	return retval;
}

/* return value is the start position of registered string */
char* register_string(const char *str)
{
	int ret_p = strbuf_p;
	char *p = (char *)str;
	bool in_str = true;
#ifdef __DEBUG__
	assert(strbuf_p + strlen(str) < STRBUF_SIZE);
#endif
	while(*(++p)) //since the first char is always `"`
	{
		if(*p == '"') {in_str = !in_str;continue;}
		if(!in_str)	continue;
		if(*p != '\\')
			strbuf[strbuf_p ++] = *p;
		else
			switch(*(++p))
			{
				case '\\':strbuf[strbuf_p ++] = '\\';break;
				case 'n' :strbuf[strbuf_p ++] = '\n';break;
				case 'r' :strbuf[strbuf_p ++] = '\r';break;
				case 't' :strbuf[strbuf_p ++] = '\t';break;
				case 'b' :strbuf[strbuf_p ++] = '\b';break;
				case 'x' :
				case 'X' :p++;strbuf[strbuf_p ++] = next_number(&p, 16);p--;break;
				case '0' :p++;strbuf[strbuf_p ++] = next_number(&p, 8);p--;break;
				default  :strbuf[strbuf_p ++] = *p;break;
			}
	}
	strbuf[strbuf_p ++] = 0;
	return &strbuf[ret_p];
}

char* register_id(const char *text)
{
	int ret_p = strbuf_p;
	int len = strlen(text);
	strcat(&strbuf[strbuf_p], text);
	strbuf_p += len + 1;
	return &strbuf[ret_p];
}

int init_component()
{
#ifdef __DEBUG__
	/* unit test of register_string */
	logd("[unit test]func:%s, line:%d...", __func__, __LINE__);
	const char *ss[] = {
		"\"Hello World!\"",
		"\"prefix\"\"\\n\\r\\t\\\\suffix\"",
		"\"prefix\" \r\n  \t  \"suffix\"",
		"\"pre\\\"fix\"  \t\n \"suf\\\"fix\"",
		"\"\\x48\\x65\\x6c\\x6c\\x6f\\x20\\x57\\x6f\\x72\\x6c\\x64\\x21\"",
		"\"\\0110\\0145\\0154\\0154\\0157\\040\\0127\\0157\\0162\\0154\\0144\\041\""
	};
	const char *ans[] = {
		"Hello World!",
		"prefix\n\r\t\\suffix",
		"prefixsuffix",
		"pre\"fixsuf\"fix",
		"Hello World!",
		"Hello World!"
	};

	bool pass = true;
	int test_len = sizeof(ss)/sizeof(ss[0]);
	for(int i = 0; i < test_len; i++)
	{
		char* p = register_string(ss[i]);
		if(strcmp(p, ans[i]) != 0)
		{
			loge("\ntest failed at case #%d.", i);
			loge("\nshould be '%s' but got '%s'", ans[i], p);
			pass = false;
			break;
		}
	}

	if(pass)
		logG("PASS\n");
	else
		logd("\n");
#endif
	return 0;
}

int strcnt(const char *strin, char ch)
{
	int ret = 0;
	char *p = (char*)strin;
	do{ret+=*p==ch;}while(*p++);
	return ret;
}
