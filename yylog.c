#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

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

int yydebug(int lineno, int column, int tokenlen, enum ErrorType errortype)
{
	extern char yylinetext[1024];
	printf("%d:%d: %s\n", lineno, column, ErrorReason[errortype]);
	printf("%s\n", yylinetext);
	for(int i = 0; i < column-1; i++)
	{
		if(yylinetext[i]=='\t')
			printf("\t");
		else
			printf(" ");
	}
	for(int i = 0; i < tokenlen; i++)
		printf("^");
	printf("\n");
	return 0;
}

int yyerr(const char *format, ...)
{
	int done;
	va_list arg;
	extern int curlineno;
	va_start(arg, format);
	done = vfprintf(stderr, format, arg);
	va_end(arg);
	return done;
}

/*for compatibility*/
int yyerror(const char *format, ...)
{
	int done;
	va_list arg;
	extern int curlineno;
	va_start(arg, format);
	logd("%d: error type B: ", curlineno);
	done = vfprintf(stderr, format, arg);
	logd("\n");
	va_end (arg);
	return done;
}

int yylog(FILE *fp, const char *tag, const char *format, ...)
{
	va_list arg;
	int done;
	
	va_start(arg, format);
	fprintf(fp, "%s", tag);
	done = vfprintf(fp, format, arg);
	fprintf(fp, "\033[0m");
	va_end (arg);
	
	return done;
}

int __attribute__((noinline)) set_break(){return 0;}
