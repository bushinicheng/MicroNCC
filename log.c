#include <stdio.h>
#include <stdarg.h>
#include "error.h"

int loge(int lineno, int column, ErrorType errno, const char *yyline)
{
	printf("%d:%d: error:%s\n", filename, lineno, column, ErrorReson[error]);
	printf("%s\n", yyline);
	for(int i = 1; i < column; i++)
		printf(" ");
	printf("^\n");
	return 0;
}
