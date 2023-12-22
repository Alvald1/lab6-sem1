#include "read.h"

int is_delim(const char* delim, char c);
int skip_delim(const char* delim);

int
is_delim(const char* delim, char c) {
    while (*delim) {
        if (*delim++ == c) {
            return __OK;
        }
    }
    return NOT_FOUNDED;
}

int
skip_delim(const char* delim) {
    char c;
    while (is_delim(delim, (c = getchar())) == __OK)
        ;
    if (c == '\n') {
        return 0;
    }
    ungetc(c, stdin);
    return 1;
}

char*
get_word(const char* delim) {
    int size_inc = 10;
    char* buffer = (char*)malloc(size_inc);
    char* cur_pos = buffer;
    int max_len = size_inc;
    int len = 0;
    char c;
    if (cur_pos == NULL) {
        return NULL;
    }
    if (skip_delim(delim) == 0) {
        free(buffer);
        return NULL;
    }
    while (is_delim(delim, (c = getchar())) == NOT_FOUNDED) {
        if (c == '\n') {
            ungetc(c, stdin);
            break;
        }
        if (++len >= max_len) {
            char* tmp = (char*)realloc(buffer, max_len += size_inc);
            if (tmp == NULL) {
                free(buffer);
                return NULL;
            }
            cur_pos = tmp + len;
        }
        *cur_pos++ = c;
    }
    *cur_pos = '\0';
    return buffer;
}
