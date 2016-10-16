#include <stdio.h>
#include <stdarg.h>

#define __YYLOG_C__
#include "error.h"

int yyerrlex(int lineno, int column, int tokenlen, enum ErrorType errortype, const char *yylinetext)
{
	printf("%d:%d: error:%s\n", lineno, column, ErrorReason[errortype]);
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

/*for compatibility*/
int yyerror(const char *format, ...)
{
	va_list arg;
	int done;
	va_start(arg, format);
	done = vfprintf(stderr, format, arg);
	fprintf(stderr, "\n");
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
