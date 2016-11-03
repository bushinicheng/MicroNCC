#include "common.h"
#include "ast.h"

#define MAX_SIZE (2*1024*1024)

Spec spec[MAX_SIZE];

int seman_analysis(Node *root)
{
	if(!root) return 0;

	seman_analysis(root->child);
	seman_analysis(root->sibling);
	return 0;
}
