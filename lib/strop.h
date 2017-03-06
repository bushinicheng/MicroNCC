#ifndef STROP_H
#define STROP_H

/* return a format string which stored in memory alloced by malloc */
char *sformat(const char *format, ...);

/* return a format string which stored in temporary buffer which can be reused */
char *sformat_t(const char *format, ...);

/* repeat `dup` times of given string `str` */
char *strmul(char *str, int dup);

/* join all string in `strlist` by `delim` */
char *strjoin(char **strlist, int size, char *delim);

/* replace `ch` in string by `rep` */
char *strrep(const char *string, char ch, const char *rep);

/* return number of `ch` in `strin` */
int strcnt(const char *strin, char ch);

/* return a sub-string of `strin` which start with `ch` */
char *strseek(const char *strin, char ch);

#endif
