#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arraylist.h"

Arraylist* newList() {
    Arraylist* new_list = malloc(sizeof(Arraylist));
    new_list->capacity = 10;
    new_list->length = 0;
    new_list->data = malloc(sizeof(list_entry)*new_list->capacity);
    return new_list;
}
void expandList(Arraylist* list) {
    list->capacity *= 2;
    list_entry* new_data = malloc(sizeof(list_entry)*list->capacity);
    memcpy(new_data, list->data, sizeof(list_entry)*list->capacity/2);
    free(list->data);
    list->data = new_data;
}
int listIsEmpty(Arraylist list) {
    return (list.length <= 0);
}
int listIsFull(Arraylist list) {
    return (list.length >= list.capacity);
}
list_entry getNth(Arraylist list, long index) {
    assert(!"Invalid index!" || ((index < list.length) && (index >= 0)));
    // if(!((index < list.length) && (index >= 0))) return -1;
    return list.data[index];
}
long search(Arraylist list, list_entry value) {
    for(int i = 0; i < list.length; i++) {
        if(value == list.data[i]) {
            return i;
        }
    }
    return -1;
}
void destroyList(Arraylist* list) {
    free(list->data);
    free(list);
}
void insert(Arraylist* list, long index, list_entry value) {
    if(listIsFull(*list)) { 
        expandList(list);
    }
    assert(!"Invalid index!" || ((index <= list->length) && (index >= 0)));
    // if(!((index <= list->length) && (index >= 0))) return;
    for(int i = list->length++; i > index; i--) {
        list->data[i] = list->data[i-1];
    }
    list->data[index] = value;
}
void pushBack(Arraylist* list, list_entry value) {
    if(listIsFull(*list)) { 
        expandList(list);
    }
    list->data[list->length++] = value;
}
list_entry removeNth(Arraylist* list, long index) {
    assert(!"Invalid index!" || ((index < list->length) && (index >= 0)));
    // if(!((index < list->length) && (index >= 0))) return -1;
    list_entry removed = list->data[index];
    for(int i = index; i < list->length - 1; i++) {
        list->data[i] = list->data[i+1];
    }
    list->length--;
    return removed;
}
list_entry popBack(Arraylist* list) {
    if(listIsEmpty(*list)) {
        return -1;
    }
    return list->data[--list->length];
}
