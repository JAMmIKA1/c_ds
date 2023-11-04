#ifndef A_LIST_H
#define A_LIST_H

typedef int list_entry;
typedef struct {
    long length;
    long capacity;
    list_entry* data;
} Arraylist;

Arraylist* newList();
list_entry getNth(Arraylist list, long index);
list_entry removeNth(Arraylist* list, long index);
list_entry popBack(Arraylist* list);
long search(Arraylist list, list_entry value);
void destroyList(Arraylist* list);
void insert(Arraylist* list, long index, list_entry value);
void pushBack(Arraylist* list, list_entry value);
int listIsEmpty(Arraylist list);

#endif // !A_LIST_H
