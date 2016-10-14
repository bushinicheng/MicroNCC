#ifndef __AST_H__
#define __AST_H__

enum {
	AST_Program_is_ExtDefList,
	AST_ExtDefList_is_ExtDef_ExtDefList,
	AST_ExtDefList_is_ExtDef,
	AST_ExtDef_is_Specifier_FuncDec_CompSt,
	AST_ExtDef_is_Specifier_SEMI,
	AST_FuncDec_is_ID_LP_RP,
	AST_FuncDec_is_ID_LP_ArgList_RP,
	AST_ArgList_is_Arg_COMMA_ArgList,
	AST_ArgList_is_Arg,
	AST_Arg_is_Specifier_ID,
	AST_CompSt_is_LC_DefList_StmtList_RC,
	AST_StmtList_is_Stmt_StmtList,
	AST_StmtList_is_Stmt,
	AST_Stmt_is_Exp_SEMI,
	AST_DefList_is_Def_DefList,
	AST_DefList_is_Def,
	AST_Def_is_Specifier_DecList_SEMI,
	AST_DecList_is_Dec_COMMA_DecList,
	AST_DecList_is_Dec,
	AST_Dec_is_VarDec,
	AST_Dec_is_VarDec_ASSIGNOP_Exp,
	AST_VarDec_is_ID,
	AST_Specifier_is_TYPE,
	AST_Specifier_is_StructSpecifier,
	AST_TYPE_is_INT,
	AST_TYPE_is_FLOAT,
	AST_StructSpecifier_is_STRUCT_Tag,
	AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC,
	AST_Tag_is_ID,
	AST_OptTag_is_ID,
	AST_Exp_is_ID
};

#ifdef __AST_NEED__

static int nr_child_nodes[] = {
	[AST_Program_is_ExtDefList] = 1,
	[AST_ExtDefList_is_ExtDef_ExtDefList] = 2,
	[AST_ExtDefList_is_ExtDef] = 1,
	[AST_ExtDef_is_Specifier_FuncDec_CompSt] = 3,
	[AST_ExtDef_is_Specifier_SEMI] = 2,
	[AST_FuncDec_is_ID_LP_RP] = 3,
	[AST_FuncDec_is_ID_LP_ArgList_RP] = 4,
	[AST_ArgList_is_Arg_COMMA_ArgList] = 3,
	[AST_ArgList_is_Arg] = 1,
	[AST_Arg_is_Specifier_ID] = 2,
	[AST_CompSt_is_LC_DefList_StmtList_RC] = 4,
	[AST_StmtList_is_Stmt_StmtList] = 2,
	[AST_StmtList_is_Stmt] = 1,
	[AST_Stmt_is_Exp_SEMI] = 2,
	[AST_DefList_is_Def_DefList] = 2,
	[AST_DefList_is_Def] = 1,
	[AST_Def_is_Specifier_DecList_SEMI] = 3,
	[AST_DecList_is_Dec_COMMA_DecList] = 3,
	[AST_DecList_is_Dec] = 1,
	[AST_Dec_is_VarDec] = 1,
	[AST_Dec_is_VarDec_ASSIGNOP_Exp] = 3,
	[AST_VarDec_is_ID] = 1,
	[AST_Specifier_is_TYPE] = 1,
	[AST_Specifier_is_StructSpecifier] = 1,
	[AST_TYPE_is_INT] = 1,
	[AST_TYPE_is_FLOAT] = 1,
	[AST_StructSpecifier_is_STRUCT_Tag] = 1,
	[AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC] = 5,
	[AST_Tag_is_ID] = 1,
	[AST_OptTag_is_ID] = 1,
	[AST_Exp_is_ID] = 1
};

#endif

Node* build_subast(int nodetype, ...);
Node *new_node();

#endif
