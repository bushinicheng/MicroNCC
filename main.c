#include <stdio.h>
#include <string.h>
#include "basic-dat.h"
#include "ast.h"

int yyparse();
int init_ast();
int init_component();
void print_ast(Node*);
extern Node *astroot;

int main(int argc, char *argv[])
{
	init_ast();
	init_component();
#ifdef __DEBUG_LEX__
	while(yylex()>0);
#else
	yyparse();
	for(int i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "--print-ast") == 0)
			print_ast(astroot);
	}
#endif
    return 0;
}
