#ifndef __AST_H__
#define __AST_H__

enum {
	AST_Undefined,
	AST_Program_is_ExtDefList,
	AST_ExtDefList_is_ExtDef,
	AST_ExtDefList_is_ExtDef_ExtDefList,
	AST_ExtDef_is_Specifier_FuncDec_CompSt,
	AST_ExtDef_is_StructSpecifier_SEMI,
	AST_ExtDef_is_StructSpecifier_error,
	AST_FuncDec_is_ID_LP_RP,
	AST_FuncDec_is_ID_LP_ArgList_RP,
	AST_ArgList_is_Arg_COMMA_ArgList,
	AST_ArgList_is_Arg,
	AST_Arg_is_Specifier_ID,
	AST_CompSt_is_LC_DefList_StmtList_RC,
	AST_CompSt_is_LC_DefList_StmtList_error,
	AST_StmtList_is_Stmt_StmtList,
	AST_StmtList_is_Stmt,
	AST_Stmt_is_Exp_SEMI,
	AST_Stmt_is_SEMI,
	AST_Stmt_is_RETURN_Exp_SEMI,
	AST_Stmt_is_LC_StmtList_RC,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt,
	AST_Stmt_is_WHILE_LP_Exp_RP_Stmt,
	AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI,
	AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt,
	AST_Stmt_is_Exp_error,
	AST_Stmt_is_RETURN_Exp_error,
	AST_Stmt_is_LC_StmtList_error,
	AST_DefList_is_Def_DefList,
	AST_DefList_is_Def,
	AST_Def_is_Specifier_DecList_SEMI,
	AST_Def_is_Specifier_DecList_error,
	AST_DecList_is_Dec_COMMA_DecList,
	AST_DecList_is_Dec,
	AST_DecList_is_Dec_error_COMMA_DecList,
	AST_Dec_is_VarDec,
	AST_Dec_is_VarDec_ASSIGNOP_Exp,
	AST_VarDec_is_ID,
	AST_VarDec_is_VarDec_LB_NUM_RB,
	AST_Specifier_is_TYPE,
	AST_Specifier_is_StructSpecifier,
	AST_StructSpecifier_is_STRUCT_Tag,
	AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC,
	AST_Tag_is_ID,
	AST_OptTag_is_ID,
	AST_Exp_is_ID,
	AST_Exp_is_NUM,
	AST_Exp_is_ADD_NUM,
	AST_Exp_is_SUB_NUM,
	AST_Exp_is_STRING,
	AST_Exp_is_Exp_ASSIGNOP_Exp,
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
	AST_Exp_is_Exp_LB_Exp_RB,
	AST_Exp_is_Exp_LB_Exp_error,
};

#ifdef __AST_C__

typedef struct tagParNodeStruct {
	int nr_child;
	char *str_struct;
	char *str_root;
} ParNodeStruct;

static ParNodeStruct parnodestruct[] = {
	[AST_Undefined] = {0, "AST_Undefined", "Undefined"},
	[AST_Program_is_ExtDefList] = {1, "AST_Program_is_ExtDefList", "Program"},
	[AST_ExtDefList_is_ExtDef] = {1, "AST_ExtDefList_is_ExtDef", "ExtDefList"},
	[AST_ExtDefList_is_ExtDef_ExtDefList] = {2, "AST_ExtDefList_is_ExtDef_ExtDefList", "ExtDefList"},
	[AST_ExtDef_is_Specifier_FuncDec_CompSt] = {3, "AST_ExtDef_is_Specifier_FuncDec_CompSt", "ExtDef"},
	[AST_ExtDef_is_StructSpecifier_SEMI] = {2, "AST_ExtDef_is_StructSpecifier_SEMI", "ExtDef"},
	[AST_ExtDef_is_StructSpecifier_error] = {2, "AST_ExtDef_is_StructSpecifier_error", "ExtDef"},
	[AST_FuncDec_is_ID_LP_RP] = {3, "AST_FuncDec_is_ID_LP_RP", "FuncDec"},
	[AST_FuncDec_is_ID_LP_ArgList_RP] = {4, "AST_FuncDec_is_ID_LP_ArgList_RP", "FuncDec"},
	[AST_ArgList_is_Arg_COMMA_ArgList] = {3, "AST_ArgList_is_Arg_COMMA_ArgList", "ArgList"},
	[AST_ArgList_is_Arg] = {1, "AST_ArgList_is_Arg", "ArgList"},
	[AST_Arg_is_Specifier_ID] = {2, "AST_Arg_is_Specifier_ID", "Arg"},
	[AST_CompSt_is_LC_DefList_StmtList_RC] = {4, "AST_CompSt_is_LC_DefList_StmtList_RC", "CompSt"},
	[AST_CompSt_is_LC_DefList_StmtList_error] = {4, "AST_CompSt_is_LC_DefList_StmtList_error", "CompSt"},
	[AST_StmtList_is_Stmt_StmtList] = {2, "AST_StmtList_is_Stmt_StmtList", "StmtList"},
	[AST_StmtList_is_Stmt] = {1, "AST_StmtList_is_Stmt", "StmtList"},
	[AST_Stmt_is_Exp_SEMI] = {2, "AST_Stmt_is_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_SEMI] = {1, "AST_Stmt_is_SEMI", "Stmt"},
	[AST_Stmt_is_RETURN_Exp_SEMI] = {3, "AST_Stmt_is_RETURN_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_LC_StmtList_RC] = {3, "AST_Stmt_is_LC_StmtList_RC", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt] = {5, "AST_Stmt_is_IF_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt] = {7, "AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt", "Stmt"},
	[AST_Stmt_is_WHILE_LP_Exp_RP_Stmt] = {5, "AST_Stmt_is_WHILE_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI] = {7, "AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI", "Stmt"},
	[AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt] = {9, "AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_Exp_error] = {2, "AST_Stmt_is_Exp_error", "Stmt"},
	[AST_Stmt_is_RETURN_Exp_error] = {3, "AST_Stmt_is_RETURN_Exp_error", "Stmt"},
	[AST_Stmt_is_LC_StmtList_error] = {3, "AST_Stmt_is_LC_StmtList_error", "Stmt"},
	[AST_DefList_is_Def_DefList] = {2, "AST_DefList_is_Def_DefList", "DefList"},
	[AST_DefList_is_Def] = {1, "AST_DefList_is_Def", "DefList"},
	[AST_Def_is_Specifier_DecList_SEMI] = {3, "AST_Def_is_Specifier_DecList_SEMI", "Def"},
	[AST_Def_is_Specifier_DecList_error] = {3, "AST_Def_is_Specifier_DecList_error", "Def"},
	[AST_DecList_is_Dec_COMMA_DecList] = {3, "AST_DecList_is_Dec_COMMA_DecList", "DecList"},
	[AST_DecList_is_Dec] = {1, "AST_DecList_is_Dec", "DecList"},
	[AST_DecList_is_Dec_error_COMMA_DecList] = {4, "AST_DecList_is_Dec_error_COMMA_DecList", "DecList"},
	[AST_Dec_is_VarDec] = {1, "AST_Dec_is_VarDec", "Dec"},
	[AST_Dec_is_VarDec_ASSIGNOP_Exp] = {3, "AST_Dec_is_VarDec_ASSIGNOP_Exp", "Dec"},
	[AST_VarDec_is_ID] = {1, "AST_VarDec_is_ID", "VarDec"},
	[AST_VarDec_is_VarDec_LB_NUM_RB] = {4, "AST_VarDec_is_VarDec_LB_NUM_RB", "VarDec"},
	[AST_Specifier_is_TYPE] = {1, "AST_Specifier_is_TYPE", "Specifier"},
	[AST_Specifier_is_StructSpecifier] = {1, "AST_Specifier_is_StructSpecifier", "Specifier"},
	[AST_StructSpecifier_is_STRUCT_Tag] = {2, "AST_StructSpecifier_is_STRUCT_Tag", "StructSpecifier"},
	[AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC] = {5, "AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC", "StructSpecifier"},
	[AST_Tag_is_ID] = {1, "AST_Tag_is_ID", "Tag"},
	[AST_OptTag_is_ID] = {1, "AST_OptTag_is_ID", "OptTag"},
	[AST_Exp_is_ID] = {1, "AST_Exp_is_ID", "Exp"},
	[AST_Exp_is_NUM] = {1, "AST_Exp_is_NUM", "Exp"},
	[AST_Exp_is_ADD_NUM] = {2, "AST_Exp_is_ADD_NUM", "Exp"},
	[AST_Exp_is_SUB_NUM] = {2, "AST_Exp_is_SUB_NUM", "Exp"},
	[AST_Exp_is_STRING] = {1, "AST_Exp_is_STRING", "Exp"},
	[AST_Exp_is_Exp_ASSIGNOP_Exp] = {3, "AST_Exp_is_Exp_ASSIGNOP_Exp", "Exp"},
	[AST_Exp_is_Exp_DOT_ID] = {3, "AST_Exp_is_Exp_DOT_ID", "Exp"},
	[AST_Exp_is_Exp_POINTER_ID] = {3, "AST_Exp_is_Exp_POINTER_ID", "Exp"},
	[AST_Exp_is_Exp_ADD_Exp] = {3, "AST_Exp_is_Exp_ADD_Exp", "Exp"},
	[AST_Exp_is_Exp_SUB_Exp] = {3, "AST_Exp_is_Exp_SUB_Exp", "Exp"},
	[AST_Exp_is_Exp_MULT_Exp] = {3, "AST_Exp_is_Exp_MULT_Exp", "Exp"},
	[AST_Exp_is_Exp_DIV_Exp] = {3, "AST_Exp_is_Exp_DIV_Exp", "Exp"},
	[AST_Exp_is_Exp_EQ_Exp] = {3, "AST_Exp_is_Exp_EQ_Exp", "Exp"},
	[AST_Exp_is_Exp_LT_Exp] = {3, "AST_Exp_is_Exp_LT_Exp", "Exp"},
	[AST_Exp_is_Exp_LE_Exp] = {3, "AST_Exp_is_Exp_LE_Exp", "Exp"},
	[AST_Exp_is_Exp_NE_Exp] = {3, "AST_Exp_is_Exp_NE_Exp", "Exp"},
	[AST_Exp_is_Exp_GT_Exp] = {3, "AST_Exp_is_Exp_GT_Exp", "Exp"},
	[AST_Exp_is_Exp_GE_Exp] = {3, "AST_Exp_is_Exp_GE_Exp", "Exp"},
	[AST_Exp_is_Exp_LB_Exp_RB] = {4, "AST_Exp_is_Exp_LB_Exp_RB", "Exp"},
	[AST_Exp_is_Exp_LB_Exp_error] = {4, "AST_Exp_is_Exp_LB_Exp_error", "Exp"},
};

#include "syntax.h"

static char* str_lexval[] = {
	[LT] = "LT",
	[LE] = "LE",
	[NE] = "NE",
	[EQ] = "EQ",
	[GE] = "GE",
	[GT] = "GT",
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
	[STRUCT] = "STRUCT",
	[NUM] = "NUM",
	[STRING] = "STRING",
	[ID] = "ID",
};

#endif

Node* new_node();
Node* new_sym_node(int lexval, YYLTYPE *yyinfo);
Node* __attribute__((noinline)) build_subast(int nodetype, YYLTYPE *yyinfo, ...);
void print_ast(Node *root);
int init_ast();

#endif
