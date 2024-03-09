#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h> // For size_t

size_t str_len(const char *s);

int str_cmp(const char *s1, const char *s2);

int str_n_cmp(const char *s1, const char *s2, size_t n);

void *mem_cpy(void *restrict dst, const void *restrict src, size_t n);

char *str_chr(const char *s, int c);

char *str_p_brk(const char *s, const char *charset);

char *str_sep(char **stringp, const char *delim);

char *str_cat(char *s1, const char *s2);

#endif // MY_STRING_H
