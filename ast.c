#include "common.h"
#include "vector.h"

#define __AST_C__
#include "ast.h"

#define MAX_SIZE (1024*1024*2)

int curlineno;
static Node ndpool[MAX_SIZE];
Node *astroot = NULL;
DebugInfo curd;

extern bool is_print_reduce_step;

Node* new_node()
{
	static int ndpool_p = -1;
	assert(ndpool_p < MAX_SIZE);
	ndpool_p ++;
	return &ndpool[ndpool_p];
}

Node* new_sym_node(int lexval, YYLTYPE *yyinfo)
{
	Node *pnd = new_node();
	pnd->lexval = lexval;
	pnd->lineno = yyinfo->first_line;
	pnd->column = yyinfo->last_column;
	return pnd;
}

Node* __attribute__((noinline)) build_subast(int nodetype, YYLTYPE *yyinfo, ...)
{
	if(is_print_reduce_step)
		logd("%s\n", node_struct[nodetype].str_struct);

	va_list vlist;
	va_start(vlist, yyinfo);
	Node *parent_node = new_node();
	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;

	/*debug info*/
	parent_node->semanval = nodetype;
	parent_node->syntaxval = node_struct[nodetype].parent;
	parent_node->lineno = curlineno = yyinfo->first_line;
	parent_node->column = yyinfo->first_column;

	for(int i = 1; i < node_struct[nodetype].nr_child; i++)
	{
		Node *post_child = va_arg(vlist, PNode);
		prev_child->sibling = post_child;
		prev_child->parent = parent_node;
		prev_child = post_child;
	}

	if(!node_struct[nodetype].nr_child)
		first_child = NULL;
	else
	{
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

	static int *stack;
	static int space = 0;
	vector_init(int, stack);

	/* print leading space */
	int j = 0;
	for(int i = 0; i < 3*space-3; i++)
	{
		int size = vector_size(stack);
		if(size > 0 && j<size && i==3*stack[j])
		{
			logd("|");
			j ++;
		}
		else logd(" ");
	}
	if(space > 0) logd("+--");

	/* print semanval or lexval */
	if(root->semanval > 0)
		logd("%s\n", node_struct[root->semanval].str_root);
	else if(root->lexval >= 0)
	{
		if(root->lexval == ID)
			logd("%s:%s\n", str_lexval[root->lexval], root->exval.st);
		else if(root->lexval == NUM)
		{
			switch(root->specval)
			{
			case 'i':
				logd("NUM:%d\n", root->exval.i);
				break;
			case 'o':
				logd("NUM:0%o\n", root->exval.i);
				break;
			case 'x':
				logd("NUM:0x%x\n", root->exval.i);
				break;
			case 'f':
				logd("NUM:%f\n", root->exval.f);
				break;
			default:
				logd("NUM:0\n");
				break;
			}
		}
		else if(root->lexval == TYPE)
			logd("TYPE:%s\n", str_lexval[root->specval]);
		else
			logd("%s\n", str_lexval[root->lexval]);
	}


	/* recursively print ast */
	space ++;
	if(root->sibling) vector_push(stack, space-2);
	print_ast(root->child);
	space --;
	if(root->sibling) vector_pop(stack);
	print_ast(root->sibling);

	if(space == 0)
		vector_free(stack);
}

int init_ast()
{
#ifdef __DEBUG__
	bool pass = true;
	logd("[unit test]func:%s, line:%d...", __func__, __LINE__);
	for(int i = 0;pass && i < sizeof(node_struct)/sizeof(node_struct[0]); i++)
	{
		if(node_struct[i].nr_child < 0 || node_struct[i].str_struct == NULL || node_struct[i].str_root == NULL)
		{
			loge("\ntest failed at #%d of array node_struct.", i);
			pass = false;
			break;
		}
		
		char *ptr = node_struct[i].str_struct;
		while(*ptr) {
			if( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
				)
			{
				loge("\ntest failed at #%d of array node_struct.", i);
				pass = false;
				break;
			}
			ptr++;
		}

		ptr = node_struct[i].str_root;
		while(*ptr) {
			if( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
				)
			{
				loge("\ntest failed at #%d of array node_struct.", i);
				pass = false;
				break;
			}
			ptr++;
		}
	}

	if(pass)
		logG("PASS\n");
	else
		logd("\n");
#endif
	return 0;
}

Node *get_child(Node *par, int semanval)
{
	return NULL;
}
