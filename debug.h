#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "error.h"
//#define YYDEBUG 1

int __attribute__((noinline)) set_break();
char *sformat(const char *format, ...);

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
	yylog(stderr, "\033[" YYLOG_STYLE_BACK ";" YYLOG_COLOR_PURPLE "m", __VA_ARGS__)

#define loge(...) do {\
	yylog(stderr, "\033[" YYLOG_STYLE_BOLD ";" YYLOG_COLOR_RED "m", __VA_ARGS__); \
	exit(-1); \
} while(0)

#define logw(...) do { \
	set_break(); \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_YELLOW "m[WARNING] \033[0m", "line:%d, file:%s, ", __LINE__, __FILE__); \
	yylog(stderr, "\033[" YYLOG_STYLE_BOLD ";" YYLOG_COLOR_WHITE "m", __VA_ARGS__); \
} while(0)

#define logi(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_NORMAL "m", __VA_ARGS__)

#define logl() \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[DEBUG] \033[0m", "line: %-3d, func:%s\n", __LINE__, __func__)

#ifdef __DEBUG__
#define logd(...) \
	yylog(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[DEBUG] \033[0m", __VA_ARGS__)
#else
#define logd(...) do{}while(0)
#endif

#define logG(...) do { \
	fprintf(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_GREEN "m"); \
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, "\033[0m"); \
} while(0)

#define logR(...) do { \
	fprintf(stderr, "\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_RED "m"); \
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, "\033[0m"); \
} while(0)


#define __TEST_START__(info)\
	logi("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[%-5s test]\033[0m func:%s, line:%d...", #info, __func__, __LINE__);

#define __TEST_AVOID__(info, cond) \
	if(cond) {\
		logR("FAIL\n"); \
		logw(#cond " should not be true, test failed!"); \
		goto __##info##_test_fail__;\
	}

#define __TEST_EQUAL__(info, a, b) \
	if((a) != (b)) {\
		logR("FAIL\n"); \
		logw(#a " <> " #b ", test failed!"); \
		goto __##info##_test_fail__;\
	}

#define __TEST_STR_EQUAL__(info, a, b) \
	if(strcmp((a), (b)) != 0) {\
		logR("FAIL\n"); \
		logw(#a " <> " #b ", test failed!"); \
		goto __##info##_test_fail__;\
	}

#define __TEST_FAIL__(info) \
	goto __##info##_test_fail__;\

#define __TEST_ASSERT__(info, cond, ...) \
	if(!(cond)) { \
		logR("FAIL\n"); \
		logw(__VA_ARGS__); \
		goto __##info##_test_fail__;\
	}

#define __TEST_END__(info) \
__##info##_test_end__: \
	logG("PASS"); \
__##info##_test_fail__: \
	logG("\n");


#define STATE_TEST_START \
	__TEST_START__(state);

#define STATE_TEST_AVOID(cond) \
	__TEST_AVOID__(state, cond);

#define STATE_TEST_EQUAL(a, b) \
	__TEST_EQUAL__(state, a, b);

#define STATE_TEST_END \
	__TEST_END__(state);



#define UNIT_TEST_START \
	__TEST_START__(unit);

#define UNIT_TEST_AVOID(cond) \
	__TEST_AVOID__(unit, cond);

#define UNIT_TEST_ASSERT(cond, ...) \
	__TEST_ASSERT__(unit, cond, __VA_ARGS__);

#define UNIT_TEST_EQUAL(a, b) \
	__TEST_EQUAL__(unit, a, b);

#define UNIT_TEST_STR_EQUAL(a, b) \
	__TEST_STR_EQUAL__(unit, a, b);

#define UNIT_TEST_FAIL \
	__TEST_FAIL__(unit);

#define UNIT_TEST_END \
	__TEST_END__(unit);


#endif
