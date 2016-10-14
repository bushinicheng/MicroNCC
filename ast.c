#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "basic-dat.h"

#define __AST_C__
#include "ast.h"
#include "debug.h"

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
	va_list vlist;
	va_start(vlist, nodetype);
	Node *parnd = new_node();
	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;
	printf("*");
	printf("%d,%s,%p", nodetype, str_nodes[nodetype], prev_child);
	printf("*\n");
	set_break();
	parnd->semanval = nodetype;
	for(int i = 1; i < nr_child_nodes[nodetype]; i++)
	{
		Node *post_child = va_arg(vlist, PNode);
		prev_child->sibling = post_child;
		prev_child = post_child;
	}
	if(!nr_child_nodes[nodetype])
		first_child = NULL;
	else
		prev_child->sibling = NULL;
	parnd->child = first_child;
	printf("%p,%p\n", first_child->sibling, parnd->child);
	va_end(vlist);
	return parnd;
}
