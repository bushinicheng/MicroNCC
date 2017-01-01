#include "common.h"

bool is_syntax_error = false;

typedef struct tagVarElement {
	char *varname;
	Spec *type;
	Node *node;
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
				printf(dupformat, sa);
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
		if(strcmp(varname, actionscope[i].varname) == 0)
			return true;
		i --;
	}

	return false;
}

VarElement *find_variable(char *varname) {
	for(int i = asptr - 1; i >= 0; i--) {
		if(strcmp(varname, actionscope[i].varname) == 0)
			return &actionscope[i];
	}

	return NULL;
}


/* function:
 *   split the action scope
 */
void push_barrier() {
	actionscope[asptr].varname = NULL;
	actionscope[asptr].type = NULL;
	actionlevel ++;
}


/*
 * function:
 *   register a variable in actionscope array
 */
void push_variable(char *varname, Spec *type) {
	assert(varname != NULL && type != NULL);
	find_duplication(varname);
	actionscope[asptr].varname = varname;
	actionscope[asptr].type = type;
	asptr ++;
}


/*
 * function:
 *   clear current scope
 */
void pop_scope() {
	if(asptr > 0) asptr --;
	if(actionlevel > 0) actionlevel --;
	while(asptr > 0 && actionscope[asptr].varname != NULL) {
		asptr --;
	}
}

int analyse_expression(Node *root) {
	if(root == NULL) return 0;
}

int analyse_statement(Node *root) {
	if(root == NULL) return 0;
}

int analyse_function(Node *root, Spec *functype) {
	if(root == NULL) return 0;
	assert(root->reduce_rule = AST_Block_is_Specifier_FuncDec_CompSt);

	push_barrier();
}

int analyse_vardef(Node *root) {
	if(root == NULL) return 0;
	assert(root->token = VarDef);
	Spec *type = find_type_of_spec(root->child);
	Node *declist = root->child->sibling;
	while(1) {
		Node *vardec = declist->child->child;
		Spec *type = register_type_complex_var(vardec, NULL);
		while(vardec->child->token != ID) {
			if(vardec->reduce_rule == AST_VarDec_is_MULT_VarDec)
				vardec = vardec->child->sibling;
			else if(vardec->reduce_rule == AST_VarDec_is_VarDec_LB_NUM_RB)
				vardec = vardec->child;
		}
		push_variable(vardec->child->supval.st, type);
		if(declist->child->sibling)
			declist = declist->child->sibling->sibling;
		else
			break;
	}
	return 0;
}

int semantic_analysis(Node *root)
{
	if(root == NULL)
		return 0;

	assert(root->token == Program);
	Node *blocklist = root->child;

	//block reduce
	while(blocklist != NULL) {
		Spec *type = NULL;
		Node *idlist = NULL;
		Node *block = blocklist->child;
		switch(block->reduce_rule) {
			case AST_Block_is_Specifier_FuncDec_CompSt:
				type = register_type_function(block->child->sibling);
				push_variable(block->child->sibling->child->supval.st, type);
				analyse_function(block, type);
				break;
			case AST_Block_is_StructDec_IdList_SEMI:
				type = register_type_struct(block->child);
				idlist = block->child->sibling;
				while(1) {
					push_variable(idlist->child->supval.st, type);
					if(!idlist->child->sibling) break;
					else idlist = idlist->child->sibling->sibling;
				}
				break;
			case AST_Block_is_StructDec_SEMI:
				register_type_struct(block->child);
				break;
			case AST_Block_is_VarDef:
				analyse_vardef(root->child);
				break;
		}

		if(block->child->sibling)
			blocklist = block->child->sibling;
		else
			break;
	}

	return 0;
}

void init_seman()
{
	asptr = 0;
	actionlevel = 0;
}
