#ifndef __COMMON_H__
#define __COMMON_H__

/* some common macro will be defined in this file  */

#define __DEBUG__
//#define __DEBUG_LEX__

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
#define INT_MAX 2147483647

//#define __DEBUG_LEX__

/*other header files*/
#include "error.h"
#include "debug.h"
#include "vector.h"
#include "node.h"
#include "syntax.h"
#include "ast.h"
#include "bpool.h"

#define MAKE_DWORD2(a, b) ((a) << 16 | (b))
#define MAKE_DWORD4(a, b, c, d) ((a) << 24 | (b) << 16 | (c) << 8 | (d))
#define DWORD2_PART1(a) (((a)>>16) & 0xffff)
#define DWORD2_PART2(a) ((a) & 0xffff)
#define DWORD4_PART1(a) (((a)>>24) & 0xff)
#define DWORD4_PART2(a) (((a)>>16) & 0xff)
#define DWORD4_PART3(a) (((a)>> 8) & 0xff)
#define DWORD4_PART4(a) ((a) & 0xff)

#define wt_assert(cond) do { \
	if(!(cond)) set_break(); \
	assert(cond); \
} while(0)

int yylex_destroy();

#endif
