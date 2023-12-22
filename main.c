#include <stdio.h>
#include "lib/list.h"
#include "lib/read.h"
#include "lib/sort.h"

int
main() {
    char* str = NULL;
    List list;
    init_list(&list);
    while ((str = get_word(" \t")) != NULL) {
        add_head(&list, str);
    }
    display_list(&list);
    sort(&list);
    display_list(&list);
    dealloc_list(&list);
    return 0;
}
