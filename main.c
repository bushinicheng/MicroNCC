#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "common.h"
#include "ast.h"

int yyparse();
int init_ast();
int init_spec();
int init_component();
int init_vector();
void print_ast(Node*);
void yyrestart(FILE *);
extern Node *astroot;

/*global onoff*/
bool is_print_ast = false;
bool is_print_reduce_step = false;
bool is_file = false;

int main(int argc, char *argv[])
{
	init_ast();
	init_component();
	init_vector();
	init_spec();
	char ch;
	FILE *fp = NULL;

#ifdef __DEBUG_LEX__
	logd("[LOG]: enter debug mode, while(yylex())\n");
	while(yylex()>0);
#else

	logd("[LOG]: parse arguments.\n");
	for(int i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "--print-ast") == 0)
			is_print_ast=true;
		else if(strcmp(argv[i], "--print-reduce") == 0)
			is_print_reduce_step=true;
		else if(!is_file)
		{
			fp=fopen(argv[i], "rb");
			if(fp != NULL)
			{
				yyrestart(fp);
				is_file=true;
			}
		}
	}
	/*grammer:shift and reduce*/

#if YYDEBUG == 1
	yydebug = 1;
#endif
	logd("[LOG]: call yyparse.\n");
	yyparse();
	logd("[LOG]: call print_ast.\n");
	if(is_print_ast) print_ast(astroot);
	if(fp) fclose(fp);
#endif
	logd("[LOG]: normal exit.\n");
    return 0;
}
