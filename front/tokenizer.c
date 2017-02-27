#include <stdio.h>

//int (*yylex = NULL)();

/* TODO: design a tokenizer
 *   1. switch_buffer  ==>  included header file
 *   2. restart  ==>  after the end of buffer
 *   3. reset_state  ==>  free memory, reset global variable
 *   4. handle different types of buffer:
 *      such as file, string in memory, or stdin
 *
 */


struct {
	FILE *fp;
	char *str;
} wt_buffer;
