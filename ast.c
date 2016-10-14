#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "basic-dat.h"

#define __AST_NEED__
#include "ast.h"

#define MAX_SIZE (1024*1024*2)

static Node ndpool[MAX_SIZE];
Node *astroot = &ndpool[0];
DebugInfo curd;

Node *new_node()
{
	static int ndpool_p = 0;
	assert(ndpool_p < MAX_SIZE);
	ndpool_p ++;
	return &ndpool[ndpool_p];
}

Node* __attribute__((noinline)) build_subast(int nodetype, ...)
{
	Node *pre_child = NULL;
	Node *parnd = new_node();
	parnd->semanval = nodetype;
	for(int i = nr_child_nodes[nodetype]; i>= 0; i--)
	{
		Node *post_child = *(Node **)(&nodetype + i);
		post_child->sibling = pre_child;
		pre_child = post_child;
	}
	parnd->child = pre_child;
	return 0;
}
