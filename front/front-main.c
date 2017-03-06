#include "front-com.h"

int semantic_analysis(void *root);
void print_ast(node_t *), yyrestart(FILE *);
int yyparse(), init_ast(), init_spec(), init_seman(), init_lexical();

/*global declaration*/
FILE *fp = NULL;
extern node_t *astroot;

/*global onoff*/
bool is_print_ast = false;
bool is_print_reduce_step = false;
bool is_file = false;

void init_front_global_variables() {
	extern vec_t cmd_files;
	if(get_onoff_from_arguments(ArgumentPrintSyntaxTree))
		is_print_ast = true;
	if(get_onoff_from_arguments(ArgumentPrintReduceStep))
		is_print_reduce_step = true;
	char **files = vector_ptr(&cmd_files);
	if(vector_size(&cmd_files) == 0)
		loge("no input files.\n");
	else if(vector_size(&cmd_files) > 1)
		loge("unable to handle more than one files.\n");
	logd("load file '%s'\n", files[0]);
	fp = fopen(files[0], "r");
	if(!fp)
		loge("fail to open file '%s'.\n", files[0]);
}

int init_front() {
	/* init some global variables */
	init_front_global_variables();

	/*init syntax tree module*/
	init_ast();

	/*init type system*/
	init_spec();

	/*init lexical file*/
	init_lexical();

	/*init semantic module*/
	init_seman();

	/*restart parser*/
	yyrestart(fp);

	/*lalr*/
	yyparse();

	/*print ast structure*/
	if(is_print_ast)
		print_ast(astroot);

	/*close file descriptor*/
	fclose(fp);

	return 0;
}
