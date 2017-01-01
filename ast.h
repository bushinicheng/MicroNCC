#ifndef __AST_H__
#define __AST_H__

enum {
	NONTERMINALBEGIN = 512,
	Program,
	BlockList,
	Block,
	FuncDec,
	FuncDefArgList,
	FuncDefArg,
	FuncCallArgList,
	FuncCallArg,
	IdList,
	VarDef,
	StmtList,
	Stmt,
	DecList,
	Dec,
	VarDec,
	Specifier,
	StructDec,
	StructDecVar,
	StructDecVarList,
	CompSt,
	Exp
};

enum {
	AST_NONTERMINALBEGIN,
	AST_Program_is_BlockList,
	AST_BlockList_is_Block,
	AST_BlockList_is_Block_BlockList,
	AST_Block_is_Specifier_FuncDec_CompSt,
	AST_Block_is_StructDec_IdList_SEMI,
	AST_Block_is_StructDec_SEMI,
	AST_Block_is_VarDef,
	AST_IdList_is_VarDec_COMMA_IdList,
	AST_IdList_is_VarDec,
	AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC,
	AST_StructDecVarList_is_StructDecVar_StructDecVarList,
	AST_StructDecVarList_is_StructDecVar,
	AST_StructDecVar_is_Specifier_IdList_SEMI,
	AST_StructDecVar_is_StructDec_IdList_SEMI,
	AST_FuncDec_is_ID_LP_RP,
	AST_FuncDec_is_ID_LP_FuncDefArgList_RP,
	AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList,
	AST_FuncDefArgList_is_FuncDefArg,
	AST_FuncDefArg_is_Specifier_VarDec,
	AST_CompSt_is_LC_StmtList_RC,
	AST_StmtList_is_Stmt_StmtList,
	AST_StmtList_is_Stmt,
	AST_Stmt_is_Exp_SEMI,
	AST_Stmt_is_VarDef,
	AST_Stmt_is_CompSt,
	AST_Stmt_is_SEMI,
	AST_Stmt_is_RETURN_Exp_SEMI,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt,
	AST_Stmt_is_WHILE_LP_Exp_RP_Stmt,
	AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI,
	AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt,
	AST_VarDef_is_Specifier_DecList_SEMI,
	AST_DecList_is_Dec_COMMA_DecList,
	AST_DecList_is_Dec,
	AST_Dec_is_VarDec,
	AST_Dec_is_VarDec_ASSIGNOP_Exp,
	AST_VarDec_is_ID,
	AST_VarDec_is_MULT_VarDec,
	AST_VarDec_is_VarDec_LB_NUM_RB,
	AST_Specifier_is_TYPE,
	AST_Specifier_is_STRUCT_ID,
	AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList,
	AST_FuncCallArgList_is_FuncCallArg,
	AST_FuncCallArg_is_Exp,
	AST_Exp_is_ID,
	AST_Exp_is_ID_LP_RP,
	AST_Exp_is_ID_LP_FuncCallArgList_RP,
	AST_Exp_is_NUM,
	AST_Exp_is_ADD_NUM,
	AST_Exp_is_SUB_NUM,
	AST_Exp_is_MULT_Exp,
	AST_Exp_is_BITAND_Exp,
	AST_Exp_is_BITNOR_Exp,
	AST_Exp_is_NOT_Exp,
	AST_Exp_is_STRING,
	AST_Exp_is_Exp_ASSIGNOP_Exp,
	AST_Exp_is_Exp_COMMA_Exp,
	AST_Exp_is_Exp_DOT_ID,
	AST_Exp_is_Exp_POINTER_ID,
	AST_Exp_is_Exp_ADD_Exp,
	AST_Exp_is_Exp_SUB_Exp,
	AST_Exp_is_Exp_MULT_Exp,
	AST_Exp_is_Exp_DIV_Exp,
	AST_Exp_is_Exp_EQ_Exp,
	AST_Exp_is_Exp_LT_Exp,
	AST_Exp_is_Exp_LE_Exp,
	AST_Exp_is_Exp_NE_Exp,
	AST_Exp_is_Exp_GT_Exp,
	AST_Exp_is_Exp_GE_Exp,
	AST_Exp_is_Exp_AND_Exp,
	AST_Exp_is_Exp_OR_Exp,
	AST_Exp_is_Exp_BITAND_Exp,
	AST_Exp_is_Exp_BITOR_Exp,
	AST_Exp_is_LP_Exp_RP,
	AST_Exp_is_Exp_LB_Exp_RB
};

typedef struct tagReduceRules {
    int nr_child;
    int root_type;
    const char *str_rule;
    const char *str_root;
} ReduceRules;

Node* new_node();
Node* new_sym_node(int lexval, YYLTYPE *yyinfo);
Node* __attribute__((noinline)) build_subast(int nodetype, YYLTYPE *yyinfo, ...);
void print_ast(Node *root);
int init_ast();

#endif
