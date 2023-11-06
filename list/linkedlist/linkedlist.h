#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int list_entry;
typedef struct node {
    list_entry data;
    struct node* next;
} node;
typedef struct  Linkedlist {
    node* head;
    node* tail;
    unsigned long length;
} Linkedlist;

Linkedlist* newList();
list_entry getNth(Linkedlist* list, unsigned long index);
list_entry getLast(Linkedlist* list);
void removeNth(Linkedlist* list, unsigned long index);
void insert(Linkedlist* list, list_entry value, unsigned long index);
void appendNode(Linkedlist* list, list_entry value);
int listIsEmpty(Linkedlist* list);
void listDestroy(Linkedlist* list);

#endif // !LINKED_LIST_H
