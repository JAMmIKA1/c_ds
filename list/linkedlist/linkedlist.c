#include <stdlib.h>
#include "linkedlist.h"

Linkedlist* newList() {
    Linkedlist* new_list = malloc(sizeof(Linkedlist));
    new_list->head = 0;
    new_list->tail = 0;
    new_list->length = 0;
    return new_list;
}
node* newNode(list_entry value) {
    node* new_node = malloc(sizeof(node));
    new_node->next = 0;
    new_node->data = value;
    return new_node;
}
node* getNthAddr(Linkedlist* list, unsigned long index) {
    if(index >= list->length) {
        return 0;
    }
    node* tmp = list->head;
    for(int i = 0; i < index; i++) {
        tmp = tmp->next;
    }
    return tmp;
}
list_entry getNth(Linkedlist* list, unsigned long index) {
    node* target = getNthAddr(list, index);
    if(target) {
        return target->data;
    }
    return -1;
}
list_entry getLast(Linkedlist* list) {
    if(listIsEmpty(list)) {
        return -1;
    }
    return list->tail->data;
}
void removeNth(Linkedlist* list, unsigned long index) {
    node *target, *tmp;
    if(listIsEmpty(list)) {
        return;
    }
    if(index == 0) {
        target = list->head;
        list->head = list->head->next;
        free(target);
        list->length--;
        return;
    }
    target = getNthAddr(list, index - 1);
    if(target == 0 || target->next == 0) return;
    tmp = target;
    target = target->next;
    tmp->next = target->next;
    free(target);
    list->length--;
}
void appendNode(Linkedlist* list, list_entry value) {
    if(listIsEmpty(list)) {
        list->head = list->tail = newNode(value);
        list->length++;
        return;
    }
    list->tail->next = newNode(value);
    list->tail = list->tail->next;
    list->length++;
}
void insert(Linkedlist* list, list_entry value, unsigned long index) {
    node* new_node;
    if(index == list->length) {
        appendNode(list, value);
        return;
    }
    if(index == 0) {
        new_node = newNode(value);
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
        return;
    }
    node* tmp = getNthAddr(list, index - 1);
    if(tmp == 0 || tmp->next == 0) return;
    new_node = newNode(value);
    new_node->next = tmp->next;
    tmp->next = new_node;
    list->length++;
}
int listIsEmpty(Linkedlist* list) {
    return !list->length;
}
void freeNodes(node* node) {
    if(node == 0) return;
    freeNodes(node->next);
    free(node);
}
void listDestroy(Linkedlist* list) {
    freeNodes(list->head);
    free(list);
}
