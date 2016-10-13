#include <stdio.h>
#include <stdarg.h>
#include "error.h"

int loge(int lineno, int column, enum ErrorType errno, const char *yylinetext)
{
	printf("%d:%d: error:%s\n", lineno, column, ErrorReason[errno]);
	printf("%s\n", yylinetext);
	for(int i = 1; i < column; i++)
		printf(" ");
	printf("^\n");
	return 0;
}

int yyerror(const char *str)
{
	printf("%s\n", str);
	return 0;
}
