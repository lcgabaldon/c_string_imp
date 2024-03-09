#include <stdlib.h>

size_t str_len(const char *s) {
    const char *p = s;
    while (*p != '\0') {
        p++; // Move the pointer to the next character
    }
    return p - s; // The difference between the pointers is the string length
}  

int str_cmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int str_n_cmp(const char *s1, const char *s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    } else {
        return (unsigned char)*s1 - (unsigned char)*s2;
    }
}

void *mem_cpy(void *restrict dst, const void *restrict src, size_t n) {
    char *d = (char *)dst;
    const char *s = (char *)src;
    while (n) {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return dst;
}

char *str_chr(const char *s, int c) {
    char target = (char)c;

    while(*s != target) {
        if (*s == '\0') {
            return NULL;
        }
        s++;
    }
    return (char *)s;
}

char *str_p_brk(const char *s, const char *charset) {
    for (const char *p = s; *p != '\0'; p++) {
        for (const char *c = charset; *c != '\0'; c++) {
            if (*p == *c) {
                return (char *)p;
            }
        }
    }
    return NULL;
}

char *str_sep(char **stringp, const char *delim) {
    if (!stringp || !*stringp || !*delim) return NULL;

    char *start = *stringp;
    char *end = *stringp;

    while (*end) {
        const char *d;
        for (d = delim; *d; d++) {
            if (*end == *d) {
                *end = '\0';
                *stringp = end + 1;
                return start;
            }
        }
        end++;
    }

    *stringp = NULL;
    return start;
}

char *str_cat(char *s1, const char *s2) {
    char *p = s1;

    while (*p != '\0') { p++; }

    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}
