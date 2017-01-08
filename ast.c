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
	wt_assert(ndpool_ptr < MAX_SIZE);
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
	return parent_node;
}

void dump_ast(Node *root)
{
	if(root == NULL)
		return;

	static int newline = 0;
	static int tree_depth = 0;
	static int pp = 0;


	if(root->token == RC) {
		tree_depth --;
	}

	if(root->token == LP)
		pp ++;
	else if(root->token == RP)
		pp --;

	/* print leading space */
	if(!pp && newline) {
		printf("\n");
		for(int i = 0; i < tree_depth; i++) {
			printf("    ");
		}
	}

	if(root->token == LC) {
		tree_depth ++;
	}

	newline = 0;

	/* print semanval or lexval */
	switch(root->token){
		case SIZEOF:	printf("sizeof ");break;
		case LSHIFT:	printf(" << ");break;
		case RSHIFT:	printf(" >> ");break;
		case LSHIFTE:	printf(" <<= ");break;
		case RSHIFTE:	printf(" >>= ");break;
		case LT:		printf(" <= ");break;
		case LE:		printf(" < ");break;
		case NE:		printf(" != ");break;
		case EQ:		printf(" == ");break;
		case GE:		printf(" >= ");break;
		case GT:		printf(" > ");break;
		case AND:		printf(" & ");break;
		case OR:		printf(" | ");break;
		case XOR:		printf(" ^ ");break;
		case NOT:		printf("~");break;
		case ANDE:		printf(" &= ");break;
		case ORE:		printf(" |= ");break;
		case XORE:		printf(" ^= ");break;
		case LAND:		printf(" && ");break;
		case LOR:		printf(" || ");break;
		case LNOT:		printf("!");break;
		case ADD:		printf(" + ");break;
		case SUB:		printf(" - ");break;
		case MULT:		printf("*");break;
		case DIV:		printf(" / ");break;
		case MOD:		printf("%% ");break;
		case ADDE:		printf(" += ");break;
		case SUBE:		printf(" -= ");break;
		case MULTE:		printf(" *= ");break;
		case DIVE:		printf(" /= ");break;
		case MODE:		printf(" %%= ");break;
		case INC:		printf(" ++");break;
		case DEC:		printf(" --");break;
		case ASSIGNOP:	printf(" = ");break;
		case LP:		printf("(");break;
		case RP:		printf(")");break;
		case LB:		printf("[");break;
		case RB:		printf("]");break;
		case LC:		printf("{");newline=1;break;
		case RC:		printf("}");newline=1;break;
		case DOT:		printf(".");break;
		case COMMA:		printf(", ");break;
		case SEMI:		printf(";");newline=1;break;
		case POINTER:	printf("->");break;
		case COLON:		printf(":");newline=1;break;
		case IF:		printf("if ");break;
		case ELSE:		printf("else ");break;
		case DO:		printf("do ");break;
		case WHILE:		printf("while ");break;
		case FOR:		printf("for ");break;
		case RETURN:	printf("return ");break;
		case SWITCH:	printf("switch ");break;
		case CASE:		printf("case ");break;
		case BREAK:		printf("break ");break;
		case DEFAULT:	printf("default ");break;
		case GOTO:		printf("goto ");break;
		case TYPE:
			switch(root->idtype->cons.suptype) {
				case VOID:		printf("void ");break;
				case BOOL:		printf("bool ");break;
				case CHAR:		printf("char ");break;
				case SHORT:		printf("short ");break;
				case INT:		printf("int ");break;
				case UNSIGNED:	printf("unsigned ");break;
				case FLOAT:		printf("float ");break;
				case DOUBLE:	printf("double ");break;
				case INT8T:		printf("int8_t ");break;
				case INT16T:	printf("int16_t ");break;
				case INT32T:	printf("int32_t ");break;
				case INT64T:	printf("int64_t ");break;
				case UINT8T:	printf("uint8_t ");break;
				case UINT16T:	printf("uint16_t ");break;
				case UINT32T:	printf("uint32_t ");break;
				case UINT64T:	printf("uint64_t ");break;
				case SIZET:		printf("size_t ");break;
				case OFFT:		printf("off_t ");break;
				case UINTPTRT:	printf("uintptr_t ");break;
			}
			break;
		case ENUM:		printf("enum ");break;
		case UNION:		printf("union ");break;
		case STRUCT:	printf("struct ");break;
		case NUM:
			switch(root->idtype->cons.suptype) {
				case 'i':
					printf("%d", root->idtype->cons.supval.i);
					break;
				case 'o':
					printf("0%o", root->idtype->cons.supval.i);
					break;
				case 'x':
					printf("0x%x", root->idtype->cons.supval.i);
					break;
				case 'f':
					printf("%f", root->idtype->cons.supval.f);
					break;
				default:
					printf("?");
					break;
			}
			break;
		case STRING:
			printf("\"%s\"", root->idtype->cons.supval.st);
			break;
		case NIL:		printf("NULL");break;
		case TRUE:		printf("true");break;
		case FALSE:		printf("false");break;
		case ID:
			printf("%s", root->idtype->cons.supval.st);
			break;
	}

	if(root->token == Block) {
		printf("\n\n");
	}

	/* recursively print ast */
	if(root->token == Exp) printf("(");
	dump_ast(root->child);
	if(root->token == Exp) printf(")");
	dump_ast(root->sibling);

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
		printf("%s:%s\n", str_lexval[root->token], root->idtype->cons.supval.st);
	else if(root->token == NUM) {
		switch(root->idtype->cons.suptype) {
		case 'i':
			printf("NUM:%d\n", root->idtype->cons.supval.i);
			break;
		case 'o':
			printf("NUM:0%o\n", root->idtype->cons.supval.i);
			break;
		case 'x':
			printf("NUM:0x%x\n", root->idtype->cons.supval.i);
			break;
		case 'f':
			printf("NUM:%f\n", root->idtype->cons.supval.f);
			break;
		default:
			printf("NUM:0\n");
			break;
		}
	}
	else if(root->token == TYPE)
		printf("TYPE:%s\n", str_lexval[root->idtype->cons.suptype]);
	else
		printf("%s\n", str_lexval[root->token]);


	/* recursively print ast */
	stack[tree_depth] = !!root->sibling;
	tree_depth ++;	print_ast(root->child);	tree_depth --;
	stack[tree_depth] = 0;
	print_ast(root->sibling);

	//dec call_depth
	call_depth --;
	if(call_depth == 0) require_memory(0);
}

/*just for debugging */
void print_exp(Node *exp)
{
	if(!exp) return;
	static int call_depth = 0;
	for(int i = 0; i < call_depth; i++) {
		printf(" ");
	}
	if(exp->token == Exp) {
		printf("%s:'%s'@", str_lexval[exp->token], type_format(exp->idtype));
		if(exp->idtype)
			printf("%c\n", exp->idtype->lval ? 'r':'l');
		else
			printf("(nil)\n");
	}
	else
		printf("%s\n", str_lexval[exp->token]);

	call_depth += 2;
	print_exp(exp->child);
	call_depth -= 2;
	print_exp(exp->sibling);
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
	for(int i = 0; root && i < depth; i++) {
		int token = va_arg(vlist, int);
		root = get_child_node_w(root, token);
	}
	va_end(vlist);
	return root;
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

Node* find_node_by_rule(Node *root, int rule)
{
	if(!root) return NULL;

	if(root->reduce_rule == rule) {
		return root;
	}
	Node *node = NULL;
	node = find_node_by_rule(root->child, rule);
	if(!node)
		return find_node_by_rule(root->sibling, rule);
	return node;
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
	for(int i = 0;i < sizeof(syntax_rules)/sizeof(syntax_rules[0]); i++)
	{
		STATE_TEST_AVOID(syntax_rules[i].nr_child < 0 || syntax_rules[i].str_rule == NULL || syntax_rules[i].str_root == NULL);
		
		const char *ptr = syntax_rules[i].str_rule;
		while(*ptr) {
			STATE_TEST_AVOID( !( ('a'<= *ptr && *ptr<='z')
				||('A'<= *ptr && *ptr<='Z')
				||('0'<= *ptr && *ptr<='9') 
				||('_' == *ptr) )
					);
			ptr++;
		}

		ptr = syntax_rules[i].str_root;
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
