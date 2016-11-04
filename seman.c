#include "common.h"
#include "ast.h"

#define MAX_SIZE (2*1024*1024)

static Spec spec[MAX_SIZE];

static IdSet *actionscope;
vector_init_def(actionscope);

Spec *new_spec()
{
	static int spec_ptr = -1;
	spec_ptr ++;
	assert(spec_ptr < MAX_SIZE);
	return &spec[spec_ptr];
}

Spec* register_type_struct(Node *root)
{
	assert(root->semanval == AST_StructSpecifier_is_STRUCT_LC_DefList_RC
		|| root->semanval == AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC);

	Node *deflist = NULL;
	Spec *newtype = new_spec();
	newtype->type = SpecTypeStruct;
	if(root->semanval == AST_StructSpecifier_is_STRUCT_LC_DefList_RC)
	{
		deflist = root->child->sibling->sibling;
		newtype->id = NULL;
	}
	else if(root->semanval == AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC)
	{
		deflist = root->child->sibling->sibling->sibling;
		newtype->id = root->child->sibling->exval.st;
	}

	while(deflist != NULL)
	{
	}


	return newtype;
}

Spec* register_type_array(Node *root)
{
	assert(root->semanval == AST_VarDec_is_VarDec_LB_NUM_RB);
	return NULL;
}

Spec* register_type_func(Node *root)
{
	assert(root->semanval == AST_ExtDef_is_Specifier_FuncDec_CompSt);
	return NULL;
}

int seman_analysis(Node *root)
{
	/* 每出现一个ID的定义，当前作用域检查ID是否定义过
	 * 注册ID时操作包括，相对地址分配，需考虑位宽
	 * 对ID的定义进行注册，对ID的引用进行查询和标注
	 * 每进入一个子作用域，作用域加加，插入一个栅栏
	 * 每退出一个作用域，向左删除到栅栏处
	 * 局部作用域优先于全局作用域
	 * 局部作用域的ID可以与全局作用域的ID相同
	 *
	 * 遍历的第二个任务：计算表达式类型
	 * 对表达式左右类型不统一的情况进行：
	 *     1、隐式类型转化(基础类型之间)
	 *     2、报错
	 * */
	if(!root) return 0;

#define ACTIONSCOPE_ERASE_RIGHT \
	do { \
		while(vector_top(actionscope).id != NULL) \
			vector_pop(actionscope); \
		vector_pop(actionscope); \
	} while(0);
	
	Spec specifier;
	IdSet barrier = {NULL, NULL};
	vector_push(actionscope, barrier);

	switch(root->semanval)
	{
		/*action scope: {StmtList} and FuncDec*/
		case AST_Stmt_is_LC_StmtList_RC:
			vector_push(actionscope, barrier);
			seman_analysis(root->child);
			ACTIONSCOPE_ERASE_RIGHT;
			break;
		case AST_ExtDef_is_Specifier_FuncDec_CompSt:
			vector_push(actionscope, barrier);
			/*id type: function*/
			register_type_func(root);
			seman_analysis(root->child);
			ACTIONSCOPE_ERASE_RIGHT;
			break;

		/*special type*/
		case AST_StructSpecifier_is_STRUCT_LC_DefList_RC:
			register_type_struct(root);
			break;
		case AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC:
			register_type_struct(root);
			break;
		case AST_VarDec_is_VarDec_LB_NUM_RB:
			register_type_array(root);
			break;
		/*definition of identifier*/
		case AST_DefArg_is_Specifier_ID:
			break;
		case AST_Def_is_Specifier_DecList_SEMI:
			break;

		/*reference of varible*/
		case AST_Exp_is_ID:
			break;
		case AST_Exp_is_ID_LP_ArgList_RP:
			break;
		case AST_Exp_is_Exp_DOT_ID:
			break;
		case AST_Exp_is_Exp_POINTER_ID:
			break;

		/*check type*/
		case AST_Exp_is_MULT_Exp:
			break;
		case AST_Exp_is_BITAND_Exp:
			break;
		case AST_Exp_is_NOT_Exp:
			break;
		case AST_Exp_is_Exp_ASSIGNOP_Exp:
			break;

		/*basic arithmetical operation*/
		case AST_Exp_is_Exp_ADD_Exp:
			break;
		case AST_Exp_is_Exp_SUB_Exp:
			break;
		case AST_Exp_is_Exp_MULT_Exp:
			break;
		case AST_Exp_is_Exp_DIV_Exp:
			break;
		case AST_Exp_is_Exp_EQ_Exp:
			break;
		case AST_Exp_is_Exp_LT_Exp:
			break;
		case AST_Exp_is_Exp_LE_Exp:
			break;
		case AST_Exp_is_Exp_NE_Exp:
			break;
		case AST_Exp_is_Exp_GT_Exp:
			break;
		case AST_Exp_is_Exp_GE_Exp:
			break;
		case AST_Exp_is_Exp_AND_Exp:
			break;
		case AST_Exp_is_Exp_OR_Exp:
			break;
		case AST_Exp_is_Exp_BITAND_Exp:
			break;
		case AST_Exp_is_Exp_BITOR_Exp:
			break;

		case AST_Exp_is_Exp_LB_Exp_RB:
			break;

		default:
			seman_analysis(root->child);
			break;
	}

	seman_analysis(root->sibling);
	return 0;
}

void init_seman()
{
	vector_init_mem(IdSet, actionscope);
}
