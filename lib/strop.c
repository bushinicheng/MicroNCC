/*
 * some functions for string operation which C library didn't support.
 */

char *sformat(const char *format, ...) {
	char *ret_str = (char *)get_memory_pointer();
	va_list ap;
	va_start(ap, format);
	int len = vsprintf(ret_str, format, ap);
	return (char *)require_memory(len + 1);
}

/* function:
 *		return a format string which stored in temporary buffer
 * It dont't guarantee the timeliness of return string.
 * What can be ensure is that the memory will not be change
 * until the next call of get_memory_pointer
 * */
char *sformat_t(const char *format, ...) {
	char *ret_str = (char *)get_memory_pointer();
	va_list ap;
	va_start(ap, format);
	int len = vsprintf(ret_str, format, ap);
	push_bpool_state(len + 1);
	return ret_str;
}

/*
 * repeat target string	`str` `dup` times
 */
char *strmul(char *str, int dup) {
	int len = strlen(str);
	char *p = malloc(len * dup + 1), *base = p;
	p[0] = 0;
	for(int i = 0; i < dup; i++) {
		strcpy(p, str);
		p += len;
	}
	return base;
}

/*
 * join alist of string `strlist` by `delim`
 */
char *strjoin(char **strlist, int size, char *delim) {
	char *p = get_memory_pointer();
	char *base = p;
	int delimlen = strlen(delim);
	for(int i = 0; i < size; i++) {
		strcpy(p, strlist[i]);
		p += strlen(strlist[i]);
		if(i != size - 1) {
			strcpy(p, delim);
			p += delimlen;
		}
	}
	return require_memory((size_t)p - (size_t)base + 1);
}

/*
 * replace `ch` in `string` by `rep`
 */
char *strrep(const char *string, char ch, const char *rep) {
	int i = 0, p = 0;
	char *buf = get_memory_pointer();
	while(string[i]) {
		if(string[i] == ch) {
			int q = 0;
			while(rep[q]) {
				buf[p ++] = rep[q ++];
			}
		}else{
			buf[p ++] = string[i];
		}
		i ++;
	}
	buf[p ++] = 0;
	return require_memory(strlen(buf) + 1);
}

/*
 * count the numbers of `ch` in `strin`
 */
int strcnt(const char *strin, char ch) {
	int ret = 0;
	char *p = (char*)strin;
	do{ret+=(*p==ch);}while(*p++);
	return ret;
}

/*
 * return a sub-string of `strin` which start with `ch`
 */
char *strseek(const char *strin, char ch) {
	while(*strin && *strin != ch) {
		strin ++;
	}
	if(*strin == ch)
		return (char *)strin;
	else
		return NULL;
}
