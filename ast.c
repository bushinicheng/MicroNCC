#define __AST_C__
#include "common.h"
#include "vector.h"

#define MAX_SIZE (1024*1024*2)

int curlineno;
static MemPool ndpool;
Node *astroot = NULL;

extern bool is_print_reduce_step;

void __attribute__((noinline)) make_node(Node *root, int reduce_rule, int token, ...)
{
	va_list vlist;
	va_start(vlist, token);

	root->reduce_rule = reduce_rule;
	root->token = token;

	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;

	if(token == AST_NONTERMINALBEGIN) {
		root->parent = NULL;
		root->child = NULL;
		root->sibling = NULL;
	}

	/*debug info*/
	for(int i = 1; i < syntax_rules[reduce_rule].nr_child; i++)
	{
		Node *post_child = va_arg(vlist, PNode);
		prev_child->sibling = post_child;
		prev_child->parent = root;
		prev_child = post_child;
	}

	if(!syntax_rules[reduce_rule].nr_child)
		first_child = NULL;
	else {
		prev_child->sibling = NULL;
		prev_child->parent = root;
	}
	root->child = first_child;
	va_end(vlist);
}

Node* new_node()
{
	return (Node*)mempool_new(&ndpool);
}

Node* new_sym_node(int lexval, YYLTYPE *yyinfo)
{
	Node *pnd = new_node();
	pnd->token = lexval;
	pnd->lineno = yyinfo->first_line;
	pnd->column = yyinfo->last_column;
	return pnd;
}

Node* __attribute__((noinline)) build_subast(int nodetype, YYLTYPE *yyinfo, ...)
{
	if(is_print_reduce_step)
		printf("%s\n", syntax_rules[nodetype].str_rule);

	va_list vlist;
	va_start(vlist, yyinfo);
	Node *parent_node = new_node();
	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;

	/*debug info*/
	parent_node->reduce_rule = nodetype;
	parent_node->token = syntax_rules[nodetype].root_type;
	parent_node->lineno = curlineno = yyinfo->first_line;
	parent_node->column = yyinfo->first_column;

	for(int i = 1; i < syntax_rules[nodetype].nr_child; i++) {
		Node *post_child = va_arg(vlist, PNode);
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
	return parent_node;
}

/*some function for searching child node*/
Node* get_child_node_with_skip(Node *root, int token, int skip)
{
	if(skip < 0) return NULL;
	if(!root) return NULL;
	Node *child = root->child;
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

Node* get_child_node(Node *root, int token)
{
	return get_child_node_with_skip(root, token, 0);
}

Node* get_child_node_with_skip_w(Node *root, int token, int skip)
{
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	Node *ret = get_child_node_with_skip(root, token, skip);
	if(!ret)
		logw("unsucessful search:{'root':'%s', 'child':'%s', 'rule':'%s'}\n", str_lexval[root->token], str_lexval[token], syntax_rules[root->reduce_rule].str_rule);
	return ret;
}

Node* get_child_node_w(Node *root, int token)
{
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	Node *ret = get_child_node(root, token);
	if(!ret) {
		logw("unsucessful search:{'root':'%s', 'child':'%s', 'rule':'%s'}\n", str_lexval[root->token], str_lexval[token], syntax_rules[root->reduce_rule].str_rule);
	}
	return ret;
}

Node* __attribute__((noinline))get_child_node_dw(Node *root, int depth, ...)
{
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

void print_ast(Node *root)
{
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
		printf("%s:%s", str_lexval[root->token], root->cv.str);
	else if(root->token == NUM) {
		switch(root->cv.st) {
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
		printf("TYPE:%s", str_lexval[root->reduce_rule]);
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
	mempool_init(&ndpool, sizeof(Node));
}
