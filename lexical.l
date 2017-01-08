%{
#include "common.h"

/*data structure for registering string and identifier*/
#define STRBUF_SIZE (1024*1024*2)

char strbuf[STRBUF_SIZE]; 
static int strbuf_ptr = 0;;

/*function declaration*/
int strcnt(const char *strin, char ch);
int next_number(char **str, int base);
char* register_string(const char *str);
char* register_id(const char *text);
int init_component();
int fileno(FILE *stream);

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

static int symbol(int syntaxval);
static int type(int specval);
static int num(int specval);
static int reg(int syntaxval);

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

"<<"                {tokout("LSHIFT");	return symbol(LSHIFT);}
">>"                {tokout("RSHIFT");	return symbol(RSHIFT);}
"<<="               {tokout("LSHIFTE");	return symbol(LSHIFTE);}
">>="               {tokout("RSHIFTE");	return symbol(RSHIFTE);}

"+"                 {tokout("ADD");		return symbol(ADD);}
"-"                 {tokout("SUB");		return symbol(SUB);}
"*"                 {tokout("MULT");	return symbol(MULT);}
"/"                 {tokout("DIV");		return symbol(DIV);}
"%"                 {tokout("MOD");		return symbol(MOD);}
"+="                {tokout("ADDE");	return symbol(ADDE);}
"-="                {tokout("SUBE");	return symbol(SUBE);}
"*="                {tokout("MULTE");	return symbol(MULTE);}
"/="                {tokout("DIVE");	return symbol(DIVE);}
"%="                {tokout("MODE");	return symbol(MODE);}
"++"                {tokout("INC"); 	return symbol(INC);}
"--"                {tokout("DEC");		return symbol(DEC);}
"&="                {tokout("ANDE");	return symbol(ANDE);}
"|="                {tokout("ORE");		return symbol(ORE);}
"^="                {tokout("XORE");	return symbol(XORE);}

"&"                 {tokout("AND");		return symbol(AND);}
"|"                 {tokout("OR");		return symbol(OR);}
"^"                 {tokout("XOR");		return symbol(XOR);}
"~"                 {tokout("NOT");		return symbol(NOT);}
"&&"                {tokout("LAND");	return symbol(LAND);}
"||"                {tokout("LOR");		return symbol(LOR);}
"!"                 {tokout("LNOT");	return symbol(LNOT);}
"sizeof"            {tokout("SIZEOF");	return symbol(SIZEOF);}

"("                 {tokout("LP");		return symbol(LP);}
")"                 {tokout("RP");		return symbol(RP);}
"["                 {tokout("LB");		return symbol(LB);}
"]"                 {tokout("RB");		return symbol(RB);}
"{"                 {tokout("LC");		return symbol(LC);}
"}"                 {tokout("RC");		return symbol(RC);}
"."                 {tokout("DOT");		return symbol(DOT);}
"->"                {tokout("PT");		return symbol(POINTER);}
","                 {tokout("COMMA");	return symbol(COMMA);}
":"                 {tokout("COMMA");	return symbol(COLON);}
";"                 {tokout("SEMI");	return symbol(SEMI);}
"..."               {tokout("SEMI");	return symbol(SEMI);}
"'\w+'"             {tokout("SEMI");	return symbol(SEMI);}

void                {tokout("VOID");	return type(VOID);}
bool                {tokout("BOOL");	return type(BOOL);}
char                {tokout("CHAR");	return type(CHAR);}
short               {tokout("SHORT");	return type(SHORT);}
int                 {tokout("INT");		return type(INT);}
unsigned            {tokout("UNSIGNED");return type(UNSIGNED);}
float               {tokout("FLOAT");	return type(FLOAT);}
double              {tokout("DOUBLE");	return type(DOUBLE);}
int8_t              {tokout("INT8T");	return type(INT8T);}
int16_t             {tokout("INT16T");	return type(INT16T);}
int32_t             {tokout("INT32T");	return type(INT32T);}
uint8_t             {tokout("UINT8T");	return type(UINT8T);}
uint16_t            {tokout("UINT16T");	return type(UINT16T);}
uint32_t            {tokout("UINT32T");	return type(UINT32T);}
size_t              {tokout("SIZET");	return type(SIZET);}
uintptr_t           {tokout("UINTPTRT");return type(UINTPTRT);}
off_t               {tokout("OFFT");	return type(OFFT);}

enum                {tokout("ENUM");	return symbol(ENUM);}
union               {tokout("UNION");	return symbol(UNION);}
struct              {tokout("STRUCT");	return symbol(STRUCT);}
NULL                {tokout("nil");		return symbol(NIL);}
true                {tokout("true");	return symbol(TRUE);}
false               {tokout("false");	return symbol(FALSE);}

if                  {tokout("IF");		return symbol(IF);}
else                {tokout("ELSE");	return symbol(ELSE);}
do                  {tokout("DO");		return symbol(DO);}
while               {tokout("WHILE");	return symbol(WHILE);}
for                 {tokout("FOR");		return symbol(FOR);}
return              {tokout("RETURN");	return symbol(RETURN);}
switch              {tokout("SWITCH");	return symbol(SWITCH);}
case                {tokout("CASE");	return symbol(CASE);}
break               {tokout("BREAK");	return symbol(BREAK);}
default             {tokout("DEFAULT");	return symbol(DEFAULT);}
goto                {tokout("GOTO");	return symbol(GOTO);}

{int}               {tokout("NUM:i");	return num('i');}
{hex}               {tokout("NUM:x");	return num('x');}
{oct}               {tokout("NUM:o");	return num('o');}
{float}             {tokout("NUM:f");	return num('f');}

{invalidnum}        {
						tokout("NUM:v");
						yydebug(yylineno, yycolumn-yyleng, yyleng, ErrorInvalidNUM);
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
						yydebug(yylineno, yycolumn-yyleng, yyleng, ErrorUnknownToken);
					}

%%

static int symbol(int syntaxval)
{
	Node *pnd = new_node();
	pnd->token = syntaxval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return syntaxval;
}

static int type(int specval)
{
	int syntaxval = TYPE;
	Node *pnd = new_node();
	pnd->token = syntaxval;
	pnd->idtype = new_spec();
	pnd->idtype->btype = SpecTypeConst;
	pnd->idtype->cons.suptype = specval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return syntaxval;
}

static int num(int specval)
{
	int syntaxval = NUM;
	char *pstr = yytext;
	Node *pnd = new_node();
	pnd->token = NUM;
	pnd->idtype = new_spec();
	pnd->idtype->lval = 1;
	pnd->idtype->btype = SpecTypeConst;
	pnd->idtype->cons.suptype = 'i';
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;

	switch(specval)
	{
	case 'i':
		pnd->idtype->cons.suptype = 'i';
		pnd->idtype->cons.supval.i = next_number(&pstr, 10);
		break;
	case 'o':
		pnd->idtype->cons.suptype = 'i';
		pstr++;
		pnd->idtype->cons.supval.i = next_number(&pstr, 8);
		break;
	case 'x':
		pnd->idtype->cons.suptype = 'i';
		pstr+=2;
		pnd->idtype->cons.supval.i = next_number(&pstr, 16);
		break;
	case 'f':
		pnd->idtype->cons.suptype = 'f';
		pnd->idtype->cons.supval.f = atof(pstr);
		break;
	}

	return syntaxval;
}

static int reg(int syntaxval)
{
	Node *pnd = new_node();
	pnd->token = syntaxval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	pnd->idtype = new_spec();
	pnd->idtype->btype = SpecTypeConst;

	switch(syntaxval)
	{
	case ID:
		pnd->idtype->cons.supval.st = register_id(yytext);
		break;
	case STRING:
		pnd->idtype->lval = 0;
		pnd->idtype->cons.suptype = 's';
		pnd->idtype->cons.supval.st = register_string(yytext);
		break;
	}

	return syntaxval;
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
	int ret_ptr = strbuf_ptr;
	char *p = (char *)str;
	bool in_str = true;
#ifdef __DEBUG__
	wt_assert(strbuf_ptr + strlen(str) < STRBUF_SIZE);
#endif
	while(*(++p)) //since the first char is always `"`
	{
		if(*p == '"') {in_str = !in_str;continue;}
		if(!in_str)	continue;
		if(*p != '\\')
			strbuf[strbuf_ptr ++] = *p;
		else
			switch(*(++p))
			{
				case '\\':strbuf[strbuf_ptr ++] = '\\';break;
				case 'n' :strbuf[strbuf_ptr ++] = '\n';break;
				case 'r' :strbuf[strbuf_ptr ++] = '\r';break;
				case 't' :strbuf[strbuf_ptr ++] = '\t';break;
				case 'b' :strbuf[strbuf_ptr ++] = '\b';break;
				case 'x' :
				case 'X' :p++;strbuf[strbuf_ptr ++] = next_number(&p, 16);p--;break;
				case '0' :p++;strbuf[strbuf_ptr ++] = next_number(&p, 8);p--;break;
				default  :strbuf[strbuf_ptr ++] = *p;break;
			}
	}
	strbuf[strbuf_ptr ++] = 0;
	return &strbuf[ret_ptr];
}

char* register_id(const char *text)
{
	int ret_ptr = strbuf_ptr;
	int len = strlen(text);
	strcat(&strbuf[strbuf_ptr], text);
	strbuf_ptr += len + 1;
	return &strbuf[ret_ptr];
}


int init_component()
{
#ifdef __DEBUG__
	/* unit test of register_string */
	UNIT_TEST_START;
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

	int test_len = sizeof(ss)/sizeof(ss[0]);
	for(int i = 0; i < test_len; i++)
	{
		char* p = register_string(ss[i]);
		UNIT_TEST_ASSERT(strcmp(p, ans[i]) == 0, "\nfail at case #%d, should be '%s' but got '%s'\n", i, ans[i], p);
	}

	UNIT_TEST_END;
#endif
	return 0;
}
