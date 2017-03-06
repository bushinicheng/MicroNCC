#ifndef OPT_H
#define OPT_H

enum {
	ArgumentPrintSyntaxTree,
	ArgumentPrintReduceStep,
/* declare your own opt here
 */
	ArgumentHelp,
};

bool get_onoff_from_arguments(int arg);
char *get_value_from_arguments(int arg);

#endif
