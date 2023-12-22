#include "list.h"

void
init_list(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void
add_head(List* list, char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
}

void
insert_node(List* list, Node* prev, char* data) {
    if (prev == list->head) {
        add_head(list, str);
    } else {
        Node* tmp = list->head;
        while (tmp->next != prev) {
            tmp = tmp->next;
        }
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;
        tmp->next = node;
        node->next = prev;
    }
}

Node*
get_node(List* list, char* data) {
    Node* node = list->head;
    while (node != NULL) {
        if (strcmp(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void
delete_node(List* list, Node* node) {
    if (node == list->head) {
        if (list->head->next == NULL) {
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        Node* tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->next = node->next;
        }
    }
    free(node);
}

void
display_list(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}
