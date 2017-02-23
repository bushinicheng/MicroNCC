%{
#include "common.h"

/*function declaration*/
int next_number(char **str, int base);
char register_literal(const char *str);
char* register_string(const char *str);
char* register_id(const char *text);
int fileno(FILE *stream);
void increase_actionlevel();
void decrease_actionlevel();

/*lexerr*/
#define MAX_SIZE 1024

static int yycolumn = 1;
char yylinetext[MAX_SIZE];

//#define __DEBUG_LEX__
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
static int qulfr(int token);
static int type(int rawtoken, int typeinfo);
static int num(int specval);
static int reg(int syntaxval);
static int relop(int token);
static int equop(int token);

%}

%option yylineno
%option noyywrap

float            (([0-9]+\.([0-9]+)?)|(([0-9]+)?\.([0-9]+)))([eE][+-]?[0-9]+)?
int              ([1-9][0-9]*|0)
hex              0[xX][0-9a-fA-F]+
oct              0[1-7][0-7]*
invalidnum       \.*[0-9][_a-zA-Z0-9\.]*
string           (\"([^\"]*(\\\")?)*\"[ \t\r\n]*)+
literal          (\'([^\']*(\\\')?)*\'[ \t\r\n]*)+
blank            [ \t\r]+
newline          \n+
id               [_a-zA-Z][_a-zA-Z0-9]*
blockcomment     (?s:\/\*([^\*]|\*[^\/])*\*\/)
linecomment      \/\/.*$
invalidcomment   \/\*([^\*]|\*[^\/])*$

%%
"="                 {tokout("AS");		return symbol(ASSIGNOP);}
"=="                {tokout("EQ");		return symbol(EQ);}
"!="                {tokout("NE");		return symbol(NE);}
"<"                 {tokout("LT");		return relop(LT);}
"<="                {tokout("LE");		return relop(LE);}
">"                 {tokout("GT");		return relop(GT);}
">="                {tokout("GE");		return relop(GE);}

"<<"                {tokout("LSHIFT");	return symbol(LSHIFT);}
">>"                {tokout("RSHIFT");	return symbol(RSHIFT);}
"<<="               {tokout("LSHIFTE");	return symbol(LSHIFTE);}
">>="               {tokout("RSHIFTE");	return symbol(RSHIFTE);}

"+"                 {tokout("ADD");		return symbol(ADD);}
"-"                 {tokout("SUB");		return symbol(SUB);}
"*"                 {tokout("MULT");	return symbol(MULT);}
"/"                 {tokout("DIV");		return symbol(DIV);}
"%"                 {tokout("MOD");		return symbol(MOD);}
"++"                {tokout("INC"); 	return symbol(INC);}
"--"                {tokout("DEC");		return symbol(DEC);}
"+="                {tokout("ADDE");	return equop(ADDE);}
"-="                {tokout("SUBE");	return equop(SUBE);}
"*="                {tokout("MULTE");	return equop(MULTE);}
"/="                {tokout("DIVE");	return equop(DIVE);}
"%="                {tokout("MODE");	return equop(MODE);}
"&="                {tokout("ANDE");	return equop(ANDE);}
"|="                {tokout("ORE");		return equop(ORE);}
"^="                {tokout("XORE");	return equop(XORE);}

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
"{"                 {tokout("LC");increase_actionlevel();return symbol(LC);}
"}"                 {tokout("RC");return symbol(RC);}
"."                 {tokout("DOT");		return symbol(DOT);}
"->"                {tokout("PT");		return symbol(PTR);}
","                 {tokout("COMMA");	return symbol(COMMA);}
"?"                 {tokout("QOP");		return symbol(QOP);}
":"                 {tokout("COLON");	return symbol(COLON);}
";"                 {tokout("SEMI");	return symbol(SEMI);}
"..."               {tokout("ELLIPSIS");return symbol(ELLIPSIS);}

void                {tokout("VOID");	return type(VOID, MAKE_WORD(SpecTypeVoid, false));}
bool                {tokout("BOOL");	return type(BOOL, MAKE_WORD(SpecTypeUint8, false));}
char                {tokout("CHAR");	return type(CHAR, MAKE_DWORD2(CombineTypeChar, MAKE_WORD(SpecTypeInt8, true)));}
short               {tokout("SHORT");	return type(SHORT, MAKE_DWORD2(CombineTypeShort, MAKE_WORD(SpecTypeInt16, true)));}
int                 {tokout("INT");		return type(INT, MAKE_DWORD2(CombineTypeInt, MAKE_WORD(SpecTypeInt32, true)));}
long                {tokout("LONG");	return type(LONG, MAKE_DWORD2(CombineTypeLong, MAKE_WORD(SpecTypeInt32, true)));}
signed              {tokout("SIGNED");	return type(SIGNED, MAKE_DWORD2(CombineTypeSigned, MAKE_WORD(SpecTypeInt32, true)));}
unsigned            {tokout("UNSIGNED");return type(UNSIGNED, MAKE_DWORD2(CombineTypeUnsigned, MAKE_WORD(SpecTypeUint32, true)));}
float               {tokout("FLOAT");	return type(FLOAT, MAKE_WORD(SpecTypeFloat32, false));}
double              {tokout("DOUBLE");	return type(DOUBLE, MAKE_DWORD2(CombineTypeDouble, MAKE_WORD(SpecTypeFloat64, true)));}
int8_t              {tokout("INT8T");	return type(INT8T, MAKE_WORD(SpecTypeInt8, false));}
int16_t             {tokout("INT16T");	return type(INT16T, MAKE_WORD(SpecTypeInt16, false));}
int32_t             {tokout("INT32T");	return type(INT32T, MAKE_WORD(SpecTypeInt32, false));}
int64_t             {tokout("INT64T");	return type(INT64T, MAKE_WORD(SpecTypeInt64, false));}
uint8_t             {tokout("UINT8T");	return type(UINT8T, MAKE_WORD(SpecTypeUint8, false));}
uint16_t            {tokout("UINT16T");	return type(UINT16T, MAKE_WORD(SpecTypeUint16, false));}
uint32_t            {tokout("UINT32T");	return type(UINT32T, MAKE_WORD(SpecTypeUint32, false));}
uint64_t            {tokout("UINT64T");	return type(UINT64T, MAKE_WORD(SpecTypeUint64, false));}
size_t              {tokout("SIZET");	return type(SIZET, MAKE_WORD(SpecTypeUint32, false));}
uintptr_t           {tokout("UINTPTRT");return type(UINTPTRT, MAKE_WORD(SpecTypeUint32, false));}
off_t               {tokout("OFFT");	return type(OFFT, MAKE_WORD(SpecTypeInt32, false));}

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

typedef             {tokout("TYPEDEF");	return qulfr(QulfrTypedef);}
extern              {tokout("EXTERN");	return qulfr(QulfrExtern);}
static              {tokout("STATIC");	return qulfr(QulfrStatic);}
auto                {tokout("AUTO");	return qulfr(QulfrAuto);}
register            {tokout("REGISTER");return qulfr(QulfrRegister);}

const               {tokout("CONST");	return qulfr(QulfrConst);}
volatile            {tokout("VOLATILE");return qulfr(QulfrVolatile);}

{int}               {tokout("NUM:i");	return num('i');}
{hex}               {tokout("NUM:x");	return num('x');}
{oct}               {tokout("NUM:o");	return num('o');}
{float}             {tokout("NUM:f");	return num('f');}

{invalidnum}        {
						tokout("NUM:v");
						yydbg(yylineno, yycolumn-yyleng, yyleng, ErrorInvalidNUM);
						return symbol(NUM);
					}
{literal}           {tokout("CHAR");	return reg(LITERAL);}
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
						yydbg(yylineno, yycolumn-yyleng, yyleng, ErrorUnknownToken);
					}

%%

static int qulfr(int token) {
	Node *pnd = new_node();
	pnd->token = TypeQulfr;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	pnd->cv.ex = token;
	yylval.pnd = pnd;
	return TypeQulfr;
}

static int equop(int token) {
	Node *pnd = new_node();
	pnd->token = token;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return EQUOP;
}

static int relop(int token) {
	Node *pnd = new_node();
	pnd->token = token;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return RELOP;
}

static int symbol(int syntaxval) {
	Node *pnd = new_node();
	pnd->token = syntaxval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return syntaxval;
}

static int type(int token, int typeinfo) {
	Node *pnd = new_node();
	pnd->token = TYPE;
	pnd->reduce_rule = token;
	pnd->cv.t = typeinfo;
	pnd->dt = convert_btype_to_pointer(WORD_PART1(typeinfo));
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return TYPE;
}

static int num(int numtype) {
	char *pstr = yytext;
	Node *pnd = new_node();
	pnd->token = NUM;
	pnd->dt = new_spec();//FIXME:overflow of int
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;

	switch(numtype) {
		case 'i':
			pnd->cv.t = 'i';
			pnd->cv.i = next_number(&pstr, 10);
			break;
		case 'o':
			pstr++;
			pnd->cv.t = 'o';
			pnd->cv.i = next_number(&pstr, 8);
			break;
		case 'x':
			pstr+=2;
			pnd->cv.t = 'x';
			pnd->cv.i = next_number(&pstr, 16);
			break;
		case 'f':
			pnd->cv.t = SpecTypeFloat32;
			pnd->cv.f = atof(pstr);
			break;
	}
	return NUM;
}

static int reg(int syntaxval) {
	Node *pnd = new_node();
	pnd->token = syntaxval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;

	switch(syntaxval)
	{
	case ID:
		pnd->cv.id = register_id(yytext);
		break;
	case STRING:
		pnd->lrv = SpecLvalue;
		pnd->dt = convert_btype_to_pointer(SpecTypeString);
		pnd->cv.str = register_string(yytext);
		break;
	case LITERAL:
		pnd->lrv = SpecRvalue;
		pnd->dt = convert_btype_to_pointer(SpecTypeInt8);
		pnd->cv._8 = register_literal(yytext);
		break;
	}

	return syntaxval;
}

int next_number(char **str, int base) {
	int retval = 0;
	/* 0xff,088,255 at most 4 nums */
	for(int i = 0; *str[0]; i++)
	{
		bool cur_valid = false;
		int ch = *(str[0]);
		str[0]++;
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
	}
	return retval;
}

char register_literal(const char *str) {
	if(str[1] == '\\') {
		char *p = (char *)&str[2];
		switch(str[2]){
			case '\\':return '\\';
			case 'n' :return '\n';
			case 'r' :return '\r';
			case 't' :return '\t';
			case 'b' :return '\b';
			case 'x' :
			case 'X' :return next_number(&p, 16);break;
			case '0' :return next_number(&p, 8);break;
			default  :return str[2];
		}
	}else{
		return str[1];
	}
}

/* return value is the start position of registered string */
char* register_string(const char *str) {
	int strbuf_ptr = 0;
	char *strbuf = get_memory_pointer();
	char *p = (char *)str;
	bool in_str = true;
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
	return (char*)require_memory(strbuf_ptr);
}

char* register_id(const char *text) {
	int len = strlen(text) + 1;
	char *strbuf = get_memory_pointer();
	strcpy(strbuf, text);
	return (char*)require_memory(len);
}


int init_component() {
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
		UNIT_TEST_ASSERT(strcmp(p, ans[i]) == 0, "fail at case #%d, should be '%s' but got '%s'.", i, ans[i], p);
	}

	const char *ns[] = {
		"12345678", "98765432", "87654321", "7654321",
		"7fa", "6ffaewr",
	};

	const int nas[] = {
		01234567, 12345678, 0x12345678,
		00, 98765432, 0x98765432,
		00, 87654321, 0x87654321,
		07654321, 7654321, 0x7654321,
		07, 7, 0x7fa,
		06, 6, 0x6ffae,
	};

	for(int i = 0; i < sizeof(ns)/sizeof(ns[0]); i++) {
		char *p = (char *)ns[i];
		int a = next_number(&p, 8);
		UNIT_TEST_ASSERT(a == nas[3 * i], "fail at case #%d, oct, should be %d but got %d.", i, nas[3 * i], a);
		p = (char *)ns[i];
		a = next_number(&p, 10);
		UNIT_TEST_ASSERT(a == nas[3 * i + 1], "fail at case #%d, dec, should be %d but got %d.", i, nas[3 * i + 1], a);
		p = (char *)ns[i];
		a = next_number(&p, 16);
		UNIT_TEST_ASSERT(a == nas[3 * i + 2], "fail at case #%d, hex, should be %d but got %d.", i, nas[3 * i + 2], a);
	}

	UNIT_TEST_END;
#endif
	return 0;
}
