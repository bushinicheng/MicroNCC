# convert AST to IR

##AST的内存形式

AST是节点串联起来的语法树，在front模块中的node.h中定义了节点，其基本结构如下：
```
typedef struct node_t {
	struct node_t *sibling;//指向兄弟节点的指针
	struct node_t *child;//指向第一个子节点的指针
	struct node_t *parent;//指向父节点的指针

	...//一些其它信息
} node_t;
```

##转换的基础知识
举个简单的例子，一个表达式的语法定义为：
```
exp -> exp + term     //exp可以是一个exp和一个term的和
     | term           //exp也可以是一个term

term -> term * factor //term可以是一个term和一个factor的积
      | factor        //term也可以就是一个factor

factor -> ( exp )     //factor可以是一个括号扩起来的表达式
        | integer     //factor也可以是一个整数
```
现在将其应用于表达式`1+2*(3+4)`,我们可以得到这样一颗语法树
```
exp
├── exp
│   └── term
│       └── factor
│           └── integer:1
├── '+'
└── term
    ├── term
    │   └── factor
    │       └── integer:2
    ├── '*'
    └── factor
        ├── '('
	    ├── exp
	    │   ├── exp
	    │   │   └── term
	    │   │       └── factor
	    │   │           └── integer:3
	    │   ├── '+'
	    │   └── term
	    │       └── factor
	    │           └── integer:4
	    └── ')'
```
有了这样一颗语法树，我们可以用递归的方法将其生成到IR，比如，假设现在有一个函数`convert_ast2ir`，可以将符合上述文法的任意一个语法树转化成中间代码，并返回一个临时变量名，这个临时变量名存储了这个表达式的计算结果，那么我们会有如下的伪代码：
```
convert_ast2ir(tree)
	if tree.production is exp -> exp + term
		temp1 = convert_ast2ir(tree.exp)
		temp2 = convert_ast2ir(tree.term)
		print temp1 '=' temp1 '+' temp2
	elif tree.production is exp -> term
		temp1 = convert_ast2ir(tree.term)
		//print nothing, since no operator here
	elif tree.production is term -> term * factor
		temp1 = convert_ast2ir(tree.term)
		temp2 = convert_ast2ir(tree.factor)
		print temp1 '=' temp1 '*' temp2
	elif tree.production is term -> factor
		temp1 = convert_ast2ir(tree.factor)
	elif tree.production is factor -> ( exp )
		temp1 = convert_ast2ir(tree.exp)
	elif tree.production is factor -> integer
		temp1 = new temp()
		print temp1 '=' integer.value
	endif
	return temp1
```
这是一个基础形式的树到IR的伪代码，甚至没有利用局部性约减临时变量个数，而树到IR的任务其实与这个大同小异。

##front模块实际在使用的文法
实际使用的语法树的文法可以参见syntax.md，文法中有很多表达式无关的部分，这一部分对生成IR没有帮助，可以忽视，重点需要关注exp和stmt的产生式。

##实际转换
举一个例子，当需要转换的一个子树的产生式为`Exp -> Exp INC`，这个产生式对应`a++`、`(*i)++`这样的表达式，转换时传入参数类型是`node_t *root`，其定义在前面有提到。通过`root->production`我们可以获得以这个节点为根的语法规则，其形如`AST_Exp_is_Exp_INC`，是一个整形变量，然后通过`root->child`，可以获得其第一个子节点`Exp`，由于树的存储是以兄弟树的形式，获得其余的子节点需要通过sibling成员变量，比如root的第二个子节点是`root->child->sibling`，第三个子节点是`root->child->sibling->sibling`，由于这条产生式只有两个子节点，所以到第三个子节点时其值为`NULL`。
更方便的子节点获取方式，很多时候需要的是具有某个属性值的子节点，虽然这可以借助产生式加严格定位得到，单写起来会很长一串，比如第8个子节点需要写成`root->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling`，这样一长串出现在代码中未免无法直视，同时也难以调错。回顾取子节点的一大共性：具有某个属性值的子节点，所以藉此可以分装一个简单的API辅助获取子节点。比如想要获得属性值为Exp的子节点，只需要`get_child_node_w(Exp)`。

##一些转换的注意点
* Exp -> ID
 * 对于ID需要先通过`find_variable(char *)`查找得到ID的相关信息
* Exp -> Exp LP ExpList RP
 * 这是一个函数调用
* 通过变量astroot可以拿到语法树的根

##参考
有一个写的很糊的版本已经有相对完整的语法树到IR转换的代码，但是这个项目中使用的语法树和那个项目中使用的不一样。具体地址https://github.com/wierton/naive-compiler/blob/lab-3-st/seman.c 的第944行`print_intercode`函数，代码中的`reduce_rule`等价于这个项目中的`production`
