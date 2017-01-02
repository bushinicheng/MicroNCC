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
		if(strcmp(varname, actionscope[i].varname) == 0)
			return true;
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
	for(int i = asptr - 1; i >= 0; i--) {
		if(strcmp(varname, actionscope[i].varname) == 0)
			return &actionscope[i];
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
}


/*
 * function:
 *   register a variable in actionscope array
 *   TODO: caculate base_addr and base_type for each id
 */
void push_variable(Node *vardec, char *varname, Spec *type) {
	assert(varname != NULL && type != NULL);
	find_duplication(varname);

	//calculate base
	vardec->var_size = vardec->idtype->width;
	if(actionscope[asptr].node)
		vardec->base_addr = actionscope[asptr].node->base_addr + actionscope[asptr].node->var_size;
	else
		vardec->base_addr = 0;

	//decide base type
	if(actionlevel > 0) {
		vardec->base_type = 2;
	} else if(actionlevel == 0) {
		vardec->base_type = 1;
	} else {
		logw("actionlevel = %d < 0\n", actionlevel);
	}

	//push variable
	actionscope[asptr].varname = varname;
	actionscope[asptr].node = vardec;
	actionscope[asptr].type = type;
	asptr ++;

	//check dup
	if(find_duplication(varname)) {
		yyerrtype(ErrorRedefinition, vardec->lineno, varname);
		is_syntax_error = true;
	}
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

/*-------------------------*/


void check_function_call(Node *root, VarElement *func) {
	if(!root || !func) return;
	assert(root->reduce_rule == AST_Exp_is_ID_LP_RP
		|| root->reduce_rule == AST_Exp_is_ID_LP_FuncCallArgList_RP);
	if(func->type->btype != SpecTypeFunc) {
		yyerrtype(ErrorNotCallable, root->lineno, root->child->supval.st);
	}else if(func->type->type.func.argv == 0) {
		if(root->reduce_rule != AST_Exp_is_ID_LP_RP) {
			yyerrtype(ErrorCall0vx, root->lineno);
		}
	}else{
		if(root->reduce_rule != AST_Exp_is_ID_LP_FuncCallArgList_RP) {
			yyerrtype(ErrorCallnv0, root->lineno, func->type->type.func.argv);
		} else {
			Node *arglist = get_child_node(root, FuncCallArgList);
			for(int i = 0; i < func->type->type.func.argv; i++) {
				

				if(!arglist->child->sibling) {
				} else {
					arglist = arglist->child->sibling->sibling;
				}
			}
			
			if(arglist->child->sibling) {
			}
		}
	}
}

/*
 *
 *-------------------------------------------------
 *
 */

void register_idlist(Node *root, Spec *type) {
	if(!root) return;
	assert(root->token == IdList);
	
	Node *idlist = root;
	while(1) {
		char *varname = NULL;
		Spec *newtype = register_complex_var_with_type(type, idlist->child, &varname);
		push_variable(idlist->child, varname, newtype);

		if(idlist->child->sibling)
			idlist = idlist->child->sibling->sibling;
		else
			break;
	}
}


int analyse_expression(Node *root) {
	if(root == NULL) return 0;
	assert(root->token == Exp);

	VarElement *var;
	Node *id, *num, *op;

	switch(root->reduce_rule) {
		case AST_Exp_is_ID:
			id = root->child;
			var = find_variable(root, id->supval.st);
			if(var)	root->idtype = var->type;
			break;
		case AST_Exp_is_ID_LP_RP:
			id = root->child;
			var = find_variable(root, id->supval.st);
			if(var)	root->idtype = var->type->type.func.ret;
			check_function_call(root, var);
			//check args type
			break;
		case AST_Exp_is_ID_LP_FuncCallArgList_RP:
			id = root->child;
			var = find_variable(root, id->supval.st);
			if(var)	root->idtype = var->type->type.func.ret;
			check_function_call(root, var);
			//check args type
			break;
	}
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
		char *varname = NULL;
		Node *vardec = declist->child->child;
		Spec *type = register_type_complex_var(vardec, &varname);
		//push and check
		push_variable(declist->child->child, varname, type);
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
				push_variable(block, block->child->sibling->child->supval.st, type);
				analyse_function(block, type);
				break;
			case AST_Block_is_StructDec_IdList_SEMI:
				type = register_type_struct(block->child);
				idlist = block->child->sibling;
				register_idlist(idlist, type);
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
