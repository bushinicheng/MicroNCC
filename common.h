#ifndef __COMMON_H__
#define __COMMON_H__

/* some common header files will be included here. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <malloc.h>

#ifdef __YYLOG_C__
#undef __YYLOG_C__
#include "error.h"
#endif
#include "debug.h"

/* some common macro will be defined in this file  */

#define __DEBUG__

typedef unsigned char bool;

#define true 1
#define false 0

#endif
