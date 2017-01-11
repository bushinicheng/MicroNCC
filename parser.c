#include "common.h"

/* recursive descent + turing machine == railgun
 *     ==> no limits for syntax rules
 *
 * syntax:
 *
 * funcdef: int **a(struct A **x[], int p, ...) {}
 * funcdel: int **a(struct A **x[], int p, ...);
 * vardef: spec **a[][] = {x, x, {4545} [,]};
 *       | spec **a[][] = assignment_exp
 *
 * initializer: assignment_exp, 
 *
 * starlist, indexlist:[][][]
 *
 * statement: if,if-else,switch-case,for,while,do-while
 *			  return,goto,break,continue,
 *			  exp,vardef
 *
 * spec:typespec,complexspec 
 *
 * type:int,uint32_t,...
 *
 * complextype:union, struct
 *
 * complexspec:complextype id { vardeflist }
 *			  |complextype {vardeflist}
 *			  |complextype id
 *			  |type_name   note:typedef struct
 *
 * storage_class:typedef, extern, static, auto, register
 *
 * type_qualifier:btype, struct, union, enum, type_name
 *
 * decl:storage_class
 *     |storage_class decl_spec
 *     |type_spec
 *     |type_spec declspec
 *     |type_qualifier decl_spec
 *     |type_qualifier
 *
 * for struct, bit fields need to be considered
 *
 *
 *
 *
 *
 */
