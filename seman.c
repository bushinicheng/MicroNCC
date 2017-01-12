#include "common.h"

bool is_syntax_error = false;
int last_syntax_error;

typedef struct tagVarElement {
	char *varname;
	Spec *type;
	Node *node;
	int citcount;
} VarElement;

static int asptr, actionlevel;
VarElement actionscope[102400];//action scope of variable


/* IN[0]: char *
 *   specify the output string, assume
 *   duplicate element as given parameter
 * IN[1]: void *
 *   set of struct contains id
 * IN[2]: size_t
 *   the length of set
 * IN[3]: size_t
 *   size of a single element
 * IN[4]: off_t
 *   offset of id in a single element
 * OUT[0]:bool
 *   true if duplicate, else false
 */
bool check_dupset(char *dupformat, void *set, size_t len, size_t unitsize, off_t off) {
	//assume ith id: ((char**)(set + i * unitsize + off))[0]
	
	for(int i = 0; i < len; i++) {
		char *sa = ((char**)(set + i * unitsize + off))[0];
		for(int j = 0; j < i; j++) {
			char *sb = ((char**)(set + j * unitsize + off))[0];
			if(strcmp(sa, sb) == 0) {
				yyerr(dupformat, sa);
				is_syntax_error = 1;
			}
		}
	}
	return true;
}


/* IN[0]:  char *
 *   variable name
 * OUT[0]: bool
 *   true if duplicate, else false
 * function:
 *   check the duplication of current action scope
 */
bool find_duplication(char *varname) {
	int i = asptr - 1;
	while(i >= 0 && actionscope[i].varname != NULL) {
		if(strcmp(varname, actionscope[i].varname) == 0) {
			return true;
		}
		i --;
	}
	return false;
}


/*
 * function:
 *   ...
 * assume each query is meaningful :)
 */
VarElement *find_variable(Node *node, char *varname) {
	wt_assert(node && varname);
	if(asptr <= 0) return NULL;
	for(int i = asptr - 1; i>=0; i--) {
		if(actionscope[i].varname) {
			if(strcmp(varname, actionscope[i].varname) == 0) {
				actionscope[i].citcount ++;
				return &actionscope[i];
			}
		}
	}

	//not found
	yyerrtype(ErrorUndeclaredIdentifier, node->lineno, varname);
	is_syntax_error = true;
	return NULL;
}


/* function:
 *   split the action scope
 */
void push_barrier() {
	actionscope[asptr].varname = NULL;
	actionscope[asptr].type = NULL;
	actionlevel ++;
	asptr ++;
}


/*
 * function:
 *   register a variable in actionscope array
 *   TODO: alloc register for active variable
 */
void push_variable(Node *node, char *varname, Spec *type) {
	wt_assert(node && varname && type);
	find_duplication(varname);

	//calculate base
	if(node->idtype)
		node->var_size = node->idtype->width;
	if(actionscope[asptr].node)
		node->base_addr = actionscope[asptr].node->base_addr + actionscope[asptr].node->var_size;
	else
		node->base_addr = 0;

	//decide base type
	if(actionlevel > 0) {
		node->base_type = 2;//global
	} else if(actionlevel == 0) {
		node->base_type = 1;//local stack
	} else {
		logw("actionlevel = %d < 0\n", actionlevel);
	}


	//check duplication
	if(find_duplication(varname)) {
		yyerrtype(ErrorRedefinition, node->lineno, varname);
		is_syntax_error = true;
	}

	//push variable
	actionscope[asptr].varname = varname;
	actionscope[asptr].node = node;
	actionscope[asptr].type = type;
	actionscope[asptr].citcount = 1;
	asptr ++;
}


/*
 * function:
 *   clear current scope
 */
void pop_scope() {
	if(asptr > 0) asptr --;
	if(actionlevel > 0) actionlevel --;
	while(asptr > 0){
	   	if(actionscope[asptr].varname != NULL)
			asptr --;
		else
			break;
	}
}


int semantic_analysis(Node *root)
{
	if(root == NULL)
		return 0;

	wt_assert(root->token == Program);
}


int reset_seman_state() {
	void reset_spec_state(); 
	asptr = 0; 
	is_syntax_error = false; 
	last_syntax_error = 0; 
	actionlevel = 0; 
	reset_spec_state(); 
}

void init_seman() {
	reset_seman_state();
}
