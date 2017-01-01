#ifndef __COMMON_H__
#define __COMMON_H__

/* some common macro will be defined in this file  */

#define __DEBUG__

/* some common header files will be included here. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <malloc.h>

/*since bool isn't valid datatype in c*/
/*define some basic type*/
typedef unsigned off_t;
typedef unsigned char bool;

#define true 1
#define false 0

/*other header files*/
#include "error.h"
#include "debug.h"
#include "vector.h"
#include "node.h"
#include "syntax.h"
#include "ast.h"

void *get_memory_pointer();
void require_memory(size_t size);

#endif
