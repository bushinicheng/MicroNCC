%{
#include "front-com.h"

/*function declaration*/
int next_number(char **str, int base);
char register_literal(const char *str);
char* register_string(const char *str);
char* register_id(const char *text);
int fileno(FILE *stream);
void increase_actionlevel();
void decrease_actionlevel();

#define YY_NO_UNPUT
#define YY_NO_INPUT

/*lexerr*/
static int yycolumn = 1;

extern YYLTYPE yylloc;

#define YY_USER_ACTION do { \
		yylloc.first_line = yylloc.last_line = yylineno; \
		yylloc.first_column = yycolumn; \
		yylloc.last_column = yycolumn+yyleng-1; \
		yycolumn += yyleng; \
	} while(0);

#define YY_DECL int next_token(void)

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
id               [_a-zA-Z][_a-zA-Z0-9]*
blockcomment     (?s:\/\*([^\*]|\*[^\/])*\*\/)
linecomment      \/\/.*$
invalidcomment   \/\*([^\*]|\*[^\/])*$

%%
^#define            {return symbol(MACRO_DEFINE);}
^#undef             {return symbol(MACRO_UNDEF);}
^#if                {return symbol(MACRO_IF);}
^#elif              {return symbol(MACRO_ELIF);}
^#else              {return symbol(MACRO_ELSE);}
^#endif             {return symbol(MACRO_ENDIF);}
^#line              {return symbol(MACRO_LINE);}
^#warning           {return symbol(MACRO_WARNING);}
^#error             {return symbol(MACRO_ERROR);}
"#"                 {return symbol(STRINGIFY);}
"##"                {return symbol(CONCAT);}
"__LINE__"          {}
"__func__"          {}
"__FILE__"          {}
"__VA_ARGS__"       {}

"="                 {return symbol(ASSIGNOP);}
"=="                {return symbol(EQ);}
"!="                {return symbol(NE);}
"<"                 {return relop(LT);}
"<="                {return relop(LE);}
">"                 {return relop(GT);}
">="                {return relop(GE);}

"<<"                {return symbol(LSHIFT);}
">>"                {return symbol(RSHIFT);}
"<<="               {return symbol(LSHIFTE);}
">>="               {return symbol(RSHIFTE);}

"+"                 {return symbol(ADD);}
"-"                 {return symbol(SUB);}
"*"                 {return symbol(MULT);}
"/"                 {return symbol(DIV);}
"%"                 {return symbol(MOD);}
"++"                {return symbol(INC);}
"--"                {return symbol(DEC);}
"+="                {return equop(ADDE);}
"-="                {return equop(SUBE);}
"*="                {return equop(MULTE);}
"/="                {return equop(DIVE);}
"%="                {return equop(MODE);}
"&="                {return equop(ANDE);}
"|="                {return equop(ORE);}
"^="                {return equop(XORE);}

"&"                 {return symbol(AND);}
"|"                 {return symbol(OR);}
"^"                 {return symbol(XOR);}
"~"                 {return symbol(NOT);}
"&&"                {return symbol(LAND);}
"||"                {return symbol(LOR);}
"!"                 {return symbol(LNOT);}
"sizeof"            {return symbol(SIZEOF);}

"("                 {return symbol(LP);}
")"                 {return symbol(RP);}
"["                 {return symbol(LB);}
"]"                 {return symbol(RB);}
"{"                 {increase_actionlevel();return symbol(LC);}
"}"                 {return symbol(RC);}
"."                 {return symbol(DOT);}
"->"                {return symbol(PTR);}
","                 {return symbol(COMMA);}
"?"                 {return symbol(QOP);}
":"                 {return symbol(COLON);}
";"                 {return symbol(SEMI);}
"..."               {return symbol(ELLIPSIS);}
\\\n                {/*do nothing*/}
\n                  {return symbol(NEWLINE);}
[ \t\r\f]+          {return symbol(SPACE);}

void                {return type(VOID, MAKE_WORD(SpecTypeVoid, false));}
bool                {return type(BOOL, MAKE_WORD(SpecTypeUint8, false));}
char                {return type(CHAR, MAKE_DWORD2(CombineTypeChar, MAKE_WORD(SpecTypeInt8, true)));}
short               {return type(SHORT, MAKE_DWORD2(CombineTypeShort, MAKE_WORD(SpecTypeInt16, true)));}
int                 {return type(INT, MAKE_DWORD2(CombineTypeInt, MAKE_WORD(SpecTypeInt32, true)));}
long                {return type(LONG, MAKE_DWORD2(CombineTypeLong, MAKE_WORD(SpecTypeInt32, true)));}
signed              {return type(SIGNED, MAKE_DWORD2(CombineTypeSigned, MAKE_WORD(SpecTypeInt32, true)));}
unsigned            {return type(UNSIGNED, MAKE_DWORD2(CombineTypeUnsigned, MAKE_WORD(SpecTypeUint32, true)));}
float               {return type(FLOAT, MAKE_WORD(SpecTypeFloat32, false));}
double              {return type(DOUBLE, MAKE_DWORD2(CombineTypeDouble, MAKE_WORD(SpecTypeFloat64, true)));}
int8_t              {return type(INT8T, MAKE_WORD(SpecTypeInt8, false));}
int16_t             {return type(INT16T, MAKE_WORD(SpecTypeInt16, false));}
int32_t             {return type(INT32T, MAKE_WORD(SpecTypeInt32, false));}
int64_t             {return type(INT64T, MAKE_WORD(SpecTypeInt64, false));}
uint8_t             {return type(UINT8T, MAKE_WORD(SpecTypeUint8, false));}
uint16_t            {return type(UINT16T, MAKE_WORD(SpecTypeUint16, false));}
uint32_t            {return type(UINT32T, MAKE_WORD(SpecTypeUint32, false));}
uint64_t            {return type(UINT64T, MAKE_WORD(SpecTypeUint64, false));}
size_t              {return type(SIZET, MAKE_WORD(SpecTypeUint32, false));}
uintptr_t           {return type(UINTPTRT, MAKE_WORD(SpecTypeUint32, false));}
off_t               {return type(OFFT, MAKE_WORD(SpecTypeInt32, false));}

enum                {return symbol(ENUM);}
union               {return symbol(UNION);}
struct              {return symbol(STRUCT);}
NULL                {return symbol(NIL);}
true                {return symbol(TRUE);}
false               {return symbol(FALSE);}

if                  {return symbol(IF);}
else                {return symbol(ELSE);}
do                  {return symbol(DO);}
while               {return symbol(WHILE);}
for                 {return symbol(FOR);}
return              {return symbol(RETURN);}
switch              {return symbol(SWITCH);}
case                {return symbol(CASE);}
break               {return symbol(BREAK);}
default             {return symbol(DEFAULT);}
goto                {return symbol(GOTO);}

typedef             {return qulfr(QulfrTypedef);}
extern              {return qulfr(QulfrExtern);}
static              {return qulfr(QulfrStatic);}
auto                {return qulfr(QulfrAuto);}
register            {return qulfr(QulfrRegister);}

const               {return qulfr(QulfrConst);}
volatile            {return qulfr(QulfrVolatile);}

{int}               {return num('i');}
{hex}               {return num('x');}
{oct}               {return num('o');}
{float}             {return num('f');}

{invalidnum}        {
						
						//yydbg(yylineno, yycolumn-yyleng, yyleng, ErrorInvalidNUM);
						return symbol(NUM);
					}
{literal}           {return reg(LITERAL);}
{string}            {return reg(STRING);}
{id}                {return reg(ID);}
{blockcomment}      {/*do nothing*/}
{linecomment}       {/*do nothing*/}
{invalidcomment}    {
						
						extern int curlineno;
						logd("%d: error type A: invalid comment\n", curlineno);
					}
.					{
						//FIXME
						//yydbg(yylineno, yycolumn-yyleng, yyleng, ErrorUnknownToken);
					}

%%

static int qulfr(int token) {
	node_t *pnd = new_node();
	pnd->token = TypeQulfr;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	pnd->cv.ex = token;
	yylval.pnd = pnd;
	return TypeQulfr;
}

static int equop(int token) {
	node_t *pnd = new_node();
	pnd->token = token;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return EQUOP;
}

static int relop(int token) {
	node_t *pnd = new_node();
	pnd->token = token;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return RELOP;
}

static int symbol(int syntaxval) {
	node_t *pnd = new_node();
	pnd->token = syntaxval;
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return syntaxval;
}

static int type(int token, int typeinfo) {
	/* +----------------+--------+--------+
	 * |       ct       |   bt   |   0/1  |
	 * +----------------+--------+--------+
	 */
	node_t *pnd = new_node();
	pnd->token = TYPE;
	pnd->production = token;
	pnd->cv.t = typeinfo;
	pnd->dt = convert_btype_to_pointer(WORD_PART1(typeinfo));
	pnd->lineno = yylineno;
	pnd->column = yycolumn;
	yylval.pnd = pnd;
	return TYPE;
}

static int num(int numtype) {
	char *pstr = yytext;
	node_t *pnd = new_node();
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
	node_t *pnd = new_node();
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

void register_macro(char *id, macro_t *macro) {
}

void handle_macro() {
}

int yylex() {
#define match_token(token) do {\
	if(next_token() != token) {\
		while(next_token() != NEWLINE); \
		lexval = next_token(); \
		goto __match_fail__;\
	}\
}while(0)
	int lexval = 0;
	switch(lexval = next_token()) {
	case SPACE:
	case NEWLINE:
		do{lexval = next_token();}while(lexval == NEWLINE || lexval == SPACE);
		break;
	case MACRO_DEFINE:
		if(next_token() == ID) {
			int cnt = 0;
			macro_t macro;
			char *id = yylval.pnd->cv.id;
			if(next_token() == LP) {
				//macro func
				char **args = get_memory_pointer();
				while(true) {
					lexval = next_token();
					if(lexval == ID)
						args[cnt ++] = yylval.pnd->cv.id;
					else if(lexval == ELLIPSIS) {
						match_token(RP);
						break;
					}else{
						yyerr("expected identifier or '...' here\n");
						goto __match_fail__;
					}

					lexval = next_token();
					if(lexval == COMMA) {
						continue;
					}else if(lexval == RP){
						break;
					}else{
						yyerr("expected ',' or ')' here\n");
						goto __match_fail__;
					}
				}
				args = require_memory(sizeof(char *) * cnt);
				macro.args = args;
				register_macro(id, &macro);
			}else{
				//comon macro
			}
			register_macro(id, &macro);
		}
		break;
	default:
		break;
	}
__match_fail__:
	return lexval;
}


int init_lexical() {
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
