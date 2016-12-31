#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "error.h"
//#define YYDEBUG 1

int __attribute__((noinline)) set_break();

/*output style*/
#define YYLOG_STYLE_NORMAL    "0"
#define YYLOG_STYLE_BOLD      "1"
#define YYLOG_STYLE_DARK      "2"
#define YYLOG_STYLE_BACK      "3"
#define YYLOG_STYLE_UNDERLINE "4"

/*output color*/
#define YYLOG_COLOR_BLACK    "30"
#define YYLOG_COLOR_RED      "31"
#define YYLOG_COLOR_GREEN    "32"
#define YYLOG_COLOR_YELLOW   "33"
#define YYLOG_COLOR_BLUE     "34"
#define YYLOG_COLOR_PURPLE   "35"
#define YYLOG_COLOR_SKYBLUE  "36"
#define YYLOG_COLOR_WHITE    "37"
#define YYLOG_COLOR_NORMAL   "38"

#define logf(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_BACK ";" YYLOG_COLOR_YELLOW "m", __VA_ARGS__)

#define loge(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_BOLD ";" YYLOG_COLOR_RED "m", __VA_ARGS__)

#define logw(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m", __VA_ARGS__)

#define logi(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_WHITE "m", __VA_ARGS__)

//#ifdef __DEBUG__
#define logd(...) \
	yylog(stderr, "\033[0m", __VA_ARGS__)
//#else
//#define logd(...) do{}while(0)
//#endif

#define logG(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_GREEN "m", __VA_ARGS__)

#define STATE_TEST_START \
	bool __state_test_pass__ = true; \
	logd("[state test]func:%s, line:%d...", __func__, __LINE__);

#define STATE_TEST_EQUAL(a, b) \
	if((a) != (b)) {\
		logd("test failed at line #%d\n", __LINE__); \
		__state_test_pass__ = false;\
		goto __state_test_end__;\
	}

#define STATE_TEST_END \
__state_test_end__: \
	if(__state_test_pass__) logG("PASS\n");

#endif
