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

int yydebug(int, int, int, enum ErrorType);
int yyerr(const char *, ...);
int yyerror(const char *, ...);
int yylog(FILE *fp, const char *tag, const char *, ...);

#endif
