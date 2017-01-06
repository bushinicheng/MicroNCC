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
	Initializer,
	TypeConversion,
	Specifier,
	TypeRef,
	CommonSpec,
	StarList,
	StructDec,
	AnonyStructDec,
	StructDecVar,
	StructDecVarList,
	CaseList,
	CaseOne,
	CompSt,
	Exp
};

enum {
	AST_NONTERMINALBEGIN,
	AST_Program_is_BlockList,
	AST_BlockList_is_Block,
	AST_BlockList_is_Block_BlockList,
	AST_Block_is_Specifier_FuncDec_CompSt,
	AST_Block_is_StructDec_SEMI,
	AST_Block_is_VarDef,
	AST_IdList_is_VarDec_COMMA_IdList,
	AST_IdList_is_VarDec,
	AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC,
	AST_AnonyStructDec_is_STRUCT_LC_StructDecVarList_RC,
	AST_StructDecVarList_is_StructDecVar_StructDecVarList,
	AST_StructDecVarList_is_StructDecVar,
	AST_StructDecVar_is_Specifier_IdList_SEMI,
	AST_StructDecVar_is_AnonyStructDec_SEMI,
	AST_StructDecVar_is_StructDec_SEMI,
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
	AST_Stmt_is_ID_COLON,
	AST_Stmt_is_BREAK_SEMI,
	AST_Stmt_is_RETURN_SEMI,
	AST_Stmt_is_RETURN_Exp_SEMI,
	AST_Stmt_is_GOTO_ID_SEMI,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt,
	AST_Stmt_is_WHILE_LP_Exp_RP_Stmt,
	AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI,
	AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt,
	AST_Stmt_is_FOR_LP_VarDef_Exp_SEMI_Exp_RP_Stmt,
	AST_Stmt_is_SWITCH_LP_Exp_RP_LC_CaseList_RC,
	AST_CaseList_is_CaseOne_CaseList,
	AST_CaseList_is_CaseOne,
	AST_CaseOne_is_CASE_Exp_COLON,
	AST_CaseOne_is_CASE_Exp_COLON_StmtList,
	AST_CaseOne_is_DEFAULT_COLON_StmtList,
	AST_VarDef_is_Specifier_DecList_SEMI,
	AST_DecList_is_Dec_COMMA_DecList,
	AST_DecList_is_Dec,
	AST_Dec_is_VarDec,
	AST_Dec_is_VarDec_ASSIGNOP_Initializer,
	AST_Initializer_is_Exp,
	AST_Initializer_is_LC_Exp_RC,
	AST_VarDec_is_ID,
	AST_VarDec_is_MULT_VarDec,
	AST_VarDec_is_VarDec_LB_NUM_RB,
	AST_Specifier_is_CommonSpec,
	AST_Specifier_is_StructDec,
	AST_Specifier_is_AnonyStructDec,
	AST_TypeRef_is_CommonSpec,
	AST_TypeRef_is_CommonSpec_StarList,
	AST_StarList_is_MULT,
	AST_StarList_is_MULT_StarList,
	AST_CommonSpec_is_TYPE,
	AST_CommonSpec_is_STRUCT_ID,
	AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList,
	AST_FuncCallArgList_is_FuncCallArg,
	AST_FuncCallArg_is_Exp,
	AST_TypeConversion_is_LP_TypeRef_RP,
	AST_Exp_is_ID,
	AST_Exp_is_ID_LP_RP,
	AST_Exp_is_ID_LP_FuncCallArgList_RP,
	AST_Exp_is_NIL,
	AST_Exp_is_TRUE,
	AST_Exp_is_FALSE,
	AST_Exp_is_NUM,
	AST_Exp_is_TypeConversion_Exp,
	AST_Exp_is_ADD_NUM,
	AST_Exp_is_SUB_NUM,
	AST_Exp_is_MULT_Exp,
	AST_Exp_is_AND_Exp,
	AST_Exp_is_NOT_Exp,
	AST_Exp_is_LNOT_Exp,
	AST_Exp_is_STRING,
	AST_Exp_is_SIZEOF_Exp,
	AST_Exp_is_Exp_INC,
	AST_Exp_is_Exp_DEC,
	AST_Exp_is_INC_Exp,
	AST_Exp_is_DEC_Exp,
	AST_Exp_is_Exp_LSHIFT_Exp,
	AST_Exp_is_Exp_RSHIFT_Exp,
	AST_Exp_is_Exp_ASSIGNOP_Exp,
	AST_Exp_is_Exp_ANDE_Exp,
	AST_Exp_is_Exp_ORE_Exp,
	AST_Exp_is_Exp_XORE_Exp,
	AST_Exp_is_Exp_LSHIFTE_Exp,
	AST_Exp_is_Exp_RSHIFTE_Exp,
	AST_Exp_is_Exp_ADDE_Exp,
	AST_Exp_is_Exp_SUBE_Exp,
	AST_Exp_is_Exp_MULTE_Exp,
	AST_Exp_is_Exp_DIVE_Exp,
	AST_Exp_is_Exp_MODE_Exp,
	AST_Exp_is_Exp_COMMA_Exp,
	AST_Exp_is_Exp_DOT_ID,
	AST_Exp_is_Exp_POINTER_ID,
	AST_Exp_is_Exp_ADD_Exp,
	AST_Exp_is_Exp_SUB_Exp,
	AST_Exp_is_Exp_MULT_Exp,
	AST_Exp_is_Exp_DIV_Exp,
	AST_Exp_is_Exp_MOD_Exp,
	AST_Exp_is_Exp_EQ_Exp,
	AST_Exp_is_Exp_LT_Exp,
	AST_Exp_is_Exp_LE_Exp,
	AST_Exp_is_Exp_NE_Exp,
	AST_Exp_is_Exp_GT_Exp,
	AST_Exp_is_Exp_GE_Exp,
	AST_Exp_is_Exp_LAND_Exp,
	AST_Exp_is_Exp_LOR_Exp,
	AST_Exp_is_Exp_AND_Exp,
	AST_Exp_is_Exp_OR_Exp,
	AST_Exp_is_Exp_XOR_Exp,
	AST_Exp_is_LP_Exp_RP,
	AST_Exp_is_Exp_LB_Exp_RB
};
        
typedef struct tagReduceRules {
    int nr_child;
    int root_type;
    char *str_rule;
    char *str_root;
} ReduceRules;

#ifdef __AST_C__

static ReduceRules syntax_rules[] = {
	[AST_NONTERMINALBEGIN] = {0, NONTERMINALBEGIN, "AST_NONTERMINALBEGIN", "NONTERMINALBEGIN"},
	[AST_Program_is_BlockList] = {1, Program, "AST_Program_is_BlockList", "Program"},
	[AST_BlockList_is_Block] = {1, BlockList, "AST_BlockList_is_Block", "BlockList"},
	[AST_BlockList_is_Block_BlockList] = {2, BlockList, "AST_BlockList_is_Block_BlockList", "BlockList"},
	[AST_Block_is_Specifier_FuncDec_CompSt] = {3, Block, "AST_Block_is_Specifier_FuncDec_CompSt", "Block"},
	[AST_Block_is_StructDec_SEMI] = {2, Block, "AST_Block_is_StructDec_SEMI", "Block"},
	[AST_Block_is_VarDef] = {1, Block, "AST_Block_is_VarDef", "Block"},
	[AST_IdList_is_VarDec_COMMA_IdList] = {3, IdList, "AST_IdList_is_VarDec_COMMA_IdList", "IdList"},
	[AST_IdList_is_VarDec] = {1, IdList, "AST_IdList_is_VarDec", "IdList"},
	[AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC] = {5, StructDec, "AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC", "StructDec"},
	[AST_AnonyStructDec_is_STRUCT_LC_StructDecVarList_RC] = {4, AnonyStructDec, "AST_AnonyStructDec_is_STRUCT_LC_StructDecVarList_RC", "AnonyStructDec"},
	[AST_StructDecVarList_is_StructDecVar_StructDecVarList] = {2, StructDecVarList, "AST_StructDecVarList_is_StructDecVar_StructDecVarList", "StructDecVarList"},
	[AST_StructDecVarList_is_StructDecVar] = {1, StructDecVarList, "AST_StructDecVarList_is_StructDecVar", "StructDecVarList"},
	[AST_StructDecVar_is_Specifier_IdList_SEMI] = {3, StructDecVar, "AST_StructDecVar_is_Specifier_IdList_SEMI", "StructDecVar"},
	[AST_StructDecVar_is_AnonyStructDec_SEMI] = {2, StructDecVar, "AST_StructDecVar_is_AnonyStructDec_SEMI", "StructDecVar"},
	[AST_StructDecVar_is_StructDec_SEMI] = {2, StructDecVar, "AST_StructDecVar_is_StructDec_SEMI", "StructDecVar"},
	[AST_FuncDec_is_ID_LP_RP] = {3, FuncDec, "AST_FuncDec_is_ID_LP_RP", "FuncDec"},
	[AST_FuncDec_is_ID_LP_FuncDefArgList_RP] = {4, FuncDec, "AST_FuncDec_is_ID_LP_FuncDefArgList_RP", "FuncDec"},
	[AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList] = {3, FuncDefArgList, "AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList", "FuncDefArgList"},
	[AST_FuncDefArgList_is_FuncDefArg] = {1, FuncDefArgList, "AST_FuncDefArgList_is_FuncDefArg", "FuncDefArgList"},
	[AST_FuncDefArg_is_Specifier_VarDec] = {2, FuncDefArg, "AST_FuncDefArg_is_Specifier_VarDec", "FuncDefArg"},
	[AST_CompSt_is_LC_StmtList_RC] = {3, CompSt, "AST_CompSt_is_LC_StmtList_RC", "CompSt"},
	[AST_StmtList_is_Stmt_StmtList] = {2, StmtList, "AST_StmtList_is_Stmt_StmtList", "StmtList"},
	[AST_StmtList_is_Stmt] = {1, StmtList, "AST_StmtList_is_Stmt", "StmtList"},
	[AST_Stmt_is_Exp_SEMI] = {2, Stmt, "AST_Stmt_is_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_VarDef] = {1, Stmt, "AST_Stmt_is_VarDef", "Stmt"},
	[AST_Stmt_is_CompSt] = {1, Stmt, "AST_Stmt_is_CompSt", "Stmt"},
	[AST_Stmt_is_SEMI] = {1, Stmt, "AST_Stmt_is_SEMI", "Stmt"},
	[AST_Stmt_is_ID_COLON] = {2, Stmt, "AST_Stmt_is_ID_COLON", "Stmt"},
	[AST_Stmt_is_BREAK_SEMI] = {2, Stmt, "AST_Stmt_is_BREAK_SEMI", "Stmt"},
	[AST_Stmt_is_RETURN_SEMI] = {2, Stmt, "AST_Stmt_is_RETURN_SEMI", "Stmt"},
	[AST_Stmt_is_RETURN_Exp_SEMI] = {3, Stmt, "AST_Stmt_is_RETURN_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_GOTO_ID_SEMI] = {3, Stmt, "AST_Stmt_is_GOTO_ID_SEMI", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_IF_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt] = {7, Stmt, "AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt", "Stmt"},
	[AST_Stmt_is_WHILE_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_WHILE_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI] = {7, Stmt, "AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI", "Stmt"},
	[AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt] = {9, Stmt, "AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_FOR_LP_VarDef_Exp_SEMI_Exp_RP_Stmt] = {8, Stmt, "AST_Stmt_is_FOR_LP_VarDef_Exp_SEMI_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_SWITCH_LP_Exp_RP_LC_CaseList_RC] = {7, Stmt, "AST_Stmt_is_SWITCH_LP_Exp_RP_LC_CaseList_RC", "Stmt"},
	[AST_CaseList_is_CaseOne_CaseList] = {2, CaseList, "AST_CaseList_is_CaseOne_CaseList", "CaseList"},
	[AST_CaseList_is_CaseOne] = {1, CaseList, "AST_CaseList_is_CaseOne", "CaseList"},
	[AST_CaseOne_is_CASE_Exp_COLON] = {3, CaseOne, "AST_CaseOne_is_CASE_Exp_COLON", "CaseOne"},
	[AST_CaseOne_is_CASE_Exp_COLON_StmtList] = {4, CaseOne, "AST_CaseOne_is_CASE_Exp_COLON_StmtList", "CaseOne"},
	[AST_CaseOne_is_DEFAULT_COLON_StmtList] = {3, CaseOne, "AST_CaseOne_is_DEFAULT_COLON_StmtList", "CaseOne"},
	[AST_VarDef_is_Specifier_DecList_SEMI] = {3, VarDef, "AST_VarDef_is_Specifier_DecList_SEMI", "VarDef"},
	[AST_DecList_is_Dec_COMMA_DecList] = {3, DecList, "AST_DecList_is_Dec_COMMA_DecList", "DecList"},
	[AST_DecList_is_Dec] = {1, DecList, "AST_DecList_is_Dec", "DecList"},
	[AST_Dec_is_VarDec] = {1, Dec, "AST_Dec_is_VarDec", "Dec"},
	[AST_Dec_is_VarDec_ASSIGNOP_Initializer] = {3, Dec, "AST_Dec_is_VarDec_ASSIGNOP_Initializer", "Dec"},
	[AST_Initializer_is_Exp] = {1, Initializer, "AST_Initializer_is_Exp", "Initializer"},
	[AST_Initializer_is_LC_Exp_RC] = {3, Initializer, "AST_Initializer_is_LC_Exp_RC", "Initializer"},
	[AST_VarDec_is_ID] = {1, VarDec, "AST_VarDec_is_ID", "VarDec"},
	[AST_VarDec_is_MULT_VarDec] = {2, VarDec, "AST_VarDec_is_MULT_VarDec", "VarDec"},
	[AST_VarDec_is_VarDec_LB_NUM_RB] = {4, VarDec, "AST_VarDec_is_VarDec_LB_NUM_RB", "VarDec"},
	[AST_Specifier_is_CommonSpec] = {1, Specifier, "AST_Specifier_is_CommonSpec", "Specifier"},
	[AST_Specifier_is_StructDec] = {1, Specifier, "AST_Specifier_is_StructDec", "Specifier"},
	[AST_Specifier_is_AnonyStructDec] = {1, Specifier, "AST_Specifier_is_AnonyStructDec", "Specifier"},
	[AST_TypeRef_is_CommonSpec] = {1, TypeRef, "AST_TypeRef_is_CommonSpec", "TypeRef"},
	[AST_TypeRef_is_CommonSpec_StarList] = {2, TypeRef, "AST_TypeRef_is_CommonSpec_StarList", "TypeRef"},
	[AST_StarList_is_MULT] = {1, StarList, "AST_StarList_is_MULT", "StarList"},
	[AST_StarList_is_MULT_StarList] = {2, StarList, "AST_StarList_is_MULT_StarList", "StarList"},
	[AST_CommonSpec_is_TYPE] = {1, CommonSpec, "AST_CommonSpec_is_TYPE", "CommonSpec"},
	[AST_CommonSpec_is_STRUCT_ID] = {2, CommonSpec, "AST_CommonSpec_is_STRUCT_ID", "CommonSpec"},
	[AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList] = {3, FuncCallArgList, "AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList", "FuncCallArgList"},
	[AST_FuncCallArgList_is_FuncCallArg] = {1, FuncCallArgList, "AST_FuncCallArgList_is_FuncCallArg", "FuncCallArgList"},
	[AST_FuncCallArg_is_Exp] = {1, FuncCallArg, "AST_FuncCallArg_is_Exp", "FuncCallArg"},
	[AST_TypeConversion_is_LP_TypeRef_RP] = {3, TypeConversion, "AST_TypeConversion_is_LP_TypeRef_RP", "TypeConversion"},
	[AST_Exp_is_ID] = {1, Exp, "AST_Exp_is_ID", "Exp"},
	[AST_Exp_is_ID_LP_RP] = {3, Exp, "AST_Exp_is_ID_LP_RP", "Exp"},
	[AST_Exp_is_ID_LP_FuncCallArgList_RP] = {4, Exp, "AST_Exp_is_ID_LP_FuncCallArgList_RP", "Exp"},
	[AST_Exp_is_NIL] = {1, Exp, "AST_Exp_is_NIL", "Exp"},
	[AST_Exp_is_TRUE] = {1, Exp, "AST_Exp_is_TRUE", "Exp"},
	[AST_Exp_is_FALSE] = {1, Exp, "AST_Exp_is_FALSE", "Exp"},
	[AST_Exp_is_NUM] = {1, Exp, "AST_Exp_is_NUM", "Exp"},
	[AST_Exp_is_TypeConversion_Exp] = {2, Exp, "AST_Exp_is_TypeConversion_Exp", "Exp"},
	[AST_Exp_is_ADD_NUM] = {2, Exp, "AST_Exp_is_ADD_NUM", "Exp"},
	[AST_Exp_is_SUB_NUM] = {2, Exp, "AST_Exp_is_SUB_NUM", "Exp"},
	[AST_Exp_is_MULT_Exp] = {2, Exp, "AST_Exp_is_MULT_Exp", "Exp"},
	[AST_Exp_is_AND_Exp] = {2, Exp, "AST_Exp_is_AND_Exp", "Exp"},
	[AST_Exp_is_NOT_Exp] = {2, Exp, "AST_Exp_is_NOT_Exp", "Exp"},
	[AST_Exp_is_LNOT_Exp] = {2, Exp, "AST_Exp_is_LNOT_Exp", "Exp"},
	[AST_Exp_is_STRING] = {1, Exp, "AST_Exp_is_STRING", "Exp"},
	[AST_Exp_is_SIZEOF_Exp] = {2, Exp, "AST_Exp_is_SIZEOF_Exp", "Exp"},
	[AST_Exp_is_Exp_INC] = {2, Exp, "AST_Exp_is_Exp_INC", "Exp"},
	[AST_Exp_is_Exp_DEC] = {2, Exp, "AST_Exp_is_Exp_DEC", "Exp"},
	[AST_Exp_is_INC_Exp] = {2, Exp, "AST_Exp_is_INC_Exp", "Exp"},
	[AST_Exp_is_DEC_Exp] = {2, Exp, "AST_Exp_is_DEC_Exp", "Exp"},
	[AST_Exp_is_Exp_LSHIFT_Exp] = {3, Exp, "AST_Exp_is_Exp_LSHIFT_Exp", "Exp"},
	[AST_Exp_is_Exp_RSHIFT_Exp] = {3, Exp, "AST_Exp_is_Exp_RSHIFT_Exp", "Exp"},
	[AST_Exp_is_Exp_ASSIGNOP_Exp] = {3, Exp, "AST_Exp_is_Exp_ASSIGNOP_Exp", "Exp"},
	[AST_Exp_is_Exp_ANDE_Exp] = {3, Exp, "AST_Exp_is_Exp_ANDE_Exp", "Exp"},
	[AST_Exp_is_Exp_ORE_Exp] = {3, Exp, "AST_Exp_is_Exp_ORE_Exp", "Exp"},
	[AST_Exp_is_Exp_XORE_Exp] = {3, Exp, "AST_Exp_is_Exp_XORE_Exp", "Exp"},
	[AST_Exp_is_Exp_LSHIFTE_Exp] = {3, Exp, "AST_Exp_is_Exp_LSHIFTE_Exp", "Exp"},
	[AST_Exp_is_Exp_RSHIFTE_Exp] = {3, Exp, "AST_Exp_is_Exp_RSHIFTE_Exp", "Exp"},
	[AST_Exp_is_Exp_ADDE_Exp] = {3, Exp, "AST_Exp_is_Exp_ADDE_Exp", "Exp"},
	[AST_Exp_is_Exp_SUBE_Exp] = {3, Exp, "AST_Exp_is_Exp_SUBE_Exp", "Exp"},
	[AST_Exp_is_Exp_MULTE_Exp] = {3, Exp, "AST_Exp_is_Exp_MULTE_Exp", "Exp"},
	[AST_Exp_is_Exp_DIVE_Exp] = {3, Exp, "AST_Exp_is_Exp_DIVE_Exp", "Exp"},
	[AST_Exp_is_Exp_MODE_Exp] = {3, Exp, "AST_Exp_is_Exp_MODE_Exp", "Exp"},
	[AST_Exp_is_Exp_COMMA_Exp] = {3, Exp, "AST_Exp_is_Exp_COMMA_Exp", "Exp"},
	[AST_Exp_is_Exp_DOT_ID] = {3, Exp, "AST_Exp_is_Exp_DOT_ID", "Exp"},
	[AST_Exp_is_Exp_POINTER_ID] = {3, Exp, "AST_Exp_is_Exp_POINTER_ID", "Exp"},
	[AST_Exp_is_Exp_ADD_Exp] = {3, Exp, "AST_Exp_is_Exp_ADD_Exp", "Exp"},
	[AST_Exp_is_Exp_SUB_Exp] = {3, Exp, "AST_Exp_is_Exp_SUB_Exp", "Exp"},
	[AST_Exp_is_Exp_MULT_Exp] = {3, Exp, "AST_Exp_is_Exp_MULT_Exp", "Exp"},
	[AST_Exp_is_Exp_DIV_Exp] = {3, Exp, "AST_Exp_is_Exp_DIV_Exp", "Exp"},
	[AST_Exp_is_Exp_MOD_Exp] = {3, Exp, "AST_Exp_is_Exp_MOD_Exp", "Exp"},
	[AST_Exp_is_Exp_EQ_Exp] = {3, Exp, "AST_Exp_is_Exp_EQ_Exp", "Exp"},
	[AST_Exp_is_Exp_LT_Exp] = {3, Exp, "AST_Exp_is_Exp_LT_Exp", "Exp"},
	[AST_Exp_is_Exp_LE_Exp] = {3, Exp, "AST_Exp_is_Exp_LE_Exp", "Exp"},
	[AST_Exp_is_Exp_NE_Exp] = {3, Exp, "AST_Exp_is_Exp_NE_Exp", "Exp"},
	[AST_Exp_is_Exp_GT_Exp] = {3, Exp, "AST_Exp_is_Exp_GT_Exp", "Exp"},
	[AST_Exp_is_Exp_GE_Exp] = {3, Exp, "AST_Exp_is_Exp_GE_Exp", "Exp"},
	[AST_Exp_is_Exp_LAND_Exp] = {3, Exp, "AST_Exp_is_Exp_LAND_Exp", "Exp"},
	[AST_Exp_is_Exp_LOR_Exp] = {3, Exp, "AST_Exp_is_Exp_LOR_Exp", "Exp"},
	[AST_Exp_is_Exp_AND_Exp] = {3, Exp, "AST_Exp_is_Exp_AND_Exp", "Exp"},
	[AST_Exp_is_Exp_OR_Exp] = {3, Exp, "AST_Exp_is_Exp_OR_Exp", "Exp"},
	[AST_Exp_is_Exp_XOR_Exp] = {3, Exp, "AST_Exp_is_Exp_XOR_Exp", "Exp"},
	[AST_Exp_is_LP_Exp_RP] = {3, Exp, "AST_Exp_is_LP_Exp_RP", "Exp"},
	[AST_Exp_is_Exp_LB_Exp_RB] = {4, Exp, "AST_Exp_is_Exp_LB_Exp_RB", "Exp"}
};

static char* str_lexval[] = {
	[SIZEOF] = "SIZEOF",
	[LSHIFT] = "LSHIFT",
	[RSHIFT] = "RSHIFT",
	[LSHIFTE] = "LSHIFTE",
	[RSHIFTE] = "RSHIFTE",
	[LT] = "LT",
	[LE] = "LE",
	[NE] = "NE",
	[EQ] = "EQ",
	[GE] = "GE",
	[GT] = "GT",
	[AND] = "AND",
	[OR] = "OR",
	[XOR] = "XOR",
	[NOT] = "NOT",
	[ANDE] = "ANDE",
	[ORE] = "ORE",
	[XORE] = "XORE",
	[LAND] = "LAND",
	[LOR] = "LOR",
	[LNOT] = "LNOT",
	[ADD] = "ADD",
	[SUB] = "SUB",
	[MULT] = "MULT",
	[DIV] = "DIV",
	[MOD] = "MOD",
	[ADDE] = "ADDE",
	[SUBE] = "SUBE",
	[MULTE] = "MULTE",
	[DIVE] = "DIVE",
	[MODE] = "MODE",
	[INC] = "INC",
	[DEC] = "DEC",
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
	[COLON] = "COLON",
	[IF] = "IF",
	[ELSE] = "ELSE",
	[DO] = "DO",
	[WHILE] = "WHILE",
	[FOR] = "FOR",
	[RETURN] = "RETURN",
	[SWITCH] = "SWITCH",
	[CASE] = "CASE",
	[BREAK] = "BREAK",
	[DEFAULT] = "DEFAULT",
	[GOTO] = "GOTO",
	[TYPE] = "TYPE",
	[VOID] = "VOID",
	[BOOL] = "BOOL",
	[CHAR] = "CHAR",
	[SHORT] = "SHORT",
	[INT] = "INT",
	[UNSIGNED] = "UNSIGNED",
	[FLOAT] = "FLOAT",
	[DOUBLE] = "DOUBLE",
	[INT8T] = "INT8T",
	[INT16T] = "INT16T",
	[INT32T] = "INT32T",
	[INT64T] = "INT64T",
	[UINT8T] = "UINT8T",
	[UINT16T] = "UINT16T",
	[UINT32T] = "UINT32T",
	[UINT64T] = "UINT64T",
	[SIZET] = "SIZET",
	[OFFT] = "OFFT",
	[UINTPTRT] = "UINTPTRT",
	[ENUM] = "ENUM",
	[UNION] = "UNION",
	[STRUCT] = "STRUCT",
	[NUM] = "NUM",
	[STRING] = "STRING",
	[NIL] = "NIL",
	[TRUE] = "TRUE",
	[FALSE] = "FALSE",
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
	[Initializer] = "Initializer",
	[TypeConversion] = "TypeConversion",
	[Specifier] = "Specifier",
	[TypeRef] = "TypeRef",
	[CommonSpec] = "CommonSpec",
	[StarList] = "StarList",
	[StructDec] = "StructDec",
	[AnonyStructDec] = "AnonyStructDec",
	[StructDecVar] = "StructDecVar",
	[StructDecVarList] = "StructDecVarList",
	[CaseList] = "CaseList",
	[CaseOne] = "CaseOne",
	[CompSt] = "CompSt",
	[Exp] = "Exp"
};

#endif

void __attribute__((noinline)) make_node(Node *root, int reduce_rule, int token, ...);
Node* new_node();
Node* new_sym_node(int lexval, YYLTYPE *yyinfo);
Node* __attribute__((noinline)) build_subast(int nodetype, YYLTYPE *yyinfo, ...);
void dump_ast(Node *root);
void print_ast(Node *root);
void print_exp(Node *exp);
Node* get_sibling_node(Node *root, int token);
Node* get_sibling_node_w(Node *root, int token);
Node* get_child_node_with_skip(Node *root, int token, int skip);
Node* get_child_node(Node *root, int token);
Node* get_child_node_with_skip_w(Node *root, int token, int skip);
Node* get_child_node_w(Node *root, int token);
Node* __attribute__((noinline))get_child_node_dw(Node *root, int depth, ...);
Node* find_child_node_with_depth(Node *root, int token, uint32_t depth);
Node* find_child_node(Node *root, int token);
Node* find_node_by_rule(Node *root, int rule);
int init_ast();

#endif
