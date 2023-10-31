#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef int queue_entry;
typedef struct {
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
    queue_entry* data;
} Queue;

Queue* newQueue();
queue_entry dequeue(Queue* target);
queue_entry front(Queue* target);
queue_entry rear(Queue* target);
size_t qsize(Queue* target);
void enqueue(Queue* queue, queue_entry value);
void quecpy(Queue* dst, Queue* src);
void qExpand(Queue* target);
void qDestroy(Queue* target);
int qIsEmpty(Queue* target);
int qIsFull(Queue* target);

#endif // !QUEUE_H
