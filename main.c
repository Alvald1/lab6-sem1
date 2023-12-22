#include <stdio.h>
#include "lib/read.h"

int
main() {
    char* str = NULL;
    while ((str = get_word(" \t")) != NULL) {
        printf("%s\n", str);
        free(str);
    }
    return 0;
}
