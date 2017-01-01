#include "common.h"
#include "vector.h"

static ReduceRules rules[] = {
	[AST_NONTERMINALBEGIN] = {0, NONTERMINALBEGIN, "AST_NONTERMINALBEGIN", "NONTERMINALBEGIN"},
	[AST_Program_is_BlockList] = {1, Program, "AST_Program_is_BlockList", "Program"},
	[AST_BlockList_is_Block] = {1, BlockList, "AST_BlockList_is_Block", "BlockList"},
	[AST_BlockList_is_Block_BlockList] = {2, BlockList, "AST_BlockList_is_Block_BlockList", "BlockList"},
	[AST_Block_is_Specifier_FuncDec_CompSt] = {3, Block, "AST_Block_is_Specifier_FuncDec_CompSt", "Block"},
	[AST_Block_is_StructDec_SEMI] = {2, Block, "AST_Block_is_StructDec_SEMI", "Block"},
	[AST_Block_is_StructDec_IdList_SEMI] = {3, Block, "AST_Block_is_StructDec_IdList_SEMI", "Block"},
	[AST_Block_is_VarDef] = {1, Block, "AST_Block_is_VarDef", "Block"},
	[AST_IdList_is_ID_COMMA_IdList] = {3, IdList, "AST_IdList_is_ID_COMMA_IdList", "IdList"},
	[AST_IdList_is_ID] = {1, IdList, "AST_IdList_is_ID", "IdList"},
	[AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC] = {5, StructDec, "AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC", "StructDec"},
	[AST_StructDecVarList_is_StructDecVar_StructDecVarList] = {2, StructDecVarList, "AST_StructDecVarList_is_StructDecVar_StructDecVarList", "StructDecVarList"},
	[AST_StructDecVarList_is_StructDecVar] = {1, StructDecVarList, "AST_StructDecVarList_is_StructDecVar", "StructDecVarList"},
	[AST_StructDecVar_is_Specifier_IdList_SEMI] = {3, StructDecVar, "AST_StructDecVar_is_Specifier_IdList_SEMI", "StructDecVar"},
	[AST_StructDecVar_is_StructDec_IdList_SEMI] = {3, StructDecVar, "AST_StructDecVar_is_StructDec_IdList_SEMI", "StructDecVar"},
	[AST_FuncDec_is_ID_LP_RP] = {3, FuncDec, "AST_FuncDec_is_ID_LP_RP", "FuncDec"},
	[AST_FuncDec_is_ID_LP_FuncDefArgList_RP] = {4, FuncDec, "AST_FuncDec_is_ID_LP_FuncDefArgList_RP", "FuncDec"},
	[AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList] = {3, FuncDefArgList, "AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList", "FuncDefArgList"},
	[AST_FuncDefArgList_is_FuncDefArg] = {1, FuncDefArgList, "AST_FuncDefArgList_is_FuncDefArg", "FuncDefArgList"},
	[AST_FuncDefArg_is_Specifier_ID] = {2, FuncDefArg, "AST_FuncDefArg_is_Specifier_ID", "FuncDefArg"},
	[AST_CompSt_is_LC_StmtList_RC] = {3, CompSt, "AST_CompSt_is_LC_StmtList_RC", "CompSt"},
	[AST_StmtList_is_Stmt_StmtList] = {2, StmtList, "AST_StmtList_is_Stmt_StmtList", "StmtList"},
	[AST_StmtList_is_Stmt] = {1, StmtList, "AST_StmtList_is_Stmt", "StmtList"},
	[AST_Stmt_is_Exp_SEMI] = {2, Stmt, "AST_Stmt_is_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_VarDef] = {1, Stmt, "AST_Stmt_is_VarDef", "Stmt"},
	[AST_Stmt_is_CompSt] = {1, Stmt, "AST_Stmt_is_CompSt", "Stmt"},
	[AST_Stmt_is_SEMI] = {1, Stmt, "AST_Stmt_is_SEMI", "Stmt"},
	[AST_Stmt_is_RETURN_Exp_SEMI] = {3, Stmt, "AST_Stmt_is_RETURN_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_IF_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt] = {7, Stmt, "AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt", "Stmt"},
	[AST_Stmt_is_WHILE_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_WHILE_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI] = {7, Stmt, "AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI", "Stmt"},
	[AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt] = {9, Stmt, "AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt", "Stmt"},
	[AST_VarDef_is_Specifier_DecList_SEMI] = {3, VarDef, "AST_VarDef_is_Specifier_DecList_SEMI", "VarDef"},
	[AST_DecList_is_Dec_COMMA_DecList] = {3, DecList, "AST_DecList_is_Dec_COMMA_DecList", "DecList"},
	[AST_DecList_is_Dec] = {1, DecList, "AST_DecList_is_Dec", "DecList"},
	[AST_Dec_is_VarDec] = {1, Dec, "AST_Dec_is_VarDec", "Dec"},
	[AST_Dec_is_VarDec_ASSIGNOP_Exp] = {3, Dec, "AST_Dec_is_VarDec_ASSIGNOP_Exp", "Dec"},
	[AST_VarDec_is_ID] = {1, VarDec, "AST_VarDec_is_ID", "VarDec"},
	[AST_VarDec_is_MULT_VarDec] = {2, VarDec, "AST_VarDec_is_MULT_VarDec", "VarDec"},
	[AST_VarDec_is_VarDec_LB_NUM_RB] = {4, VarDec, "AST_VarDec_is_VarDec_LB_NUM_RB", "VarDec"},
	[AST_Specifier_is_TYPE] = {1, Specifier, "AST_Specifier_is_TYPE", "Specifier"},
	[AST_Specifier_is_STRUCT_ID] = {2, Specifier, "AST_Specifier_is_STRUCT_ID", "Specifier"},
	[AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList] = {3, FuncCallArgList, "AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList", "FuncCallArgList"},
	[AST_FuncCallArgList_is_FuncCallArg] = {1, FuncCallArgList, "AST_FuncCallArgList_is_FuncCallArg", "FuncCallArgList"},
	[AST_FuncCallArg_is_Exp] = {1, FuncCallArg, "AST_FuncCallArg_is_Exp", "FuncCallArg"},
	[AST_Exp_is_ID] = {1, Exp, "AST_Exp_is_ID", "Exp"},
	[AST_Exp_is_ID_LP_RP] = {3, Exp, "AST_Exp_is_ID_LP_RP", "Exp"},
	[AST_Exp_is_ID_LP_FuncCallArgList_RP] = {4, Exp, "AST_Exp_is_ID_LP_FuncCallArgList_RP", "Exp"},
	[AST_Exp_is_NUM] = {1, Exp, "AST_Exp_is_NUM", "Exp"},
	[AST_Exp_is_ADD_NUM] = {2, Exp, "AST_Exp_is_ADD_NUM", "Exp"},
	[AST_Exp_is_SUB_NUM] = {2, Exp, "AST_Exp_is_SUB_NUM", "Exp"},
	[AST_Exp_is_MULT_Exp] = {2, Exp, "AST_Exp_is_MULT_Exp", "Exp"},
	[AST_Exp_is_BITAND_Exp] = {2, Exp, "AST_Exp_is_BITAND_Exp", "Exp"},
	[AST_Exp_is_BITNOR_Exp] = {2, Exp, "AST_Exp_is_BITNOR_Exp", "Exp"},
	[AST_Exp_is_NOT_Exp] = {2, Exp, "AST_Exp_is_NOT_Exp", "Exp"},
	[AST_Exp_is_STRING] = {1, Exp, "AST_Exp_is_STRING", "Exp"},
	[AST_Exp_is_Exp_ASSIGNOP_Exp] = {3, Exp, "AST_Exp_is_Exp_ASSIGNOP_Exp", "Exp"},
	[AST_Exp_is_Exp_COMMA_Exp] = {3, Exp, "AST_Exp_is_Exp_COMMA_Exp", "Exp"},
	[AST_Exp_is_Exp_DOT_ID] = {3, Exp, "AST_Exp_is_Exp_DOT_ID", "Exp"},
	[AST_Exp_is_Exp_POINTER_ID] = {3, Exp, "AST_Exp_is_Exp_POINTER_ID", "Exp"},
	[AST_Exp_is_Exp_ADD_Exp] = {3, Exp, "AST_Exp_is_Exp_ADD_Exp", "Exp"},
	[AST_Exp_is_Exp_SUB_Exp] = {3, Exp, "AST_Exp_is_Exp_SUB_Exp", "Exp"},
	[AST_Exp_is_Exp_MULT_Exp] = {3, Exp, "AST_Exp_is_Exp_MULT_Exp", "Exp"},
	[AST_Exp_is_Exp_DIV_Exp] = {3, Exp, "AST_Exp_is_Exp_DIV_Exp", "Exp"},
	[AST_Exp_is_Exp_EQ_Exp] = {3, Exp, "AST_Exp_is_Exp_EQ_Exp", "Exp"},
	[AST_Exp_is_Exp_LT_Exp] = {3, Exp, "AST_Exp_is_Exp_LT_Exp", "Exp"},
	[AST_Exp_is_Exp_LE_Exp] = {3, Exp, "AST_Exp_is_Exp_LE_Exp", "Exp"},
	[AST_Exp_is_Exp_NE_Exp] = {3, Exp, "AST_Exp_is_Exp_NE_Exp", "Exp"},
	[AST_Exp_is_Exp_GT_Exp] = {3, Exp, "AST_Exp_is_Exp_GT_Exp", "Exp"},
	[AST_Exp_is_Exp_GE_Exp] = {3, Exp, "AST_Exp_is_Exp_GE_Exp", "Exp"},
	[AST_Exp_is_Exp_AND_Exp] = {3, Exp, "AST_Exp_is_Exp_AND_Exp", "Exp"},
	[AST_Exp_is_Exp_OR_Exp] = {3, Exp, "AST_Exp_is_Exp_OR_Exp", "Exp"},
	[AST_Exp_is_Exp_BITAND_Exp] = {3, Exp, "AST_Exp_is_Exp_BITAND_Exp", "Exp"},
	[AST_Exp_is_Exp_BITOR_Exp] = {3, Exp, "AST_Exp_is_Exp_BITOR_Exp", "Exp"},
	[AST_Exp_is_LP_Exp_RP] = {3, Exp, "AST_Exp_is_LP_Exp_RP", "Exp"},
	[AST_Exp_is_Exp_LB_Exp_RB] = {4, Exp, "AST_Exp_is_Exp_LB_Exp_RB", "Exp"}
};

static char* str_lexval[] = {
	[LT] = "LT",
	[LE] = "LE",
	[NE] = "NE",
	[EQ] = "EQ",
	[GE] = "GE",
	[GT] = "GT",
	[BITAND] = "BITAND",
	[BITOR] = "BITOR",
	[BITNOR] = "BITNOR",
	[AND] = "AND",
	[OR] = "OR",
	[NOT] = "NOT",
	[ADD] = "ADD",
	[SUB] = "SUB",
	[MULT] = "MULT",
	[DIV] = "DIV",
	[RELOP] = "RELOP",
	[ASSIGNOP] = "ASSIGNOP",
	[LP] = "LP",
	[RP] = "RP",
	[LB] = "LB",
	[RB] = "RB",
	[LC] = "LC",
	[RC] = "RC",
	[DOT] = "DOT",
	[COMMA] = "COMMA",
	[SEMI] = "SEMI",
	[POINTER] = "POINTER",
	[IF] = "IF",
	[ELSE] = "ELSE",
	[DO] = "DO",
	[WHILE] = "WHILE",
	[FOR] = "FOR",
	[RETURN] = "RETURN",
	[TYPE] = "TYPE",
	[INT] = "INT",
	[CHAR] = "CHAR",
	[FLOAT] = "FLOAT",
	[ENUM] = "ENUM",
	[STRUCT] = "STRUCT",
	[NUM] = "NUM",
	[STRING] = "STRING",
	[ID] = "ID",
	[Program] = "Program",
	[BlockList] = "BlockList",
	[Block] = "Block",
	[FuncDec] = "FuncDec",
	[FuncDefArgList] = "FuncDefArgList",
	[FuncDefArg] = "FuncDefArg",
	[FuncCallArgList] = "FuncCallArgList",
	[FuncCallArg] = "FuncCallArg",
	[IdList] = "IdList",
	[VarDef] = "VarDef",
	[StmtList] = "StmtList",
	[Stmt] = "Stmt",
	[DecList] = "DecList",
	[Dec] = "Dec",
	[VarDec] = "VarDec",
	[Specifier] = "Specifier",
	[StructDec] = "StructDec",
	[StructDecVar] = "StructDecVar",
	[StructDecVarList] = "StructDecVarList",
	[CompSt] = "CompSt",
	[Exp] = "Exp"
};

#define MAX_SIZE (1024*1024*2)

int curlineno;
static Node ndpool[MAX_SIZE];
Node *astroot = NULL;
static int ndpool_ptr;

extern bool is_print_reduce_step;

void __attribute__((noinline)) make_node(Node *root, int reduce_rule, int token, ...) {
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
		printf("%s:%s\n", str_lexval[root->token], root->supval.st);
	else if(root->token == NUM) {
		switch(root->suptype) {
		case 'i':
			printf("NUM:%d\n", root->supval.i);
			break;
		case 'o':
			printf("NUM:0%o\n", root->supval.i);
			break;
		case 'x':
			printf("NUM:0x%x\n", root->supval.i);
			break;
		case 'f':
			printf("NUM:%f\n", root->supval.f);
			break;
		default:
			printf("NUM:0\n");
			break;
		}
	}
	else if(root->token == TYPE)
		printf("TYPE:%s\n", str_lexval[root->suptype]);
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

int init_ast()
{
	astroot = NULL;
	ndpool_ptr = -1;
#ifdef __DEBUG__
	STATE_TEST_START;
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
