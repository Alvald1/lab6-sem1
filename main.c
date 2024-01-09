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
        while ((str = get_word(" \t")) && strlen(str)) {
            add_head(&list, str);
        }
        free(str);
        if (list.head != NULL) {
            sort(&list);
            display_list(&list);
            printf("(a) - del\n(b) - insert before\n(c) - next\n");
            while ((tmp = getchar()) != EOF) {
                if (tmp != '\n') {
                    getchar();
                }
                switch (tmp) {
                    case 'a':
                        printf("Введите слово\n");
                        while ((str = get_word(" \t")) && strlen(str) == 0) {
                            if (strlen(str) != 0) {
                                getchar();
                            } else {
                                free(str);
                            }
                        }
                        if (str == NULL) {
                            dealloc_list(&list);
                            return 0;
                        }
                        while ((del = get_node(&list, str))) {
                            delete_node(&list, del);
                        }
                        free(str);
                        getchar();
                        display_list(&list);
                        break;
                    case 'b':
                        printf("Перед этим словом\n");
                        while ((str = get_word(" \t")) && strlen(str) == 0) {
                            if (strlen(str) != 0) {
                                getchar();
                            } else {
                                free(str);
                            }
                        }
                        if (str == NULL) {
                            dealloc_list(&list);
                            return 0;
                        }
                        getchar();
                        printf("Это слово\n");
                        while ((str2 = get_word(" \t")) && strlen(str2) == 0) {
                            if (strlen(str2) != 0) {
                                getchar();
                            } else {
                                free(str2);
                            }
                        }
                        if (str2 == NULL) {
                            free(str);
                            dealloc_list(&list);
                            return 0;
                        }
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
        }
        dealloc_list(&list);
        printf("$> ");
    }
    return 0;
}
