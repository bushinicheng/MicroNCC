#ifndef __ERROR_H__
#define __ERROR_H__

enum ErrorType {
	ERR_INVALID_NUM,
	ERR_INVALID_OCT,
	ERR_INVALID_HEX,
	ERR_INVALID_DEC,
	ERR_UNKNOWN_TOKEN,
	ERR_NULL_DECLARATION,
	ERR_EXPECTED_COMMA,
	ERR_EXPECTED_SEMI,
	ERR_EXPECTED_STATEMENT,
	ERR_MISSING_SEMI,
	ERR_MISSING_RC,
	ERR_MISSING_RB,
};

#ifdef __YYLOG_C__

static const char *ErrorReason[] = {
	[ERR_INVALID_NUM] = "error type A: invalid number.",
	[ERR_INVALID_OCT] = "error type A: invalid oct number.",
	[ERR_INVALID_HEX] = "error type A: invalid hex number.",
	[ERR_UNKNOWN_TOKEN] = "error type A: invalid character.",
	[ERR_NULL_DECLARATION] = "warning: declaration does not declare anything.",
	[ERR_EXPECTED_COMMA] = "expected ',' here.",
	[ERR_EXPECTED_SEMI] = "expected ';' here.",
	[ERR_EXPECTED_STATEMENT] = "error type B: expected definition or statement here.",
	[ERR_MISSING_SEMI] = "error type B: missing ';'",
	[ERR_MISSING_RC] = "error type B: missing '}'",
	[ERR_MISSING_RB] = "error type B: missing ']'",
};

#endif

int yydebug(int, int, int, enum ErrorType);
int yyerr(const char *, ...);
int yyerror(const char *, ...);
int yylog(FILE *fp, const char *tag, const char *, ...);

/*output style*/
#define YYLOG_STYLE_NORMAL    "0"
#define YYLOG_STYLE_BOLD      "1"
#define YYLOG_STYLE_DARK      "2"
#define YYLOG_STYLE_BACK      "3"
#define YYLOG_STYLE_UNDERLINE "4"

/*output color*/
#define YYLOG_COLOR_BLACK    "30"
#define YYLOG_COLOR_RED      "31"
#define YYLOG_COLOR_GREEN    "32"
#define YYLOG_COLOR_YELLOW   "33"
#define YYLOG_COLOR_BLUE     "34"
#define YYLOG_COLOR_PURPLE   "35"
#define YYLOG_COLOR_SKYBLUE  "36"
#define YYLOG_COLOR_WHITE    "37"
#define YYLOG_COLOR_NORMAL   "38"

#define logf(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_BACK ";" YYLOG_COLOR_YELLOW "m", __VA_ARGS__)

#define loge(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_BOLD ";" YYLOG_COLOR_RED "m", __VA_ARGS__)

#define logw(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m", __VA_ARGS__)

#define logi(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_WHITE "m", __VA_ARGS__)

//#ifdef __DEBUG__
#define logd(...) \
	yylog(stderr, "\033[0m", __VA_ARGS__)
//#else
//#define logd(...) do{}while(0)
//#endif

#define logG(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_GREEN "m", __VA_ARGS__)

#endif
