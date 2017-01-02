#define __AST_C__
#include "common.h"
#include "vector.h"

#define MAX_SIZE (1024*1024*2)

int curlineno;
static Node ndpool[MAX_SIZE];
Node *astroot = NULL;
static int ndpool_ptr;

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
	for(int i = 1; i < rules[reduce_rule].nr_child; i++)
	{
		Node *post_child = va_arg(vlist, PNode);
		prev_child->sibling = post_child;
		prev_child->parent = root;
		prev_child = post_child;
	}

	if(!rules[reduce_rule].nr_child)
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
	assert(ndpool_ptr < MAX_SIZE);
	ndpool_ptr ++;
	return &ndpool[ndpool_ptr];
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
		printf("%s\n", rules[nodetype].str_rule);

	va_list vlist;
	va_start(vlist, yyinfo);
	Node *parent_node = new_node();
	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;

	/*debug info*/
	parent_node->reduce_rule = nodetype;
	parent_node->token = rules[nodetype].root_type;
	parent_node->lineno = curlineno = yyinfo->first_line;
	parent_node->column = yyinfo->first_column;

	for(int i = 1; i < rules[nodetype].nr_child; i++) {
		Node *post_child = va_arg(vlist, PNode);
		prev_child->sibling = post_child;
		prev_child->parent = parent_node;
		prev_child = post_child;
	}

	if(!rules[nodetype].nr_child)
		first_child = NULL;
	else {
		prev_child->sibling = NULL;
		prev_child->parent = parent_node;
	}
	parent_node->child = first_child;
	va_end(vlist);
	return parent_node;
}

void print_ast(Node *root)
{
	if(root == NULL)
		return;

	static int call_depth = 0;
	static int *stack = NULL;
	static int space = 0, pstack = 0;

	if(call_depth == 0)
		stack = get_memory_pointer();

	//inc call_depth
	call_depth ++;

	/* print leading space */
	int j = 0;
	for(int i = 0; i < 3*space-3; i++)
	{
		int size = pstack;
		if(size > 0 && j<size && i==3*stack[j])
		{
			printf("|");
			j ++;
		}
		else printf(" ");
	}
	if(space > 0) printf("+--");

	/* print semanval or lexval */
	if(root->token == ID)
		printf("%s:%s\n", str_lexval[root->token], root->idtype->type.cons.supval.st);
	else if(root->token == NUM) {
		switch(root->idtype->type.cons.suptype) {
		case 'i':
			printf("NUM:%d\n", root->idtype->type.cons.supval.i);
			break;
		case 'o':
			printf("NUM:0%o\n", root->idtype->type.cons.supval.i);
			break;
		case 'x':
			printf("NUM:0x%x\n", root->idtype->type.cons.supval.i);
			break;
		case 'f':
			printf("NUM:%f\n", root->idtype->type.cons.supval.f);
			break;
		default:
			printf("NUM:0\n");
			break;
		}
	}
	else if(root->token == TYPE)
		printf("TYPE:%s\n", str_lexval[root->idtype->type.cons.suptype]);
	else
		printf("%s\n", str_lexval[root->token]);


	/* recursively print ast */
	space ++;
	if(root->sibling) stack[pstack++] = space-2;
	print_ast(root->child);
	space --;
	if(root->sibling) pstack --;
	print_ast(root->sibling);
	call_depth --;
}

Node* get_sibling_node(Node *root, int token)
{
	if(!root) return NULL;
	Node *sibling = root;
	if(root->parent) sibling = root->parent->child;
	while(sibling) {
		if(sibling->token == token)
			return sibling;
		sibling = sibling->sibling;
	}

	return NULL;
}

Node* get_sibling_node_w(Node *root, int token)
{
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	Node *ret = get_sibling_node(root, token);
	if(!ret)
		logw("unsucessful search:{'root':'%s', 'sibling':'%s'}\n", str_lexval[root->token], str_lexval[token]);
	return ret;
}

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
		logw("unsucessful search:{'root':'%s', 'child':'%s', 'rule':'%s'}\n", str_lexval[root->token], str_lexval[token], rules[root->reduce_rule].str_rule);
	return ret;
}

Node* get_child_node_w(Node *root, int token)
{
	if(!root)
		logw("invalid parameter: 'root'=(nil)\n");
	Node *ret = get_child_node(root, token);
	if(!ret)
		logw("unsucessful search:{'root':'%s', 'child':'%s', 'rule':'%s'}\n", str_lexval[root->token], str_lexval[token], rules[root->reduce_rule].str_rule);
	return ret;
}

/* not suggested to use
 * */
Node* find_child_node_with_depth(Node *root, int token, uint32_t depth)
{
	if(!depth || !root) return NULL;

	if(root->token == token) {
		return root;
	}
	Node *node = NULL;
	node = find_child_node_with_depth(root->child, token, depth - 1);
	if(!node)
		return find_child_node_with_depth(root->sibling, token, depth);
	return node;
}

Node* find_child_node(Node *root, int token)
{
	return find_child_node_with_depth(root, token, INT_MAX);
}

Node* find_node_by_rule(Node *root, int rule, int skip)
{
	return NULL;
}

int init_ast()
{
#define STATE_RESET \
	do { \
		astroot = NULL;\
		ndpool_ptr = -1;\
	} while(0)


#ifdef __DEBUG__
	STATE_TEST_START;
	STATE_RESET;
	for(int i = 0;i < sizeof(rules)/sizeof(rules[0]); i++)
	{
		STATE_TEST_AVOID(rules[i].nr_child < 0 || rules[i].str_rule == NULL || rules[i].str_root == NULL);
		
		const char *ptr = rules[i].str_rule;
		while(*ptr) {
			STATE_TEST_AVOID( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
					);
			ptr++;
		}

		ptr = rules[i].str_root;
		while(*ptr) {
			STATE_TEST_AVOID( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
				);
			ptr++;
		}
	}

	STATE_TEST_END;
#endif

	return 0;
}
