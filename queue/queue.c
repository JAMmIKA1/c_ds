#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue* newQueue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->capacity = 10;
    new_queue->front = 0;
    new_queue->rear = new_queue->capacity - 1;
    new_queue->size = 0;
    new_queue->data = (queue_entry*) malloc(sizeof(queue_entry)*new_queue->capacity);
    memset(new_queue->data, 0, sizeof(queue_entry)*new_queue->capacity);
    return new_queue;
}
queue_entry dequeue(Queue* target) {
    if(qIsEmpty(target)) {
        return -1;
    }
    target->size--;
    queue_entry value = target->data[target->front];
    target->front = (target->front + 1) % target->capacity;
    return value;
}
queue_entry front(Queue* target) {
    if(qIsEmpty(target)) {
        return -1;
    }
    return target->data[target->front];
}
queue_entry rear(Queue* target) {
    if(qIsEmpty(target)) {
        return -1;
    }
    return target->data[target->rear];
}
size_t qsize(Queue* target) {
    return target->size;
}
void enqueue(Queue* target, queue_entry value) {
    if(qIsFull(target)) {
        qExpand(target);
    }
    target->size++;
    target->rear = (target->rear + 1) % target->capacity;
    target->data[target->rear] = value;
    return;
}
void quecpy(Queue* dst, Queue* src) {
    qDestroy(dst);
    dst = (Queue*) malloc(sizeof(Queue));
    dst->capacity = src->capacity;
    dst->front = src->front;
    dst->rear = src->rear;
    dst->size = src->size;
    dst->data = (queue_entry*) malloc(sizeof(queue_entry)*dst->capacity);
    memcpy(dst->data, src->data, sizeof(queue_entry)*src->size);
}
void qExpand(Queue* target) {
    target->capacity *= 2;
    queue_entry* new_data = (queue_entry*) malloc(sizeof(queue_entry)*target->capacity);
    memset(new_data, 0, sizeof(queue_entry)*target->capacity);
    for(int i = 0; i < target->size; i++) {
        new_data[i] = target->data[(target->front + i) % (target->capacity/2)];
    }
    target->front = 0;
    target-> rear = target->size-1;
    free(target->data);
    target->data = new_data;
}
void qDestroy(Queue* target) {
    free(target->data);
    free(target);
}

int qIsEmpty(Queue* target) {
    if(target->size == 0) {
        return 1;
    }
    return 0;
}
int qIsFull(Queue* target) {
    if(target->size >= target->capacity) {
        return 1;
    }
    return 0;
}
