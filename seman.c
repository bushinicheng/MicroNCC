#include "common.h"

bool is_syntax_error = false;
bool is_print_inter_code = false;
int last_syntax_error;

typedef struct tagVarElement {
	char *vn;
	Spec *type;//type system
	Node *node;//position
	VarAddr *va;//variale address, maybe :(
} VarElement;

static int asptr, actionlevel;
VarElement actionscope[102400];//action scope of variable


