#ifndef D_LIST_H
#define D_LIST_H

typedef int list_entry;

typedef struct list_node {
    list_entry data;
    struct list_node* next;
} list_node;

typedef struct {
    int length;
    list_node* head;
    list_node* tail;
} d_list;

#endif // !_DLIST_H
