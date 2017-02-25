#ifndef __OPT_H__
#define __OPT_H__

/* declare your own opt here
 */
enum {
	ArgumentPrintSyntaxTree,
	ArgumentPrintReduceStep,
};

bool get_onoff_from_arguments(int arg);
char *get_value_from_arguments(int arg);

#endif
