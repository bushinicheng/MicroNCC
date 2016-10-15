#include <stdio.h>
#include <stdarg.h>
#include "error.h"

int yyerrlex(int lineno, int column, int tokenlen, enum ErrorType errno, const char *yylinetext)
{
	printf("%d:%d: error:%s\n", lineno, column, ErrorReason[errno]);
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

int __attribute__((noinline)) set_break(){return 0;}
