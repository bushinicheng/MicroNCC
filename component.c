#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include "common.h"
//#include "basic-dat.h"

#define BUF_SIZE (1024*1024*2)

char strbuf[BUF_SIZE]; 
static int strbuf_p = 0;

int double_buffer(void **buf, int size)
{
	void *tbuf = malloc(size * 2);
	memcpy(tbuf, *buf, size);
	free(*buf);
	*buf = tbuf;
	return 0;
}

int next_number(char **str, int base)
{
	int retval = 0;
	/* 0xff,088,255 at most 4 nums */
	for(int i = 0; i < 3; i++)
	{
		bool cur_valid = false;
		int ch = *(str[0]++);
		switch(base)
		{
			case 16:
				if(('0' <= ch && ch <= '9')
					|| ('a' <= ch && ch <= 'f')
					|| ('A' <= ch && ch <= 'F'))
				{
					if('0' <= ch && ch <= '9')
						retval = retval*16+ch-'0';
					else if('a' <= ch && ch <= 'f')
						retval = retval*16+ch+10-'a';
					else if('A' <= ch && ch <= 'F')
						retval = retval*16+ch+10-'A';
					cur_valid = true;
				}
				break;
			case 1:case 2:case 3:case 4:case 5:
			case 6:case 7:case 8:case 9:case 10:
				if('0' <= ch && ch < '0' + base)
				{
					retval = retval*base+ch-'0';
					cur_valid = true;
				}
				break;
		}
		if(!cur_valid) {str[0]--;break;}
		if(retval > 256) break;
	}
	return retval;
}

/* return value is the start position of registered string */
int register_string(const char *str)
{
	int ret_p = strbuf_p;
	char *p = (char *)str;
	bool in_str = true;
#ifdef __DEBUG__
	assert(strbuf_p + strlen(str) < BUF_SIZE);
#endif
	while(*(++p)) //since the first char is always `"`
	{
		if(*p == '"') {in_str = !in_str;continue;}
		if(!in_str)	continue;
		if(*p != '\\')
			strbuf[strbuf_p ++] = *p;
		else
			switch(*(++p))
			{
				case '\\':strbuf[strbuf_p ++] = '\\';break;
				case 'n' :strbuf[strbuf_p ++] = '\n';break;
				case 'r' :strbuf[strbuf_p ++] = '\r';break;
				case 't' :strbuf[strbuf_p ++] = '\t';break;
				case 'b' :strbuf[strbuf_p ++] = '\b';break;
				case 'x' :
				case 'X' :p++;strbuf[strbuf_p ++] = next_number(&p, 16);p--;break;
				case '0' :p++;strbuf[strbuf_p ++] = next_number(&p, 8);p--;break;
				default  :strbuf[strbuf_p ++] = *p;break;
			}
	}
	strbuf[strbuf_p ++] = 0;
	return ret_p;
}

int register_id(const char *text)
{
	int ret_p = strbuf_p;
	int len = strlen(text);
	strcat(&strbuf[strbuf_p], text);
	strbuf_p += len + 1;
	return ret_p;
}

int init_component()
{
#ifdef __DEBUG__
	/* unit test of register_string */
	printf("[unit test]func:%s, line:%d...", __func__, __LINE__);
	char *ss[] = {
		"\"Hello World!\"",
		"\"prefix\"\"\\n\\r\\t\\\\suffix\"",
		"\"prefix\" \r\n  \t  \"suffix\"",
		"\"pre\\\"fix\"  \t\n \"suf\\\"fix\"",
		"\"\\x48\\x65\\x6c\\x6c\\x6f\\x20\\x57\\x6f\\x72\\x6c\\x64\\x21\"",
		"\"\\0110\\0145\\0154\\0154\\0157\\040\\0127\\0157\\0162\\0154\\0144\\041\""
	};
	char *ans[] = {
		"Hello World!",
		"prefix\n\r\t\\suffix",
		"prefixsuffix",
		"pre\"fixsuf\"fix",
		"Hello World!",
		"Hello World!"
	};

	bool pass = true;
	int test_len = sizeof(ss)/sizeof(ss[0]);
	for(int i = 0; i < test_len; i++)
	{
		int p = register_string(ss[i]);
		if(strcmp(&strbuf[p], ans[i]) != 0)
		{
			printf("\ntest failed at case #%d.", i);
			printf("\nshould be '%s' but got '%s'", ans[i], &strbuf[p]);
			pass = false;
		}
	}
	if(pass)
		printf("PASS\n");
	else
		printf("\n");
#endif
	return 0;
}
