#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef char queue_entry;
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
void expand(Queue* target);
void qdestroy(Queue* target);
int isEmpty(Queue* target);
int isFull(Queue* target);

#endif // !QUEUE_H
