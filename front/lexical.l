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
nb               [ \t\f\r]*
blockcomment     (?s:\/\*([^\*]|\*[^\/])*\*\/)
linecomment      \/\/.*$
invalidcomment   \/\*([^\*]|\*[^\/])*$

%%
^{nb}#{nb}define    {return symbol(MACRO_DEFINE);}
^{nb}#{nb}undef     {return symbol(MACRO_UNDEF);}
^{nb}#{nb}if        {return symbol(MACRO_IF);}
^{nb}#{nb}elif      {return symbol(MACRO_ELIF);}
^{nb}#{nb}else      {return symbol(MACRO_ELSE);}
^{nb}#{nb}endif     {return symbol(MACRO_ENDIF);}
^{nb}#{nb}line      {return symbol(MACRO_LINE);}
^{nb}#{nb}warning   {return symbol(MACRO_WARNING);}
^{nb}#{nb}error     {return symbol(MACRO_ERROR);}
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
	pnd->cv.str = sformat("%s", yytext);
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
	case LITERAL:
		pnd->lrv = SpecRvalue;
		pnd->dt = convert_btype_to_pointer(SpecTypeInt8);
		pnd->cv.str = sformat("%s", yytext);
		pnd->cv._8 = register_literal(yytext);
		break;
	case STRING:
		pnd->lrv = SpecLvalue;
		pnd->dt = convert_btype_to_pointer(SpecTypeString);
		pnd->cv.str = register_string(yytext);
		break;
	case ID:
		pnd->cv.id = register_id(yytext);
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
	int buf_ptr = 0;
	char *buf = malloc(strlen(str) + 1);
	char *p = (char *)str;
	bool in_str = true;
	while(*(++p)) //since the first char is always `"`
	{
		if(*p == '"') {in_str = !in_str;continue;}
		if(!in_str)	continue;
		if(*p != '\\')
			buf[buf_ptr ++] = *p;
		else
			switch(*(++p))
			{
				case '\\':buf[buf_ptr ++] = '\\';break;
				case 'n' :buf[buf_ptr ++] = '\n';break;
				case 'r' :buf[buf_ptr ++] = '\r';break;
				case 't' :buf[buf_ptr ++] = '\t';break;
				case 'b' :buf[buf_ptr ++] = '\b';break;
				case 'x' :
				case 'X' :p++;buf[buf_ptr ++] = next_number(&p, 16);p--;break;
				case '0' :p++;buf[buf_ptr ++] = next_number(&p, 8);p--;break;
				default  :buf[buf_ptr ++] = *p;break;
			}
	}
	buf[buf_ptr] = 0;
	return buf;
}

char* register_id(const char *text) {
	int len = strlen(text) + 1;
	char *buf = malloc(len);
	strcpy(buf, text);
	return buf;
}

int swallow_space() {
	int lexval = -1;
	do{lexval = next_token();}while(lexval == SPACE);
	return lexval;
}

int swallow_blank_and_newline() {
	int lexval = -1;
	do{lexval = next_token();}while(lexval == NEWLINE || lexval == SPACE);
	return lexval;
}

bool check_duparg_in_macro(macro_arg_t *arg, size_t len) {
	for(int i = 0; i < len; i++) {
		for(int j = i + 1; j < len; j++) {
			if(strcmp(arg[i].id, arg[j].id) == 0) {
				eprintf("dupplicate argument '%s' in macro.\n", arg[i].id);
				return true;
			}
		}
	}
	return false;
}

int find_arg_in_macro(macro_arg_t *argv, size_t len, char *id) {
	for(int i = 0; i < len; i++) {
		if(strcmp(argv[i].id, id) == 0) {
			return i;
		}
	}
	return -1;
}

vec_t macro_buffer;

int match_macro() {
	//FIXME:handle error state
	static int mmt[11][MacroTokenSize] = {
		     /*ID LP RP , ... id.## #  \n ' 'other EOF*/
		[0] = { 1,10,10,10,10,10,10,10,10, 0,10, 10},
		[1] = { 8, 2, 8, 8, 8, 8, 8, 8, 8, 1, 8,  9},
		[2] = { 3,10, 5,10, 4,10,10,10,10, 2,10, 10},
		[3] = {10,10, 5, 2, 4,10,10,10,10, 3,10, 10},
		[4] = {10,10, 5,10,10,10,10,10,10, 4,10, 10},
		[5] = { 8, 8, 8, 8, 8, 8, 8, 6, 8, 5, 8,  9},
		[6] = { 8,10,10,10,10,10,10,10,10, 6,10, 10},
		[7] = { 8, 8, 8, 8, 8, 8,10,10,10, 7, 8,  8},
		[8] = { 8, 8, 8, 8, 8, 8, 7, 6, 9, 8, 8,  9},
		[9] = {10,10,10,10,10,10,10,10,10, 9,10, 10},//acc
		[10]= {10,10,10,10,10,10,10,10,10,10,10, 10},//err
	};
	//register .. or args... in state 4
	//register id in state 5
	macro_t macro;
	size_t argc = 0, mtlen = 0;
	int cur_state = 0, last_state = 0, lexval = 0, last_mtt = -1;
	node_t *lastnd = NULL;
	macro_token_t *mt = NULL;
	macro_arg_t *argv = NULL;
	while(cur_state != 9 && cur_state != 10) {
		int tokval = 0;
		lexval = swallow_space();
		switch(lexval) {
			case ID:        tokval = MacroID;        break;
			case LP:        tokval = MacroLP;        break;
			case RP:        tokval = MacroRP;        break;
			case COMMA:     tokval = MacroCOMMA;     break;
			case ELLIPSIS:  tokval = MacroELLIPSIS;  break;
			case CONCAT:    tokval = MacroCONCAT;    break;
			case STRINGIFY: tokval = MacroSTRINGIFY; break;
			case NEWLINE:   tokval = MacroNEWLINE;   break;
			case SPACE:     tokval = MacroSPACE;     break;
			case 0://EOF
				tokval = MacroEOF;
				break;
			default:        tokval = MacroOther;     break;
		}

		cur_state = mmt[cur_state][tokval];
		logd("switch state: %d --> %d\n", last_state, cur_state);
		logd("triggered by %d, '%s'\n", tokval, lexval?yytext:"EOF");

		int index = 0, mtt = 0, cat_index = 0;
		switch(cur_state) {
		case 1:
			macro.id = yylval.pnd->cv.id;
			argv = get_memory_pointer();
			break;
		case 2:
			if(last_state == 3) {
				//ID
				argv[argc].token = MacroID;
				argv[argc].id = lastnd->cv.id;
				argc ++;
			}
			break;
		case 4:
			if(last_state == 2) {
				//...
				argv[argc].token = MacroELLIPSIS;
				argv[argc].id = lastnd->cv.id;
				argc ++;
			}else if(last_state == 3){
				//args...
				argv[argc].token = MacroIDELLIPSIS;
				argv[argc].id = lastnd->cv.id;
				argc ++;
			}else{
				logw("check here.\n");
			}
			break;
		case 5:
			if(last_state == 3) {
				//ID
				macro.bt = MacroFixedArgs;
				argv[argc].token = MacroID;
				argv[argc].id = lastnd->cv.id;
				argc ++;
			}
			argv = require_memory(sizeof(macro_arg_t) * argc);
			if(check_duparg_in_macro(argv, argc))
				cur_state = 10;//err
			else
				mt = get_memory_pointer();
			break;
		case 6:
			lexval = swallow_space();
			if(lexval != ID) {
				//err
				logd("lexval=%d, should be ID=%d\n", lexval, ID);
				cur_state = 10;
			}else{
				char *cur_id = yylval.pnd->cv.id;
				int index = find_arg_in_macro(argv, argc, cur_id);
				if(index == -1) {
					//err
					cur_state = 10;
					logd("fail to find arg '%s'\n", cur_id);
				}else{
					mt[mtlen].mtt = MacroTokenStringify;
					mt[mtlen].i = index;
					mt[mtlen].pnd = yylval.pnd;
					last_mtt = MacroTokenStringify;
					mtlen ++;
					cur_state = 8;
				}
			}
			break;
		case 7:
			mtt = 0;
			if(last_mtt == MacroTokenConcatTJ
			|| last_mtt == MacroTokenConcatIJ)
				cat_index = mtlen ++;
			else
				cat_index = mtlen - 1;
			if(lastnd->token == ID && (index = find_arg_in_macro(argv, argc, lastnd->cv.id)) != -1){
				//this is arg
				mtt = mtt | 0x2;
				mt[cat_index].i = index;
			}else{
				//common token
				mt[mtlen].mtt = MacroTokenCommon;
				mt[mtlen].pnd = lastnd;
				mtlen ++;
			}

			do{
				lexval = next_token();
			}while(lexval == SPACE || lexval == CONCAT);
			if(yylval.pnd->token == ID && (index = find_arg_in_macro(argv, argc, yylval.pnd->cv.id)) != -1){
				//this is arg
				mtt = mtt | 0x1;
				mt[cat_index].j = index;
			}else{
				mt[mtlen].mtt = MacroTokenCommon;
				mt[mtlen].pnd = yylval.pnd;
				mtlen ++;
			}
			mt[cat_index].mtt = mtt;
			last_mtt = mtt;
			cur_state = 8;
			break;
		case 8:
			//store all token
			if(last_state == 1){
				macro.bt = MacroNormal;
				require_memory(0);
				mt = get_memory_pointer();
				mt[mtlen].mtt = MacroTokenCommon;
				mt[mtlen].pnd = yylval.pnd;
				last_mtt = MacroTokenCommon;
				mtlen ++;
			}else if(last_state == 5 || last_state == 8){
				//store
				int index = 0;
				if(yylval.pnd->token == ID
				&& (index = find_arg_in_macro(argv, argc, yylval.pnd->cv.id)) != -1){
					mt[mtlen].mtt = MacroTokenArg;
					mt[mtlen].i = index;
					mt[mtlen].pnd = yylval.pnd;
					last_mtt = MacroTokenArg;
					mtlen ++;
				}else{
					mt[mtlen].mtt = MacroTokenCommon;
					mt[mtlen].pnd = yylval.pnd;
					last_mtt = MacroTokenCommon;
					mtlen ++;
				}
			}else if(last_state == 6){//do nothing
			}else if(last_state == 7){//do nothing
			}
			break;
		case 9:
			mt = require_memory(mtlen * sizeof(macro_token_t));
			//accept
			break;
		}

		last_state = cur_state;
		lastnd = yylval.pnd;
	}
	if(!bpool_state_close()) require_memory(0);

	if(cur_state == 10) {
		macro.bt = MacroBad;
		//TODO:report error reason
	}

	if(lexval == NEWLINE) swallow_blank_and_newline();

	macro.argc = argc;
	macro.argv = argv;
	macro.mtlen = mtlen;
	macro.mt = mt;
	vector_push(&macro_buffer, &macro);

	return lexval;
}

char *macro_format(macro_t *macro) {
	if(!macro) return NULL;
	//format arg
	char *token_format(node_t *);
	char *buf = get_memory_pointer();
	sprintf(buf, "#define %s(", macro->id);
	for(int i = 0; i < macro->argc; i++) {
		if(i != macro->argc - 1)
			sprintf(buf + strlen(buf), "%s, ", macro->argv[i].id);
		else
			sprintf(buf + strlen(buf), "%s", macro->argv[i].id);
	}
	sprintf(buf + strlen(buf), ") ");
	for(int i = 0; i < macro->mtlen; i++) {
		char *ss[] = {"TT", "TJ", "IT", "IJ", "", "s.", "@"};
		printf("%s", ss[macro->mt[i].mtt]);
		if(macro->mt[i].mtt == MacroTokenCommon)
			printf("%s ", token_format(macro->mt[i].pnd));
		else
			printf(" ");
	}
	printf("\n");
	for(int i = 0; i < macro->mtlen; i++) {
		//logw("i:%d, mtt:%d\n", i, macro->mt[i].mtt);
		//logw("%p\n", &macro->mt[i].mtt);
		if(macro->mt[i].mtt == MacroTokenArg) {
			sprintf(buf + strlen(buf), "@%d:%s ", macro->mt[i].i, token_format(macro->mt[i].pnd));
		}else if(macro->mt[i].mtt == MacroTokenStringify){
			sprintf(buf + strlen(buf), "#%d:%s ", macro->mt[i].i, token_format(macro->mt[i].pnd));
		}else if(macro->mt[i].mtt == MacroTokenConcatTT){
			if(i + 2 >= macro->mtlen || macro->mt[i + 2].mtt >= 4){
				sprintf(buf + strlen(buf), "%s ## %s ", token_format(macro->mt[i + 1].pnd), token_format(macro->mt[i + 2].pnd));
				i += 2;
			}else{
				sprintf(buf + strlen(buf), "%s ## ", token_format(macro->mt[i + 1].pnd));
				i ++;
			}
		}else if(macro->mt[i].mtt == MacroTokenConcatTJ){
			if(i + 2 >= macro->mtlen || macro->mt[i + 2].mtt >= 4){
				sprintf(buf + strlen(buf), "%s ## @%d:%s ",
					token_format(macro->mt[i + 1].pnd),
					macro->mt[i].j,
					macro->argv[macro->mt[i].j].id);
				i ++;
			}else{
				sprintf(buf + strlen(buf), "%s ## ",
					token_format(macro->mt[i + 1].pnd));
				i ++;
			}
		}else if(macro->mt[i].mtt == MacroTokenConcatIT){
			if(i + 1 >= macro->mtlen || macro->mt[i + 1].mtt >= 4){
				sprintf(buf + strlen(buf), "@%d:%s ## %s ",
					macro->mt[i].i, macro->argv[macro->mt[i].i].id,
					token_format(macro->mt[i + 1].pnd));
				i ++;
			}else{
				sprintf(buf + strlen(buf), "@%d:%s ## ",
					macro->mt[i].i, macro->argv[macro->mt[i].i].id);
			}
		}else if(macro->mt[i].mtt == MacroTokenConcatIJ){
			if(i + 1 >= macro->mtlen || macro->mt[i + 1].mtt >= 4){
				sprintf(buf + strlen(buf), "@%d:%s ## @%d:%s ",
					macro->mt[i].i, macro->argv[macro->mt[i].i].id,
					macro->mt[i].j, macro->argv[macro->mt[i].j].id);
			}else{
				sprintf(buf + strlen(buf), "@%d:%s ## ",
					macro->mt[i].i, macro->argv[macro->mt[i].i].id);
			}
		}else if(macro->mt[i].mtt == MacroTokenCommon){
			sprintf(buf + strlen(buf), "%s ", token_format(macro->mt[i].pnd));
		}else{
			logw("check it! mtt=%d\n", macro->mt[i].mtt);
		}
	}
	buf = require_memory(strlen(buf) + 1);
	return buf;
}

int yylex() {
	int lexval = swallow_blank_and_newline();
	switch(lexval) {
	case MACRO_DEFINE:
		lexval = match_macro();
		break;
	default:
		break;
	}
	return lexval;
}

void tokenize_from_string(const char *string) {
	void *buffer_state = yy_scan_string(string);
	yy_switch_to_buffer(buffer_state);
	while(yylex() > 0);
	yylex_destroy();
}

int init_lexical() {
	vector_init(&macro_buffer, sizeof(macro_t));
#ifdef __DEBUG__
	/* unit test of register_string */
	UNIT_TEST_START;
	
	struct {
		char *sample, *ans;
	}test_macro_string[] = {
		{"#define macro a e + - extern int * /",
			"#define macro() a e ADD SUB extern INT MULT DIV "},
		{"#define macro a b c \\\n d e\n",
			"#define macro() a b c d e "},
		{"#define macro() a b c \\\n d e\n",
			"#define macro() a b c d e "},
		{"#define macro() a b c \\/\n d e\n",
			"#define macro() a b c DIV "},
		{"#define macro(aa) aa vv dd \\/\n d e\n",
			"#define macro(aa) @0:aa vv dd DIV "},
		{"#define macro(aa) a vv dd \\/\n d e\n",
			"#define macro(aa) a vv dd DIV "},
		{"#define macro(aa,vv,dd) aa vv dd \\/\n d e\n",
			"#define macro(aa, vv, dd) @0:aa @1:vv @2:dd DIV "},
		{"#define macro(a,b,c) # a vv dd \\/",
			"#define macro(a, b, c) #0:a vv dd DIV "},
		{"#define macro(a,b,c) # a",
			"#define macro(a, b, c) #0:a "},
		{"#define macro(a,b,c) # a b ## c",
			"#define macro(a, b, c) #0:a @1:b ## @2:c "},
		{"#define macro(a,b) a##b",
			"#define macro(a, b) @0:a ## @1:b "},
		{"#define macro(a,b,c)  d## vv dd ",
			"#define macro(a, b, c) d ## vv dd "},
		{"#define macro(a,b,c)  a## vv dd ",
			"#define macro(a, b, c) @0:a ## vv dd "},
		{"#define macro(a,b,c)  vv## c dd ",
			"#define macro(a, b, c) vv ## @2:c dd "},
		{"#define macro(a,b,c)  a## c dd ",
			"#define macro(a, b, c) @0:a ## @2:c dd "},
		{"#define macro(a,b,c)  vv## vv##vv dd ",
			"#define macro(a, b, c) vv ## vv ## vv dd "},
		{"#define macro(a,b,c)  vv## vv##a dd ",
			"#define macro(a, b, c) vv ## vv ## @0:a dd "},
		{"#define macro(a,b,c)  vv## a##vv dd ",
			"#define macro(a, b, c) vv ## @0:a ## vv dd "},
		{"#define macro(a,b,c)  a## vv##vv dd ",
			"#define macro(a, b, c) @0:a ## vv ## vv dd "},
		{"#define macro(a,b,c)  a## b##vv dd ",
			"#define macro(a, b, c) @0:a ## @1:b ## vv dd "},
		{"#define macro(a,b,c)  vv ##a## b vv dd ",
			"#define macro(a, b, c) vv ## @0:a ## @1:b vv dd "},
		{"#define macro(a,b,c)  c ##a## b vv dd ",
			"#define macro(a, b, c) @2:c ## @0:a ## @1:b vv dd "},
		{"#define macro(a,b,c)  vv ##vv## a## vv##b##c##as##q vv dd ",
			"#define macro(a, b, c) vv ## vv ## @0:a ## vv ## @1:b ## @2:c ## as ## q vv dd "},
		{"#define macro(a,b,c)  vv ##a## b## vv dd ",
			"#define macro(a, b, c) vv ## @0:a ## @1:b ## vv dd "},
		{"#define macro(a,b,c)  vv #### b## vv dd ",
			"#define macro(a, b, c) vv ## @1:b ## vv dd "},
	};

	for(int i = 0; i < sizeof(test_macro_string)/sizeof(test_macro_string[0]); i++) {
		tokenize_from_string(test_macro_string[i].sample);
		macro_t *pma = vector_top(&macro_buffer);
		UNIT_TEST_STR_EQUAL(macro_format(pma), test_macro_string[i].ans);
	}


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
