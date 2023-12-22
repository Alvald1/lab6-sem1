#include "sort.h"

void
swap(List* list, Node* left, Node* right) {
    Node* prev_left = NULL;
    Node* cur = list->head;
    while (cur != left) {
        prev_left = cur;
        cur = cur->next;
    }
    Node* prev_right = NULL;
    cur = list->head;
    while (cur != right) {
        prev_right = cur;
        cur = cur->next;
    }
    if (prev_left != NULL) {
        prev_left->next = right;
    } else {
        list->head = right;
    }
    if (prev_right != NULL) {
        prev_right->next = left;
    } else {
        list->head = left;
    }
    Node* temp = left->next;
    left->next = right->next;
    right->next = temp;
}

void
sort(List* list) {
    Node* first = list->head;
    Node* second = NULL;
    Node* min = first;
    Node* tmp = NULL;
    while (first->next) {
        min = first;
        second = first->next;
        while (second) {
            if (strlen(min->data) > strlen(second->data)) {
                min = second;
            }
            second = second->next;
        }
        tmp = first->next;
        swap(list, first, min);
        first = tmp;
    }
}
