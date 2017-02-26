#include "front-com.h"

int yylex();
int yyparse();
int init_ast();
int init_spec();
int init_seman();
int init_lexical();
void print_ast(Node *);
void yyrestart(FILE *);
int semantic_analysis(void *root);

FILE *fp = NULL;
extern void *astroot;
/*global onoff*/
bool is_print_ast = false;
bool is_print_reduce_step = false;
bool is_file = false;

void init_front_global_variables() {
	if(get_onoff_from_arguments(ArgumentPrintSyntaxTree))
		is_print_ast = true;
	if(get_onoff_from_arguments(ArgumentPrintReduceStep))
		is_print_reduce_step = true;
}

int init_front() {
	/* init some global variables */
	init_front_global_variables();

	/*init lexical file*/
	init_lexical();

	/*init syntax tree module*/
	init_ast();

	/*init type system*/
	init_spec();

	/*init semantic module*/
	init_seman();

#ifdef __DEBUG_LEX__
	logd("enter debug mode, while(yylex()>0)\n");
	yyrestart(fp);
	while(yylex()>0);
#else
	/* grammer:shift and reduce
	 * yyrestart will be replaced by custom parser
	 * */
	logd("call yyrestart(fp=%p).\n", fp);
	yyrestart(fp);
	logd("call yyparse(void).\n");
	yyparse();
	logd("call print_ast(astroot=%p), is_print_ast=%d.\n", astroot, is_print_ast);
	if(is_print_ast) print_ast(astroot);
	if(fp && fp != stdin) fclose(fp);
#endif
}
