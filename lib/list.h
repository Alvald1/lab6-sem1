#ifndef __LIST__
#define __LIST__

typedef struct _node {
    char* data;
    struct _node* next;
} Node;

typedef struct _List {
    Node* head;
    Node* tail;
} List;

void init_list(List* list);
void add_head(List* list, char* data);
Node* get_node(List* list, char* data);
void delete_node(List* list, Node* node);
void display_list(List* list) void insert_node(List* list, Node* prev, char* data);

#endif
