#include "common.h"

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
	va_list vlist;
	va_start(vlist, yyinfo);
	Node *parnd = new_node();
	Node *first_child = va_arg(vlist, PNode);
	Node *prev_child = first_child;
	parnd->lineno = curlineno = yyinfo->first_line;
	parnd->column = yyinfo->first_column;
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

	static int stack[20], pstack = 0;
	static int space = 0;

	/* print leading space */
	int j = 0;
	for(int i = 0; i < 3*space-3; i++)
	{
		if(pstack > 0 && j<pstack && i==3*stack[j])
		{
			logd("|");
			j ++;
		}
		else logd(" ");
	}
	if(space > 0) logd("+-");

	/* print semanval or lexval */
	if(root->semanval > 0)
		logd("%s\n", parnodestruct[root->semanval].str_root);
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
			}
		}
		else if(root->lexval == TYPE)
			logd("TYPE:%s\n", str_lexval[root->specval]);
		else
			logd("%s\n", str_lexval[root->lexval]);
	}


	/* recursively print ast */
	space ++;
	if(root->sibling) stack[pstack++] = space-2;
	print_ast(root->child);
	space --;
	if(root->sibling) pstack --;
	print_ast(root->sibling);
}

int init_ast()
{
#ifdef __DEBUG__
	bool pass = true;
	logd("[unit test]func:%s, line:%d...", __func__, __LINE__);
	for(int i = 0;pass && i < sizeof(parnodestruct)/sizeof(parnodestruct[0]); i++)
	{
		if(parnodestruct[i].nr_child < 0 || parnodestruct[i].str_struct == NULL || parnodestruct[i].str_root == NULL)
		{
			loge("\ntest failed at #%d of array parnodestruct.", i);
			pass = false;
			break;
		}
		
		char *ptr = parnodestruct[i].str_struct;
		while(*ptr) {
			if( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
				)
			{
				loge("\ntest failed at #%d of array parnodestruct.", i);
				pass = false;
				break;
			}
			ptr++;
		}

		ptr = parnodestruct[i].str_root;
		while(*ptr) {
			if( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
				)
			{
				loge("\ntest failed at #%d of array parnodestruct.", i);
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
