#define __AST_C__
#include "front-com.h"

#define MAX_SIZE (1024*1024*2)

int curlineno;
static mem_pool_t ndpool;
node_t *astroot = NULL;

extern bool is_print_reduce_step;

void decrease_actionlevel();

void __attribute__((noinline)) make_node(node_t *root, int production, int token, ...) {
	va_list vlist;
	va_start(vlist, token);

	root->production = production;
	root->token = token;

	node_t *first_child = va_arg(vlist, node_t*);
	node_t *prev_child = first_child;

	if(token == AST_NONTERMINALBEGIN) {
		root->parent = NULL;
		root->child = NULL;
		root->sibling = NULL;
	}

	/*debug info*/
	for(int i = 1; i < syntax_rules[production].nr_child; i++)
	{
		node_t *post_child = va_arg(vlist, node_t*);
		prev_child->sibling = post_child;
		prev_child->parent = root;
		prev_child = post_child;
	}

	if(!syntax_rules[production].nr_child)
		first_child = NULL;
	else {
		prev_child->sibling = NULL;
		prev_child->parent = root;
	}
	root->child = first_child;
	va_end(vlist);
}

node_t* new_node() {
	return (node_t*)mempool_new(&ndpool);
}

node_t* new_sym_node(int lexval, YYLTYPE *yyinfo) {
	node_t *pnd = new_node();
	pnd->token = lexval;
	pnd->lineno = yyinfo->first_line;
	pnd->column = yyinfo->last_column;
	return pnd;
}

node_t* __attribute__((noinline)) build_subast(int nodetype, YYLTYPE *yyinfo, ...) {
	if(is_print_reduce_step)
		printf("%s\n", syntax_rules[nodetype].str_rule);

	va_list vlist;
	va_start(vlist, yyinfo);
	node_t *parent_node = new_node();
	node_t *first_child = va_arg(vlist, node_t*);
	node_t *prev_child = first_child;

	/*debug info*/
	parent_node->production = nodetype;
	parent_node->token = syntax_rules[nodetype].root_type;
	parent_node->lineno = curlineno = yyinfo->first_line;
	parent_node->column = yyinfo->first_column;

	for(int i = 1; i < syntax_rules[nodetype].nr_child; i++) {
		node_t *post_child = va_arg(vlist, node_t*);
		prev_child->sibling = post_child;
		prev_child->parent = parent_node;
		prev_child = post_child;
	}

	if(!syntax_rules[nodetype].nr_child)
		first_child = NULL;
	else {
		prev_child->sibling = NULL;
		prev_child->parent = parent_node;
	}
	parent_node->child = first_child;
	va_end(vlist);
	syntax_analysis(parent_node);
	if(get_child_node(parent_node, RC))
		decrease_actionlevel();
	return parent_node;
}

/*some function for searching child node*/
node_t* get_child_node_with_skip(node_t *root, int token, int skip) {
	if(skip < 0) return NULL;
	if(!root) return NULL;
	node_t *child = root->child;
	while(child) {
		if(child->token == token) {
			if(skip == 0)
				return child;
			else
				skip --;
		}
		child = child->sibling;
	}
	return NULL;
}

node_t* get_child_node(node_t *root, int token) {
	return get_child_node_with_skip(root, token, 0);
}

node_t* get_child_node_with_skip_w(node_t *root, int token, int skip) {
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	node_t *ret = get_child_node_with_skip(root, token, skip);
	if(!ret)
		logw("unsucessful search:{'root':'%s', 'child':'%s', 'rule':'%s'}\n", str_lexval[root->token], str_lexval[token], syntax_rules[root->production].str_rule);
	return ret;
}

node_t* get_child_node_w(node_t *root, int token) {
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	node_t *ret = get_child_node(root, token);
	if(!ret) {
		logw("unsucessful search:{'root':'%s', 'child':'%s', 'rule':'%s'}\n", str_lexval[root->token], str_lexval[token], syntax_rules[root->production].str_rule);
	}
	return ret;
}

node_t* __attribute__((noinline))get_child_node_dw(node_t *root, int depth, ...) {
	va_list vlist;
	va_start(vlist, depth);
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	for(int i = 0; root && i < depth; i++) {
		int token = va_arg(vlist, int);
		root = get_child_node_w(root, token);
	}
	va_end(vlist);
	return root;
}

node_t* find_child_node(node_t *root, int token) {
	if(!root) return NULL;
	if(root->token == token) return root;

	node_t *node = NULL;
	node = find_child_node(root->child, token);
	if(!node)
		return find_child_node(root->sibling, token);
	return node;
}

node_t* find_child_node_w(node_t *root, int token) {
	node_t *ret = find_child_node(root, token);
	if(!ret)
		logw("Unsuccessful search:{root:%s, target:%s}\n", str_lexval[root->token], str_lexval[token]);
	return ret;
}

char *token_format(node_t *node) {
	if(node->token == TYPE) {
		return str_lexval[node->production];
	}else if(node->token == TypeQulfr) {
		switch(node->cv.ex) {
			case QulfrTypedef: return "typedef";
			case QulfrExtern:  return "extern";
			case QulfrStatic:  return "static";
			case QulfrAuto:    return "auto";
			case QulfrRegister:return "register";
			case QulfrConst:   return "const";
			case QulfrVolatile:return "volatile";
			default:return NULL;
		}
	}else if(node->token == NUM){
		return node->cv.str;
	}else if(node->token == LITERAL){
		return node->cv.str;
	}else if(node->token == STRING){
		return node->cv.str;
	}else if(node->token == ID){
		return node->cv.id;
	}else{
		return str_lexval[node->token];
	}
}

void print_ast(node_t *root) {
	if(root == NULL)
		return;

	static int call_depth = 0;
	static int tree_depth = 0;
	static int *stack = NULL;

	if(call_depth == 0)
		stack = get_memory_pointer();

	//inc call_depth
	call_depth ++;

	/* print leading space */
	for(int i = 0; i < tree_depth - 1; i++) {
		if(stack[i+1])
			printf("|  ");
		else
			printf("   ");
	}
	if(tree_depth > 0) printf("+--");

	/* print semanval or lexval */
	if(root->token == ID)
		printf("ID:%s", root->cv.id);
	else if(root->token == NUM) {
		switch(root->cv.t) {
			case 'i':
				printf("NUM:%d", root->cv.i);
				break;
			case 'o':
				printf("NUM:0%o", root->cv.i);
				break;
			case 'x':
				printf("NUM:0x%x", root->cv.i);
				break;
			case 'f':
				printf("NUM:%f", root->cv.f);
				break;
			default:
				printf("NUM:0");
				break;
		}
	}
	else if(root->token == TYPE)
		printf("TYPE:%s", str_lexval[root->production]);
	else if(root->token == TypeQulfr)
		printf("Qulfr:%s", str_lexval[root->production]);
	else
		printf("%s", str_lexval[root->token]);
#if 0
	if(root->dt){
		printf(" {type:");
		print_type(root->dt);
		printf(", width:%d}", root->dt->width);
	}
#endif
	printf("\n");


	/* recursively print ast */
	stack[tree_depth] = !!root->sibling;
	tree_depth ++;	print_ast(root->child);	tree_depth --;
	stack[tree_depth] = 0;
	print_ast(root->sibling);

	//dec call_depth
	call_depth --;
	if(call_depth == 0) require_memory(0);
}

int init_ast() {
	mempool_init(&ndpool, sizeof(node_t));
	return 0;
}
