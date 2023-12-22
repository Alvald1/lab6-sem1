#include <stdio.h>
#include "lib/list.h"
#include "lib/read.h"
#include "lib/sort.h"

int
main() {
    char *str = NULL, *str2 = NULL;
    List list;
    int tmp;
    Node* del = NULL;
    printf("$> ");
    while ((tmp = getchar()) != EOF) {
        ungetc(tmp, stdin);
        init_list(&list);
        while ((str = get_word(" \t")) != NULL) {
            add_head(&list, str);
        }
        sort(&list);
        display_list(&list);
        printf("(a) - del\n(b) - insert before\n(c) - next\n");
        while (tmp && (tmp = getchar()) != EOF) {
            getchar();
            switch (tmp) {
                case 'a':
                    printf("Введите слово\n");
                    if ((str = get_word(" \t")) != NULL) {
                        while ((del = get_node(&list, str))) {
                            delete_node(&list, del);
                        }
                    }
                    free(str);
                    getchar();
                    display_list(&list);
                    break;
                case 'b':
                    printf("Перед этим словом\n");
                    str = get_word(" \t");
                    getchar();
                    printf("Это слово\n");
                    str2 = get_word(" \t");
                    insert(&list, get_node(&list, str), str2);
                    free(str);
                    getchar();
                    display_list(&list);
                    break;
                case 'c': tmp = 0; break;
            }
            if (tmp == 0) {
                break;
            }
            printf("(a) - del\n(b) - insert before\n(c) - next\n");
        }
        dealloc_list(&list);
        printf("$> ");
    }
    return 0;
}
