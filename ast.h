#ifndef __AST_H__
#define __AST_H__

enum {
	NONTERMINALBEGIN = 512,
	Program,
	ExtDecln,
	ExtDeclnList,
	FuncDef,
	ExpList,
	Decln,
	DeclnSpec,
	InitorDeclrList,
	InitorDeclr,
	TypeSpec,
	CompSpec,
	CompType,
	CompDeclnList,
	CompDecln,
	CompDeclrList,
	CompDeclr,
	EnumSpec,
	EnumorList,
	Enumor,
	TypeQulfr,
	Declr,
	DirectDeclr,
	StarList,
	TypeQulfrList,
	ParaTypeList,
	ParaList,
	ParaDecln,
	IdList,
	TypeName,
	AbstDeclr,
	DirectAbstDeclr,
	Initor,
	InitorList,
	StmtList,
	ExpStmt,
	CompSt,
	DeclnList,
	Stmt,
	Exp
};

enum {
	AST_NONTERMINALBEGIN,
	AST_Program_is_ExtDeclnList,
	AST_ExtDeclnList_is_ExtDecln,
	AST_ExtDeclnList_is_ExtDeclnList_ExtDecln,
	AST_ExtDecln_is_FuncDef,
	AST_ExtDecln_is_Decln,
	AST_FuncDef_is_DeclnSpec_Declr_DeclnList_CompSt,
	AST_FuncDef_is_DeclnSpec_Declr_CompSt,
	AST_FuncDef_is_Declr_DeclnList_CompSt,
	AST_FuncDef_is_Declr_CompSt,
	AST_ExpList_is_Exp,
	AST_ExpList_is_ExpList_COMMA_Exp,
	AST_DeclnList_is_Decln,
	AST_DeclnList_is_DeclnList_Decln,
	AST_Decln_is_DeclnSpec_SEMI,
	AST_Decln_is_DeclnSpec_InitorDeclrList_SEMI,
	AST_DeclnSpec_is_TypeSpec,
	AST_DeclnSpec_is_TypeSpec_DeclnSpec,
	AST_DeclnSpec_is_TypeQulfr,
	AST_DeclnSpec_is_TypeQulfr_DeclnSpec,
	AST_InitorDeclrList_is_InitorDeclr,
	AST_InitorDeclrList_is_InitorDeclrList_COMMA_InitorDeclr,
	AST_InitorDeclr_is_Declr,
	AST_InitorDeclr_is_Declr_ASSIGNOP_Initor,
	AST_TypeQulfr_is_TYPEDEF,
	AST_TypeQulfr_is_EXTERN,
	AST_TypeQulfr_is_STATIC,
	AST_TypeQulfr_is_AUTO,
	AST_TypeQulfr_is_REGISTER,
	AST_TypeQulfr_is_CONST,
	AST_TypeQulfr_is_VOLATILE,
	AST_TypeSpec_is_VOID,
	AST_TypeSpec_is_BOOL,
	AST_TypeSpec_is_CHAR,
	AST_TypeSpec_is_SHORT,
	AST_TypeSpec_is_INT,
	AST_TypeSpec_is_LONG,
	AST_TypeSpec_is_FLOAT,
	AST_TypeSpec_is_DOUBLE,
	AST_TypeSpec_is_SIGNED,
	AST_TypeSpec_is_UNSIGNED,
	AST_TypeSpec_is_INT8T,
	AST_TypeSpec_is_INT16T,
	AST_TypeSpec_is_INT32T,
	AST_TypeSpec_is_INT64T,
	AST_TypeSpec_is_UINT8T,
	AST_TypeSpec_is_UINT16T,
	AST_TypeSpec_is_UINT32T,
	AST_TypeSpec_is_UINT64T,
	AST_TypeSpec_is_FLOAT32T,
	AST_TypeSpec_is_FLOAT64T,
	AST_TypeSpec_is_UINTPTRT,
	AST_TypeSpec_is_SIZET,
	AST_TypeSpec_is_OFFT,
	AST_TypeSpec_is_CompSpec,
	AST_TypeSpec_is_EnumSpec,
	AST_TypeSpec_is_TYPE_NAME,
	AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC,
	AST_CompSpec_is_CompType_LC_CompDeclnList_RC,
	AST_CompSpec_is_CompType_ID,
	AST_CompType_is_STRUCT,
	AST_CompType_is_UNION,
	AST_CompDeclnList_is_CompDecln,
	AST_CompDeclnList_is_CompDeclnList_CompDecln,
	AST_CompDecln_is_DeclnSpec_SEMI,
	AST_CompDecln_is_DeclnSpec_CompDeclrList_SEMI,
	AST_CompDeclrList_is_CompDeclr,
	AST_CompDeclrList_is_CompDeclrList_COMMA_CompDeclr,
	AST_CompDeclr_is_Declr,
	AST_CompDeclr_is_COLON_Exp,
	AST_CompDeclr_is_Declr_COLON_Exp,
	AST_EnumSpec_is_ENUM_LC_EnumorList_RC,
	AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC,
	AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC,
	AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC,
	AST_EnumSpec_is_ENUM_ID,
	AST_EnumorList_is_Enumor,
	AST_EnumorList_is_EnumorList_COMMA_Enumor,
	AST_Enumor_is_ID,
	AST_Enumor_is_ID_ASSIGNOP_Exp,
	AST_Declr_is_StarList_DirectDeclr,
	AST_Declr_is_DirectDeclr,
	AST_DirectDeclr_is_ID,
	AST_DirectDeclr_is_LP_Declr_RP,
	AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB,
	AST_DirectDeclr_is_DirectDeclr_LB_RB,
	AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP,
	AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP,
	AST_DirectDeclr_is_DirectDeclr_LP_RP,
	AST_StarList_is_MULT,
	AST_StarList_is_MULT_TypeQulfrList,
	AST_StarList_is_MULT_StarList,
	AST_StarList_is_MULT_TypeQulfrList_StarList,
	AST_TypeQulfrList_is_TypeQulfr,
	AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr,
	AST_ParaTypeList_is_ParaList,
	AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS,
	AST_ParaList_is_ParaDecln,
	AST_ParaList_is_ParaList_COMMA_ParaDecln,
	AST_ParaDecln_is_DeclnSpec_Declr,
	AST_ParaDecln_is_DeclnSpec_AbstDeclr,
	AST_ParaDecln_is_DeclnSpec,
	AST_IdList_is_ID,
	AST_IdList_is_IdList_COMMA_ID,
	AST_TypeName_is_DeclnSpec,
	AST_TypeName_is_DeclnSpec_AbstDeclr,
	AST_AbstDeclr_is_StarList,
	AST_AbstDeclr_is_DirectAbstDeclr,
	AST_AbstDeclr_is_StarList_DirectAbstDeclr,
	AST_DirectAbstDeclr_is_LP_AbstDeclr_RP,
	AST_DirectAbstDeclr_is_LB_RB,
	AST_DirectAbstDeclr_is_LB_Exp_RB,
	AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_RB,
	AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_Exp_RB,
	AST_DirectAbstDeclr_is_LP_RP,
	AST_DirectAbstDeclr_is_LP_ParaTypeList_RP,
	AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_RP,
	AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_ParaTypeList_RP,
	AST_Initor_is_Exp,
	AST_Initor_is_LB_Exp_RB_ASSIGNOP_Exp,
	AST_Initor_is_LC_InitorList_RC,
	AST_Initor_is_LC_InitorList_COMMA_RC,
	AST_InitorList_is_Initor,
	AST_InitorList_is_InitorList_COMMA_Initor,
	AST_StmtList_is_Stmt,
	AST_StmtList_is_StmtList_Stmt,
	AST_ExpStmt_is_Decln,
	AST_ExpStmt_is_Exp_SEMI,
	AST_ExpStmt_is_SEMI,
	AST_CompSt_is_LC_RC,
	AST_CompSt_is_LC_StmtList_RC,
	AST_Stmt_is_SEMI,
	AST_Stmt_is_Decln,
	AST_Stmt_is_Exp_SEMI,
	AST_Stmt_is_CompSt,
	AST_Stmt_is_GOTO_ID_SEMI,
	AST_Stmt_is_ID_COLON,
	AST_Stmt_is_CONTINUE_SEMI,
	AST_Stmt_is_BREAK_SEMI,
	AST_Stmt_is_RETURN_SEMI,
	AST_Stmt_is_RETURN_Exp_SEMI,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt,
	AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt,
	AST_Stmt_is_SWITCH_LP_Exp_RP_Stmt,
	AST_Stmt_is_CASE_Exp_COLON_Stmt,
	AST_Stmt_is_DEFAULT_COLON_Stmt,
	AST_Stmt_is_WHILE_LP_Exp_RP_Stmt,
	AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI,
	AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_RP_Stmt,
	AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_Exp_RP_Stmt,
	AST_Exp_is_ID,
	AST_Exp_is_NUM,
	AST_Exp_is_NIL,
	AST_Exp_is_TRUE,
	AST_Exp_is_FALSE,
	AST_Exp_is_STRING,
	AST_Exp_is_LITERAL,
	AST_Exp_is_LP_Exp_RP,
	AST_Exp_is_Exp_LB_Exp_RB,
	AST_Exp_is_Exp_LP_RP,
	AST_Exp_is_Exp_LP_ExpList_RP,
	AST_Exp_is_Exp_DOT_ID,
	AST_Exp_is_Exp_PTR_ID,
	AST_Exp_is_Exp_INC,
	AST_Exp_is_Exp_DEC,
	AST_Exp_is_INC_Exp,
	AST_Exp_is_DEC_Exp,
	AST_Exp_is_AND_Exp,
	AST_Exp_is_MULT_Exp,
	AST_Exp_is_ADD_Exp,
	AST_Exp_is_SUB_Exp,
	AST_Exp_is_NOT_Exp,
	AST_Exp_is_LNOT_Exp,
	AST_Exp_is_SIZEOF_Exp,
	AST_Exp_is_SIZEOF_LP_TypeName_RP,
	AST_Exp_is_LP_TypeName_RP_Exp,
	AST_Exp_is_Exp_MULT_Exp,
	AST_Exp_is_Exp_DIV_Exp,
	AST_Exp_is_Exp_MOD_Exp,
	AST_Exp_is_Exp_ADD_Exp,
	AST_Exp_is_Exp_SUB_Exp,
	AST_Exp_is_Exp_LSHIFT_Exp,
	AST_Exp_is_Exp_RSHIFT_Exp,
	AST_Exp_is_Exp_LT_Exp,
	AST_Exp_is_Exp_GT_Exp,
	AST_Exp_is_Exp_LE_Exp,
	AST_Exp_is_Exp_GE_Exp,
	AST_Exp_is_Exp_EQ_Exp,
	AST_Exp_is_Exp_NE_Exp,
	AST_Exp_is_Exp_AND_Exp,
	AST_Exp_is_Exp_XOR_Exp,
	AST_Exp_is_Exp_OR_Exp,
	AST_Exp_is_Exp_LAND_Exp,
	AST_Exp_is_Exp_LOR_Exp,
	AST_Exp_is_Exp_QOP_Exp_COLON_Exp,
	AST_Exp_is_Exp_ASSIGNOP_Exp,
	AST_Exp_is_Exp_MULTE_Exp,
	AST_Exp_is_Exp_DIVE_Exp,
	AST_Exp_is_Exp_MODE_Exp,
	AST_Exp_is_Exp_ADDE_Exp,
	AST_Exp_is_Exp_SUBE_Exp,
	AST_Exp_is_Exp_LSHIFTE_Exp,
	AST_Exp_is_Exp_RSHIFTE_Exp,
	AST_Exp_is_Exp_ANDE_Exp,
	AST_Exp_is_Exp_XORE_Exp,
	AST_Exp_is_Exp_ORE_Exp,
	AST_Exp_is_Exp_COMMA_Exp
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
	[AST_Program_is_ExtDeclnList] = {1, Program, "AST_Program_is_ExtDeclnList", "Program"},
	[AST_ExtDeclnList_is_ExtDecln] = {1, ExtDeclnList, "AST_ExtDeclnList_is_ExtDecln", "ExtDeclnList"},
	[AST_ExtDeclnList_is_ExtDeclnList_ExtDecln] = {2, ExtDeclnList, "AST_ExtDeclnList_is_ExtDeclnList_ExtDecln", "ExtDeclnList"},
	[AST_ExtDecln_is_FuncDef] = {1, ExtDecln, "AST_ExtDecln_is_FuncDef", "ExtDecln"},
	[AST_ExtDecln_is_Decln] = {1, ExtDecln, "AST_ExtDecln_is_Decln", "ExtDecln"},
	[AST_FuncDef_is_DeclnSpec_Declr_DeclnList_CompSt] = {4, FuncDef, "AST_FuncDef_is_DeclnSpec_Declr_DeclnList_CompSt", "FuncDef"},
	[AST_FuncDef_is_DeclnSpec_Declr_CompSt] = {3, FuncDef, "AST_FuncDef_is_DeclnSpec_Declr_CompSt", "FuncDef"},
	[AST_FuncDef_is_Declr_DeclnList_CompSt] = {3, FuncDef, "AST_FuncDef_is_Declr_DeclnList_CompSt", "FuncDef"},
	[AST_FuncDef_is_Declr_CompSt] = {2, FuncDef, "AST_FuncDef_is_Declr_CompSt", "FuncDef"},
	[AST_ExpList_is_Exp] = {1, ExpList, "AST_ExpList_is_Exp", "ExpList"},
	[AST_ExpList_is_ExpList_COMMA_Exp] = {3, ExpList, "AST_ExpList_is_ExpList_COMMA_Exp", "ExpList"},
	[AST_DeclnList_is_Decln] = {1, DeclnList, "AST_DeclnList_is_Decln", "DeclnList"},
	[AST_DeclnList_is_DeclnList_Decln] = {2, DeclnList, "AST_DeclnList_is_DeclnList_Decln", "DeclnList"},
	[AST_Decln_is_DeclnSpec_SEMI] = {2, Decln, "AST_Decln_is_DeclnSpec_SEMI", "Decln"},
	[AST_Decln_is_DeclnSpec_InitorDeclrList_SEMI] = {3, Decln, "AST_Decln_is_DeclnSpec_InitorDeclrList_SEMI", "Decln"},
	[AST_DeclnSpec_is_TypeSpec] = {1, DeclnSpec, "AST_DeclnSpec_is_TypeSpec", "DeclnSpec"},
	[AST_DeclnSpec_is_TypeSpec_DeclnSpec] = {2, DeclnSpec, "AST_DeclnSpec_is_TypeSpec_DeclnSpec", "DeclnSpec"},
	[AST_DeclnSpec_is_TypeQulfr] = {1, DeclnSpec, "AST_DeclnSpec_is_TypeQulfr", "DeclnSpec"},
	[AST_DeclnSpec_is_TypeQulfr_DeclnSpec] = {2, DeclnSpec, "AST_DeclnSpec_is_TypeQulfr_DeclnSpec", "DeclnSpec"},
	[AST_InitorDeclrList_is_InitorDeclr] = {1, InitorDeclrList, "AST_InitorDeclrList_is_InitorDeclr", "InitorDeclrList"},
	[AST_InitorDeclrList_is_InitorDeclrList_COMMA_InitorDeclr] = {3, InitorDeclrList, "AST_InitorDeclrList_is_InitorDeclrList_COMMA_InitorDeclr", "InitorDeclrList"},
	[AST_InitorDeclr_is_Declr] = {1, InitorDeclr, "AST_InitorDeclr_is_Declr", "InitorDeclr"},
	[AST_InitorDeclr_is_Declr_ASSIGNOP_Initor] = {3, InitorDeclr, "AST_InitorDeclr_is_Declr_ASSIGNOP_Initor", "InitorDeclr"},
	[AST_TypeQulfr_is_TYPEDEF] = {1, TypeQulfr, "AST_TypeQulfr_is_TYPEDEF", "TypeQulfr"},
	[AST_TypeQulfr_is_EXTERN] = {1, TypeQulfr, "AST_TypeQulfr_is_EXTERN", "TypeQulfr"},
	[AST_TypeQulfr_is_STATIC] = {1, TypeQulfr, "AST_TypeQulfr_is_STATIC", "TypeQulfr"},
	[AST_TypeQulfr_is_AUTO] = {1, TypeQulfr, "AST_TypeQulfr_is_AUTO", "TypeQulfr"},
	[AST_TypeQulfr_is_REGISTER] = {1, TypeQulfr, "AST_TypeQulfr_is_REGISTER", "TypeQulfr"},
	[AST_TypeQulfr_is_CONST] = {1, TypeQulfr, "AST_TypeQulfr_is_CONST", "TypeQulfr"},
	[AST_TypeQulfr_is_VOLATILE] = {1, TypeQulfr, "AST_TypeQulfr_is_VOLATILE", "TypeQulfr"},
	[AST_TypeSpec_is_VOID] = {1, TypeSpec, "AST_TypeSpec_is_VOID", "TypeSpec"},
	[AST_TypeSpec_is_BOOL] = {1, TypeSpec, "AST_TypeSpec_is_BOOL", "TypeSpec"},
	[AST_TypeSpec_is_CHAR] = {1, TypeSpec, "AST_TypeSpec_is_CHAR", "TypeSpec"},
	[AST_TypeSpec_is_SHORT] = {1, TypeSpec, "AST_TypeSpec_is_SHORT", "TypeSpec"},
	[AST_TypeSpec_is_INT] = {1, TypeSpec, "AST_TypeSpec_is_INT", "TypeSpec"},
	[AST_TypeSpec_is_LONG] = {1, TypeSpec, "AST_TypeSpec_is_LONG", "TypeSpec"},
	[AST_TypeSpec_is_FLOAT] = {1, TypeSpec, "AST_TypeSpec_is_FLOAT", "TypeSpec"},
	[AST_TypeSpec_is_DOUBLE] = {1, TypeSpec, "AST_TypeSpec_is_DOUBLE", "TypeSpec"},
	[AST_TypeSpec_is_SIGNED] = {1, TypeSpec, "AST_TypeSpec_is_SIGNED", "TypeSpec"},
	[AST_TypeSpec_is_UNSIGNED] = {1, TypeSpec, "AST_TypeSpec_is_UNSIGNED", "TypeSpec"},
	[AST_TypeSpec_is_INT8T] = {1, TypeSpec, "AST_TypeSpec_is_INT8T", "TypeSpec"},
	[AST_TypeSpec_is_INT16T] = {1, TypeSpec, "AST_TypeSpec_is_INT16T", "TypeSpec"},
	[AST_TypeSpec_is_INT32T] = {1, TypeSpec, "AST_TypeSpec_is_INT32T", "TypeSpec"},
	[AST_TypeSpec_is_INT64T] = {1, TypeSpec, "AST_TypeSpec_is_INT64T", "TypeSpec"},
	[AST_TypeSpec_is_UINT8T] = {1, TypeSpec, "AST_TypeSpec_is_UINT8T", "TypeSpec"},
	[AST_TypeSpec_is_UINT16T] = {1, TypeSpec, "AST_TypeSpec_is_UINT16T", "TypeSpec"},
	[AST_TypeSpec_is_UINT32T] = {1, TypeSpec, "AST_TypeSpec_is_UINT32T", "TypeSpec"},
	[AST_TypeSpec_is_UINT64T] = {1, TypeSpec, "AST_TypeSpec_is_UINT64T", "TypeSpec"},
	[AST_TypeSpec_is_FLOAT32T] = {1, TypeSpec, "AST_TypeSpec_is_FLOAT32T", "TypeSpec"},
	[AST_TypeSpec_is_FLOAT64T] = {1, TypeSpec, "AST_TypeSpec_is_FLOAT64T", "TypeSpec"},
	[AST_TypeSpec_is_UINTPTRT] = {1, TypeSpec, "AST_TypeSpec_is_UINTPTRT", "TypeSpec"},
	[AST_TypeSpec_is_SIZET] = {1, TypeSpec, "AST_TypeSpec_is_SIZET", "TypeSpec"},
	[AST_TypeSpec_is_OFFT] = {1, TypeSpec, "AST_TypeSpec_is_OFFT", "TypeSpec"},
	[AST_TypeSpec_is_CompSpec] = {1, TypeSpec, "AST_TypeSpec_is_CompSpec", "TypeSpec"},
	[AST_TypeSpec_is_EnumSpec] = {1, TypeSpec, "AST_TypeSpec_is_EnumSpec", "TypeSpec"},
	[AST_TypeSpec_is_TYPE_NAME] = {1, TypeSpec, "AST_TypeSpec_is_TYPE_NAME", "TypeSpec"},
	[AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC] = {5, CompSpec, "AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC", "CompSpec"},
	[AST_CompSpec_is_CompType_LC_CompDeclnList_RC] = {4, CompSpec, "AST_CompSpec_is_CompType_LC_CompDeclnList_RC", "CompSpec"},
	[AST_CompSpec_is_CompType_ID] = {2, CompSpec, "AST_CompSpec_is_CompType_ID", "CompSpec"},
	[AST_CompType_is_STRUCT] = {1, CompType, "AST_CompType_is_STRUCT", "CompType"},
	[AST_CompType_is_UNION] = {1, CompType, "AST_CompType_is_UNION", "CompType"},
	[AST_CompDeclnList_is_CompDecln] = {1, CompDeclnList, "AST_CompDeclnList_is_CompDecln", "CompDeclnList"},
	[AST_CompDeclnList_is_CompDeclnList_CompDecln] = {2, CompDeclnList, "AST_CompDeclnList_is_CompDeclnList_CompDecln", "CompDeclnList"},
	[AST_CompDecln_is_DeclnSpec_SEMI] = {2, CompDecln, "AST_CompDecln_is_DeclnSpec_SEMI", "CompDecln"},
	[AST_CompDecln_is_DeclnSpec_CompDeclrList_SEMI] = {3, CompDecln, "AST_CompDecln_is_DeclnSpec_CompDeclrList_SEMI", "CompDecln"},
	[AST_CompDeclrList_is_CompDeclr] = {1, CompDeclrList, "AST_CompDeclrList_is_CompDeclr", "CompDeclrList"},
	[AST_CompDeclrList_is_CompDeclrList_COMMA_CompDeclr] = {3, CompDeclrList, "AST_CompDeclrList_is_CompDeclrList_COMMA_CompDeclr", "CompDeclrList"},
	[AST_CompDeclr_is_Declr] = {1, CompDeclr, "AST_CompDeclr_is_Declr", "CompDeclr"},
	[AST_CompDeclr_is_COLON_Exp] = {2, CompDeclr, "AST_CompDeclr_is_COLON_Exp", "CompDeclr"},
	[AST_CompDeclr_is_Declr_COLON_Exp] = {3, CompDeclr, "AST_CompDeclr_is_Declr_COLON_Exp", "CompDeclr"},
	[AST_EnumSpec_is_ENUM_LC_EnumorList_RC] = {4, EnumSpec, "AST_EnumSpec_is_ENUM_LC_EnumorList_RC", "EnumSpec"},
	[AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC] = {5, EnumSpec, "AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC", "EnumSpec"},
	[AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC] = {5, EnumSpec, "AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC", "EnumSpec"},
	[AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC] = {6, EnumSpec, "AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC", "EnumSpec"},
	[AST_EnumSpec_is_ENUM_ID] = {2, EnumSpec, "AST_EnumSpec_is_ENUM_ID", "EnumSpec"},
	[AST_EnumorList_is_Enumor] = {1, EnumorList, "AST_EnumorList_is_Enumor", "EnumorList"},
	[AST_EnumorList_is_EnumorList_COMMA_Enumor] = {3, EnumorList, "AST_EnumorList_is_EnumorList_COMMA_Enumor", "EnumorList"},
	[AST_Enumor_is_ID] = {1, Enumor, "AST_Enumor_is_ID", "Enumor"},
	[AST_Enumor_is_ID_ASSIGNOP_Exp] = {3, Enumor, "AST_Enumor_is_ID_ASSIGNOP_Exp", "Enumor"},
	[AST_Declr_is_StarList_DirectDeclr] = {2, Declr, "AST_Declr_is_StarList_DirectDeclr", "Declr"},
	[AST_Declr_is_DirectDeclr] = {1, Declr, "AST_Declr_is_DirectDeclr", "Declr"},
	[AST_DirectDeclr_is_ID] = {1, DirectDeclr, "AST_DirectDeclr_is_ID", "DirectDeclr"},
	[AST_DirectDeclr_is_LP_Declr_RP] = {3, DirectDeclr, "AST_DirectDeclr_is_LP_Declr_RP", "DirectDeclr"},
	[AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB] = {4, DirectDeclr, "AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB", "DirectDeclr"},
	[AST_DirectDeclr_is_DirectDeclr_LB_RB] = {3, DirectDeclr, "AST_DirectDeclr_is_DirectDeclr_LB_RB", "DirectDeclr"},
	[AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP] = {4, DirectDeclr, "AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP", "DirectDeclr"},
	[AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP] = {4, DirectDeclr, "AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP", "DirectDeclr"},
	[AST_DirectDeclr_is_DirectDeclr_LP_RP] = {3, DirectDeclr, "AST_DirectDeclr_is_DirectDeclr_LP_RP", "DirectDeclr"},
	[AST_StarList_is_MULT] = {1, StarList, "AST_StarList_is_MULT", "StarList"},
	[AST_StarList_is_MULT_TypeQulfrList] = {2, StarList, "AST_StarList_is_MULT_TypeQulfrList", "StarList"},
	[AST_StarList_is_MULT_StarList] = {2, StarList, "AST_StarList_is_MULT_StarList", "StarList"},
	[AST_StarList_is_MULT_TypeQulfrList_StarList] = {3, StarList, "AST_StarList_is_MULT_TypeQulfrList_StarList", "StarList"},
	[AST_TypeQulfrList_is_TypeQulfr] = {1, TypeQulfrList, "AST_TypeQulfrList_is_TypeQulfr", "TypeQulfrList"},
	[AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr] = {2, TypeQulfrList, "AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr", "TypeQulfrList"},
	[AST_ParaTypeList_is_ParaList] = {1, ParaTypeList, "AST_ParaTypeList_is_ParaList", "ParaTypeList"},
	[AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS] = {3, ParaTypeList, "AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS", "ParaTypeList"},
	[AST_ParaList_is_ParaDecln] = {1, ParaList, "AST_ParaList_is_ParaDecln", "ParaList"},
	[AST_ParaList_is_ParaList_COMMA_ParaDecln] = {3, ParaList, "AST_ParaList_is_ParaList_COMMA_ParaDecln", "ParaList"},
	[AST_ParaDecln_is_DeclnSpec_Declr] = {2, ParaDecln, "AST_ParaDecln_is_DeclnSpec_Declr", "ParaDecln"},
	[AST_ParaDecln_is_DeclnSpec_AbstDeclr] = {2, ParaDecln, "AST_ParaDecln_is_DeclnSpec_AbstDeclr", "ParaDecln"},
	[AST_ParaDecln_is_DeclnSpec] = {1, ParaDecln, "AST_ParaDecln_is_DeclnSpec", "ParaDecln"},
	[AST_IdList_is_ID] = {1, IdList, "AST_IdList_is_ID", "IdList"},
	[AST_IdList_is_IdList_COMMA_ID] = {3, IdList, "AST_IdList_is_IdList_COMMA_ID", "IdList"},
	[AST_TypeName_is_DeclnSpec] = {1, TypeName, "AST_TypeName_is_DeclnSpec", "TypeName"},
	[AST_TypeName_is_DeclnSpec_AbstDeclr] = {2, TypeName, "AST_TypeName_is_DeclnSpec_AbstDeclr", "TypeName"},
	[AST_AbstDeclr_is_StarList] = {1, AbstDeclr, "AST_AbstDeclr_is_StarList", "AbstDeclr"},
	[AST_AbstDeclr_is_DirectAbstDeclr] = {1, AbstDeclr, "AST_AbstDeclr_is_DirectAbstDeclr", "AbstDeclr"},
	[AST_AbstDeclr_is_StarList_DirectAbstDeclr] = {2, AbstDeclr, "AST_AbstDeclr_is_StarList_DirectAbstDeclr", "AbstDeclr"},
	[AST_DirectAbstDeclr_is_LP_AbstDeclr_RP] = {3, DirectAbstDeclr, "AST_DirectAbstDeclr_is_LP_AbstDeclr_RP", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_LB_RB] = {2, DirectAbstDeclr, "AST_DirectAbstDeclr_is_LB_RB", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_LB_Exp_RB] = {3, DirectAbstDeclr, "AST_DirectAbstDeclr_is_LB_Exp_RB", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_RB] = {3, DirectAbstDeclr, "AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_RB", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_Exp_RB] = {4, DirectAbstDeclr, "AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_Exp_RB", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_LP_RP] = {2, DirectAbstDeclr, "AST_DirectAbstDeclr_is_LP_RP", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_LP_ParaTypeList_RP] = {3, DirectAbstDeclr, "AST_DirectAbstDeclr_is_LP_ParaTypeList_RP", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_RP] = {3, DirectAbstDeclr, "AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_RP", "DirectAbstDeclr"},
	[AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_ParaTypeList_RP] = {4, DirectAbstDeclr, "AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_ParaTypeList_RP", "DirectAbstDeclr"},
	[AST_Initor_is_Exp] = {1, Initor, "AST_Initor_is_Exp", "Initor"},
	[AST_Initor_is_LB_Exp_RB_ASSIGNOP_Exp] = {5, Initor, "AST_Initor_is_LB_Exp_RB_ASSIGNOP_Exp", "Initor"},
	[AST_Initor_is_LC_InitorList_RC] = {3, Initor, "AST_Initor_is_LC_InitorList_RC", "Initor"},
	[AST_Initor_is_LC_InitorList_COMMA_RC] = {4, Initor, "AST_Initor_is_LC_InitorList_COMMA_RC", "Initor"},
	[AST_InitorList_is_Initor] = {1, InitorList, "AST_InitorList_is_Initor", "InitorList"},
	[AST_InitorList_is_InitorList_COMMA_Initor] = {3, InitorList, "AST_InitorList_is_InitorList_COMMA_Initor", "InitorList"},
	[AST_StmtList_is_Stmt] = {1, StmtList, "AST_StmtList_is_Stmt", "StmtList"},
	[AST_StmtList_is_StmtList_Stmt] = {2, StmtList, "AST_StmtList_is_StmtList_Stmt", "StmtList"},
	[AST_ExpStmt_is_Decln] = {1, ExpStmt, "AST_ExpStmt_is_Decln", "ExpStmt"},
	[AST_ExpStmt_is_Exp_SEMI] = {2, ExpStmt, "AST_ExpStmt_is_Exp_SEMI", "ExpStmt"},
	[AST_ExpStmt_is_SEMI] = {1, ExpStmt, "AST_ExpStmt_is_SEMI", "ExpStmt"},
	[AST_CompSt_is_LC_RC] = {2, CompSt, "AST_CompSt_is_LC_RC", "CompSt"},
	[AST_CompSt_is_LC_StmtList_RC] = {3, CompSt, "AST_CompSt_is_LC_StmtList_RC", "CompSt"},
	[AST_Stmt_is_SEMI] = {1, Stmt, "AST_Stmt_is_SEMI", "Stmt"},
	[AST_Stmt_is_Decln] = {1, Stmt, "AST_Stmt_is_Decln", "Stmt"},
	[AST_Stmt_is_Exp_SEMI] = {2, Stmt, "AST_Stmt_is_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_CompSt] = {1, Stmt, "AST_Stmt_is_CompSt", "Stmt"},
	[AST_Stmt_is_GOTO_ID_SEMI] = {3, Stmt, "AST_Stmt_is_GOTO_ID_SEMI", "Stmt"},
	[AST_Stmt_is_ID_COLON] = {2, Stmt, "AST_Stmt_is_ID_COLON", "Stmt"},
	[AST_Stmt_is_CONTINUE_SEMI] = {2, Stmt, "AST_Stmt_is_CONTINUE_SEMI", "Stmt"},
	[AST_Stmt_is_BREAK_SEMI] = {2, Stmt, "AST_Stmt_is_BREAK_SEMI", "Stmt"},
	[AST_Stmt_is_RETURN_SEMI] = {2, Stmt, "AST_Stmt_is_RETURN_SEMI", "Stmt"},
	[AST_Stmt_is_RETURN_Exp_SEMI] = {3, Stmt, "AST_Stmt_is_RETURN_Exp_SEMI", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_IF_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt] = {7, Stmt, "AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt", "Stmt"},
	[AST_Stmt_is_SWITCH_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_SWITCH_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_CASE_Exp_COLON_Stmt] = {4, Stmt, "AST_Stmt_is_CASE_Exp_COLON_Stmt", "Stmt"},
	[AST_Stmt_is_DEFAULT_COLON_Stmt] = {3, Stmt, "AST_Stmt_is_DEFAULT_COLON_Stmt", "Stmt"},
	[AST_Stmt_is_WHILE_LP_Exp_RP_Stmt] = {5, Stmt, "AST_Stmt_is_WHILE_LP_Exp_RP_Stmt", "Stmt"},
	[AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI] = {7, Stmt, "AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI", "Stmt"},
	[AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_RP_Stmt] = {6, Stmt, "AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_RP_Stmt", "Stmt"},
	[AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_Exp_RP_Stmt] = {7, Stmt, "AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_Exp_RP_Stmt", "Stmt"},
	[AST_Exp_is_ID] = {1, Exp, "AST_Exp_is_ID", "Exp"},
	[AST_Exp_is_NUM] = {1, Exp, "AST_Exp_is_NUM", "Exp"},
	[AST_Exp_is_NIL] = {1, Exp, "AST_Exp_is_NIL", "Exp"},
	[AST_Exp_is_TRUE] = {1, Exp, "AST_Exp_is_TRUE", "Exp"},
	[AST_Exp_is_FALSE] = {1, Exp, "AST_Exp_is_FALSE", "Exp"},
	[AST_Exp_is_STRING] = {1, Exp, "AST_Exp_is_STRING", "Exp"},
	[AST_Exp_is_LITERAL] = {1, Exp, "AST_Exp_is_LITERAL", "Exp"},
	[AST_Exp_is_LP_Exp_RP] = {3, Exp, "AST_Exp_is_LP_Exp_RP", "Exp"},
	[AST_Exp_is_Exp_LB_Exp_RB] = {4, Exp, "AST_Exp_is_Exp_LB_Exp_RB", "Exp"},
	[AST_Exp_is_Exp_LP_RP] = {3, Exp, "AST_Exp_is_Exp_LP_RP", "Exp"},
	[AST_Exp_is_Exp_LP_ExpList_RP] = {4, Exp, "AST_Exp_is_Exp_LP_ExpList_RP", "Exp"},
	[AST_Exp_is_Exp_DOT_ID] = {3, Exp, "AST_Exp_is_Exp_DOT_ID", "Exp"},
	[AST_Exp_is_Exp_PTR_ID] = {3, Exp, "AST_Exp_is_Exp_PTR_ID", "Exp"},
	[AST_Exp_is_Exp_INC] = {2, Exp, "AST_Exp_is_Exp_INC", "Exp"},
	[AST_Exp_is_Exp_DEC] = {2, Exp, "AST_Exp_is_Exp_DEC", "Exp"},
	[AST_Exp_is_INC_Exp] = {2, Exp, "AST_Exp_is_INC_Exp", "Exp"},
	[AST_Exp_is_DEC_Exp] = {2, Exp, "AST_Exp_is_DEC_Exp", "Exp"},
	[AST_Exp_is_AND_Exp] = {2, Exp, "AST_Exp_is_AND_Exp", "Exp"},
	[AST_Exp_is_MULT_Exp] = {2, Exp, "AST_Exp_is_MULT_Exp", "Exp"},
	[AST_Exp_is_ADD_Exp] = {2, Exp, "AST_Exp_is_ADD_Exp", "Exp"},
	[AST_Exp_is_SUB_Exp] = {2, Exp, "AST_Exp_is_SUB_Exp", "Exp"},
	[AST_Exp_is_NOT_Exp] = {2, Exp, "AST_Exp_is_NOT_Exp", "Exp"},
	[AST_Exp_is_LNOT_Exp] = {2, Exp, "AST_Exp_is_LNOT_Exp", "Exp"},
	[AST_Exp_is_SIZEOF_Exp] = {2, Exp, "AST_Exp_is_SIZEOF_Exp", "Exp"},
	[AST_Exp_is_SIZEOF_LP_TypeName_RP] = {4, Exp, "AST_Exp_is_SIZEOF_LP_TypeName_RP", "Exp"},
	[AST_Exp_is_LP_TypeName_RP_Exp] = {4, Exp, "AST_Exp_is_LP_TypeName_RP_Exp", "Exp"},
	[AST_Exp_is_Exp_MULT_Exp] = {3, Exp, "AST_Exp_is_Exp_MULT_Exp", "Exp"},
	[AST_Exp_is_Exp_DIV_Exp] = {3, Exp, "AST_Exp_is_Exp_DIV_Exp", "Exp"},
	[AST_Exp_is_Exp_MOD_Exp] = {3, Exp, "AST_Exp_is_Exp_MOD_Exp", "Exp"},
	[AST_Exp_is_Exp_ADD_Exp] = {3, Exp, "AST_Exp_is_Exp_ADD_Exp", "Exp"},
	[AST_Exp_is_Exp_SUB_Exp] = {3, Exp, "AST_Exp_is_Exp_SUB_Exp", "Exp"},
	[AST_Exp_is_Exp_LSHIFT_Exp] = {3, Exp, "AST_Exp_is_Exp_LSHIFT_Exp", "Exp"},
	[AST_Exp_is_Exp_RSHIFT_Exp] = {3, Exp, "AST_Exp_is_Exp_RSHIFT_Exp", "Exp"},
	[AST_Exp_is_Exp_LT_Exp] = {3, Exp, "AST_Exp_is_Exp_LT_Exp", "Exp"},
	[AST_Exp_is_Exp_GT_Exp] = {3, Exp, "AST_Exp_is_Exp_GT_Exp", "Exp"},
	[AST_Exp_is_Exp_LE_Exp] = {3, Exp, "AST_Exp_is_Exp_LE_Exp", "Exp"},
	[AST_Exp_is_Exp_GE_Exp] = {3, Exp, "AST_Exp_is_Exp_GE_Exp", "Exp"},
	[AST_Exp_is_Exp_EQ_Exp] = {3, Exp, "AST_Exp_is_Exp_EQ_Exp", "Exp"},
	[AST_Exp_is_Exp_NE_Exp] = {3, Exp, "AST_Exp_is_Exp_NE_Exp", "Exp"},
	[AST_Exp_is_Exp_AND_Exp] = {3, Exp, "AST_Exp_is_Exp_AND_Exp", "Exp"},
	[AST_Exp_is_Exp_XOR_Exp] = {3, Exp, "AST_Exp_is_Exp_XOR_Exp", "Exp"},
	[AST_Exp_is_Exp_OR_Exp] = {3, Exp, "AST_Exp_is_Exp_OR_Exp", "Exp"},
	[AST_Exp_is_Exp_LAND_Exp] = {3, Exp, "AST_Exp_is_Exp_LAND_Exp", "Exp"},
	[AST_Exp_is_Exp_LOR_Exp] = {3, Exp, "AST_Exp_is_Exp_LOR_Exp", "Exp"},
	[AST_Exp_is_Exp_QOP_Exp_COLON_Exp] = {5, Exp, "AST_Exp_is_Exp_QOP_Exp_COLON_Exp", "Exp"},
	[AST_Exp_is_Exp_ASSIGNOP_Exp] = {3, Exp, "AST_Exp_is_Exp_ASSIGNOP_Exp", "Exp"},
	[AST_Exp_is_Exp_MULTE_Exp] = {3, Exp, "AST_Exp_is_Exp_MULTE_Exp", "Exp"},
	[AST_Exp_is_Exp_DIVE_Exp] = {3, Exp, "AST_Exp_is_Exp_DIVE_Exp", "Exp"},
	[AST_Exp_is_Exp_MODE_Exp] = {3, Exp, "AST_Exp_is_Exp_MODE_Exp", "Exp"},
	[AST_Exp_is_Exp_ADDE_Exp] = {3, Exp, "AST_Exp_is_Exp_ADDE_Exp", "Exp"},
	[AST_Exp_is_Exp_SUBE_Exp] = {3, Exp, "AST_Exp_is_Exp_SUBE_Exp", "Exp"},
	[AST_Exp_is_Exp_LSHIFTE_Exp] = {3, Exp, "AST_Exp_is_Exp_LSHIFTE_Exp", "Exp"},
	[AST_Exp_is_Exp_RSHIFTE_Exp] = {3, Exp, "AST_Exp_is_Exp_RSHIFTE_Exp", "Exp"},
	[AST_Exp_is_Exp_ANDE_Exp] = {3, Exp, "AST_Exp_is_Exp_ANDE_Exp", "Exp"},
	[AST_Exp_is_Exp_XORE_Exp] = {3, Exp, "AST_Exp_is_Exp_XORE_Exp", "Exp"},
	[AST_Exp_is_Exp_ORE_Exp] = {3, Exp, "AST_Exp_is_Exp_ORE_Exp", "Exp"},
	[AST_Exp_is_Exp_COMMA_Exp] = {3, Exp, "AST_Exp_is_Exp_COMMA_Exp", "Exp"}
};

static char* str_lexval[] = {
	[ID] = "ID",
	[NUM] = "NUM",
	[STRING] = "STRING",
	[LITERAL] = "LITERAL",
	[SIZEOF] = "SIZEOF",
	[TYPE_NAME] = "TYPE_NAME",
	[COMMA] = "COMMA",
	[DOT] = "DOT",
	[PTR] = "PTR",
	[QOP] = "QOP",
	[COLON] = "COLON",
	[ASSIGNOP] = "ASSIGNOP",
	[DIVE] = "DIVE",
	[MULTE] = "MULTE",
	[MODE] = "MODE",
	[ADDE] = "ADDE",
	[SUBE] = "SUBE",
	[LSHIFTE] = "LSHIFTE",
	[RSHIFTE] = "RSHIFTE",
	[ANDE] = "ANDE",
	[XORE] = "XORE",
	[ORE] = "ORE",
	[LAND] = "LAND",
	[LOR] = "LOR",
	[OR] = "OR",
	[XOR] = "XOR",
	[AND] = "AND",
	[EQ] = "EQ",
	[NE] = "NE",
	[LT] = "LT",
	[LE] = "LE",
	[GE] = "GE",
	[GT] = "GT",
	[LSHIFT] = "LSHIFT",
	[RSHIFT] = "RSHIFT",
	[ADD] = "ADD",
	[SUB] = "SUB",
	[MULT] = "MULT",
	[DIV] = "DIV",
	[MOD] = "MOD",
	[INC] = "INC",
	[DEC] = "DEC",
	[LNOT] = "LNOT",
	[NOT] = "NOT",
	[TYPEDEF] = "TYPEDEF",
	[EXTERN] = "EXTERN",
	[STATIC] = "STATIC",
	[AUTO] = "AUTO",
	[REGISTER] = "REGISTER",
	[CONST] = "CONST",
	[VOLATILE] = "VOLATILE",
	[CHAR] = "CHAR",
	[SHORT] = "SHORT",
	[INT] = "INT",
	[LONG] = "LONG",
	[SIGNED] = "SIGNED",
	[UNSIGNED] = "UNSIGNED",
	[FLOAT] = "FLOAT",
	[DOUBLE] = "DOUBLE",
	[VOID] = "VOID",
	[STRUCT] = "STRUCT",
	[UNION] = "UNION",
	[ENUM] = "ENUM",
	[ELLIPSIS] = "ELLIPSIS",
	[CASE] = "CASE",
	[DEFAULT] = "DEFAULT",
	[IF] = "IF",
	[ELSE] = "ELSE",
	[SWITCH] = "SWITCH",
	[WHILE] = "WHILE",
	[DO] = "DO",
	[FOR] = "FOR",
	[GOTO] = "GOTO",
	[CONTINUE] = "CONTINUE",
	[BREAK] = "BREAK",
	[RETURN] = "RETURN",
	[LC] = "LC",
	[RC] = "RC",
	[LB] = "LB",
	[RB] = "RB",
	[LP] = "LP",
	[RP] = "RP",
	[SEMI] = "SEMI",
	[BOOL] = "BOOL",
	[INT8T] = "INT8T",
	[INT16T] = "INT16T",
	[INT32T] = "INT32T",
	[INT64T] = "INT64T",
	[UINT8T] = "UINT8T",
	[UINT16T] = "UINT16T",
	[UINT32T] = "UINT32T",
	[UINT64T] = "UINT64T",
	[FLOAT32T] = "FLOAT32T",
	[FLOAT64T] = "FLOAT64T",
	[SIZET] = "SIZET",
	[UINTPTRT] = "UINTPTRT",
	[OFFT] = "OFFT",
	[NIL] = "NIL",
	[TRUE] = "TRUE",
	[FALSE] = "FALSE",
	[Program] = "Program",
	[ExtDecln] = "ExtDecln",
	[ExtDeclnList] = "ExtDeclnList",
	[FuncDef] = "FuncDef",
	[ExpList] = "ExpList",
	[Decln] = "Decln",
	[DeclnSpec] = "DeclnSpec",
	[InitorDeclrList] = "InitorDeclrList",
	[InitorDeclr] = "InitorDeclr",
	[TypeSpec] = "TypeSpec",
	[CompSpec] = "CompSpec",
	[CompType] = "CompType",
	[CompDeclnList] = "CompDeclnList",
	[CompDecln] = "CompDecln",
	[CompDeclrList] = "CompDeclrList",
	[CompDeclr] = "CompDeclr",
	[EnumSpec] = "EnumSpec",
	[EnumorList] = "EnumorList",
	[Enumor] = "Enumor",
	[TypeQulfr] = "TypeQulfr",
	[Declr] = "Declr",
	[DirectDeclr] = "DirectDeclr",
	[StarList] = "StarList",
	[TypeQulfrList] = "TypeQulfrList",
	[ParaTypeList] = "ParaTypeList",
	[ParaList] = "ParaList",
	[ParaDecln] = "ParaDecln",
	[IdList] = "IdList",
	[TypeName] = "TypeName",
	[AbstDeclr] = "AbstDeclr",
	[DirectAbstDeclr] = "DirectAbstDeclr",
	[Initor] = "Initor",
	[InitorList] = "InitorList",
	[StmtList] = "StmtList",
	[ExpStmt] = "ExpStmt",
	[CompSt] = "CompSt",
	[DeclnList] = "DeclnList",
	[Stmt] = "Stmt",
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
