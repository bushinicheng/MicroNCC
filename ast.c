#include "common.h"
#include "basic-dat.h"

#define __DEBUG_YACC__

#define __AST_C__
#include "ast.h"

#define MAX_SIZE (1024*1024*2)

static Node ndpool[MAX_SIZE];
Node *astroot = NULL;
DebugInfo curd;

extern bool is_print_reduce_step;

Node *new_node()
{
	static int ndpool_p = -1;
	assert(ndpool_p < MAX_SIZE);
	ndpool_p ++;
	return &ndpool[ndpool_p];
}

Node* __attribute__((noinline)) build_subast(int nodetype, ...)
{
	va_list vlist;
	va_start(vlist, nodetype);
	Node *parnd = new_node();
	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;
	prev_child->sibling = NULL;
	parnd->semanval = nodetype;
	if(is_print_reduce_step)
		logd("%s\n", parnodestruct[nodetype].str_struct);
	for(int i = 1; i < parnodestruct[nodetype].nr_child; i++)
	{
		Node *post_child = va_arg(vlist, PNode);
		prev_child->sibling = post_child;
		prev_child = post_child;
	}
	if(!parnodestruct[nodetype].nr_child)
		first_child = NULL;
	else
		prev_child->sibling = NULL;
	parnd->child = first_child;
	va_end(vlist);
	return parnd;
}

void print_ast(Node *root)
{
	if(root == NULL)
		return;

	static int space = 0;
	for(int i = 0; i < 2*space; i++)
		logd(" ");
	if(root->semanval > 0)
		logd("%s\n", parnodestruct[root->semanval].str_root);
	else
		logd("%s\n", str_lexval[root->lexval]);

	space ++;
	print_ast(root->child);
	space --;
	print_ast(root->sibling);
}

int init_ast()
{
#ifdef __DEBUG__
	bool pass = true;
	logd("[unit test]func:%s, line:%d...", __func__, __LINE__);
	for(int i = 0; i < sizeof(parnodestruct)/sizeof(parnodestruct[0]); i++)
	{
		if(parnodestruct[i].nr_child < 0 || parnodestruct[i].str_struct == NULL || parnodestruct[i].str_root == NULL)
		{
			loge("test failed at #%d of array parnodestruct.", i);
			pass = false;
		}
	}

	if(pass)
		logG("PASS\n");
	else
		logd("\n");
#endif
	return 0;
}
