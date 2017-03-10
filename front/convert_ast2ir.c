char* convert_ast2ir(node_t* root){
	static temp_time=0;//新建临时变量的次数
	if(!root)
		return;
	if(root->token==ExpList){

	}
	else if(root->token==Stmt){

	}
	else if(root->token==StmtList){

	}
	else if(root->token==Exp){
		node_t *exp1 = get_child_node(root, Exp);
		node_t *exp2 = get_child_node_with_skip(root, Exp, 1);
		if(!exp1){
			if(root->production==AST_Exp_is_ID){
				node_t *idnode = get_child_node_w(root, ID);
				char *vn = idnode->cv.id;
				return vn;	//+'\t'
				//printf("%s\t",vn);
				//ident_info_t *ve = find_variable(vn);
				//printf("%s\t", );
			}
			else if (root->production==AST_Exp_is_NUM){
				node_t *numnode = get_child_node_w(root, NUM);
				switch(numnode->cv.t){
					case 'i':
					//没有问题吗？？？？sformat_t？？？
						return sformat("#%d\t",numnode->cv.i);
						break;
					case 'o':
						return sformat("0%o\t",numnode->cv.i);
						break;
					case 'x':
						return sformat("0x%x\t",numnode->cv.i);
						break;
					case 'f':
						return sformat("%f\t",numnode->cv.f);							
						break;
					default:
						break;
					}	
				}
				
			}
			else if (root->production==AST_Exp_is_NIL){
				return sformat("%s\t","NULL");
				//............................
			}
			else if (root->production==AST_Exp_is_TRUE){
				return sformat("%s\t","TRUE");
				//....................
			}
			else if (root->production==AST_Exp_is_FALSE){
				return sformat("%s\t","FALSE");
			}
			else if(root->production==AST_Exp_is_STRING){
				node_t *strnode = get_child_node_w(root, STRING);
				char *vn = strnode->cv.str;
				return sformat("%s\t",vn);
			}
			else if(root->production==AST_Exp_is_LITERAL){
				node_t *charnode = get_child_node_w(root, LITERAL);
				char vn=charnode->cv._8;
				return sformat("%c\t",vn);
			}
			else if(root->production==AST_Exp_is_SIZEOF_LP_TypeName_RP){
				node_t *typenmnode = get_child_node(root,TypeName);
				temp_time++;
				//所以说下面少了一个参数
				printf("%s%d\t=\t%s\t%s\n", "t",temp_time,"SIZEOF","");
				return sformat("%s%d\t","t",temp_time);
				//............................
			}
		}
		else if(!exp2){
			if(root->production==AST_Exp_is_LP_Exp_RP){
				char* rv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,rv_exp);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_LP_RP){
				char* rv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,rv_exp);
				return "t";//+temp_time+"("+")"
				return sformat("%s%d\t(\t)\t","t",temp_time);
				//.......................................
			}
			else if(root->production==AST_Exp_is_Exp_LP_ExpList_RP){
				node_t *explistnode=get_child_node(root, ExpList);
				char* rv_explist=print_intercode(explist_node);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,rv_explist);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_DOT_ID){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv_exp);
				temp_time++;
				node_t *idnode = get_child_node_w(root, ID);
				char *vn = idnode->cv.id;
				printf("%s%d\t:=\t%s%d\tDOT\t%s\n", "t",temp_time,"t",temp_time-1,vn);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_PTR_ID){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv_exp);
				temp_time++;
				node_t *idnode = get_child_node_w(root, ID);
				char *vn = idnode->cv.id;
				printf("%s%d\t:=\t%s%d\tPTR\t%s\n", "t",temp_time,"t",temp_time-1,vn);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_INC){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv_exp);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t+\t1\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time-1);
			}
			else if(root->production==AST_Exp_is_Exp_DEC){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv_exp);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t-\t1\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time-1);
			}
			else if(root->production==AST_Exp_is_INC_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv_exp);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t+\t1\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_DEC_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv_exp);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t+\t1\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_AND_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\t&%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_MULT_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\t*%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_ADD_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\t+%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_SUB_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\t-%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_NOT_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\t~%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_LNOT_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\t!%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}	
			else if(root->production==AST_Exp_is_SIZEOF_Exp){
				char* lv_exp=print_intercode(exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp);
				temp_time++;
				printf("%s%d\t:=\tSIZEOF\t%s%d\n", "t",temp_time,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_LP_TypeName_RP_Exp){
				//.............................
			}
		}
		else{
			if(root->production==AST_Exp_is_Exp_LB_Exp_RB){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t[\t%s%d\t]\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
				//..........................................
			}
			else if(root->production==AST_Exp_is_Exp_MULT_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t*\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_DIV_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t/\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_MOD_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t%%\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_ADD_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t+\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}	
			else if(root->production==AST_Exp_is_Exp_SUB_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t-\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_LSHIFT_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t<<\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_RSHIFT_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t>>\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_RELOP_Exp){
				//............................
			}
			else if(root->production==AST_Exp_is_Exp_EQ_Exp){
				//............................
			}
			else if(root->production==AST_Exp_is_Exp_NE_Exp){
				//............................
			}
			else if(root->production==AST_Exp_is_Exp_AND_Exp){
				//............................
			}
			else if(root->production==AST_Exp_is_Exp_XOR_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t^\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_OR_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				temp_time++;
				printf("%s%d\t:=\t%s%d\t|\t%s%d\n","t",temp_time,"t",temp_time-2,"t",temp_time-1);
				return sformat("%s%d\t","t",temp_time);
			}
			else if(root->production==AST_Exp_is_Exp_LAND_Exp){
				//..................................
			}
			else if(root->production==AST_Exp_is_Exp_LOR_Exp){
				//..................................
			}
			else if(root->production==AST_Exp_is_Exp_ASSIGNOP_Exp){
				char* lv_exp1=print_intercode(exp1);
				char* lv_exp2=print_intercode(exp2);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp1);
				temp_time++;
				printf("%s%d\t:=\t%s\n", "t",temp_time,lv1_exp2);
				printf("%s%d\t:=\t%s%d\n","t",temp_time-1,"t",temp_time);
				return sformat("%s%d\t","t",temp_time-1);
			}
			else if(root->production==AST_Exp_is_Exp_EQUOP_Exp){
				//........................怎样得到equop的具体值
			}
			else if(root->production==AST_Exp_is_Exp_COMMA_Exp){
				//........................
			}
			else if(root->production==AST_Exp_is_Exp_QOP_Exp_COLON_Exp){
				//..........................
			}
		}

	}