#include <stddef.h>
#include <stdlib.h>


char **tokenize(char *str, const char *delims) {

    int count = 0;
    char *temp = str;
    char *last = NULL; 

    while (*temp) {
        if (str_chr(delims, *temp)) { //Using str_chr to check for delimiter
            if (last != NULL) {
                count++;
                last = NULL;
            }
            *temp = '\0';
        } else if (last == NULL) {
            last = temp;
        }
        temp++;
    }
    char **tokens = (char **)malloc(sizeof(char *) * (count + 1));
    if (!tokens) return NULL;
    
    int i = 0;
    temp = str;
    char *start = NULL;

    while (*temp || temp == str) {
        if (*temp == '\0' || temp == str) {
            if (start != NULL) {
                tokens[i++] = start;
                start = NULL;
            }
            if (*temp) temp++;
        }
        if (*temp && start == NULL) {
            start = temp;
        }
        temp++;
    }
    tokens[i] = NULL;
    return tokens;
}
