#ifndef __OPT_H__
#define __OPT_H__

enum {
	ArgumentPrintSyntaxTree,
	ArgumentPrintReduceStep,
/* declare your own opt here
 */
};

bool get_onoff_from_arguments(int arg);
char *get_value_from_arguments(int arg);

#endif
