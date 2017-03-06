#ifndef DEBUG_H
#define DEBUG_H

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

#define veprintf(fmt...) vfprintf (stderr, fmt)
#define eprintf(fmt...) fprintf (stderr, fmt)

int yylog(FILE *fp, const char *tag, const char *format, ...);

#define loge(fmt, ...) do {\
	eprintf("\033[" YYLOG_STYLE_BOLD ";" YYLOG_COLOR_RED "m" fmt "\033[0m", ## __VA_ARGS__); \
	exit(-1); \
} while(0)

#define logw(fmt, ...) do { \
	set_break(); \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_YELLOW "m[WARNING] \033[0m" "line:%d, file:%s, " "\033[" YYLOG_STYLE_BOLD ";" YYLOG_COLOR_WHITE "m" fmt "\033[0m", __LINE__, __FILE__, ## __VA_ARGS__); \
} while(0)

#define logi(fmt, ...) \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_NORMAL "m[INFO] \033[0m" fmt, ## __VA_ARGS__)

#define logl() \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[DEBUG] \033[0m" "line: %-3d, func:%s\n", __LINE__, __func__)

#ifdef __DEBUG__
#define logd(fmt, ...) \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[DEBUG] \033[0m" fmt, ## __VA_ARGS__)
#else
#define logd(...) do{}while(0)
#endif

#ifdef __DEBUG_LEVEL_2__
#define logd2(fmt, ...) \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[DEBUG]\033[0m %s at %d: " fmt, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define logd2(...) do{}while(0)
#endif

#define logG(...) do { \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_GREEN "m"); \
	eprintf(__VA_ARGS__); \
	eprintf("\033[0m"); \
} while(0)

#define logR(...) do { \
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_RED "m"); \
	eprintf(__VA_ARGS__); \
	eprintf("\033[0m"); \
} while(0)


#define __TEST_START__(info)\
	eprintf("\033[" YYLOG_STYLE_NORMAL ";" YYLOG_COLOR_BLUE "m[%-5s test]\033[0m func:%s, line:%d...", #info, __func__, __LINE__);

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
		logw( "%s <> %s, test failed!", a, b); \
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
