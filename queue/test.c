#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void printQueue(Queue queue);
queue_entry returnFirst(Queue* queue);
queue_entry returnLast(Queue* queue);
void destroy(Queue *queue);
void copy(Queue *dst, Queue src);
size_t returnSize(Queue queue);
queue_entry returnFirstCpy(Queue queue);

int main() {
    Queue *sections = newQueue();
    Queue *groups = newQueue();
    Queue *merge = newQueue();
    for(int i = 0; i < 10; i++) {
        enqueue(sections, i + 1);
        enqueue(groups, i + 50);
    }
    printf("Sections: \t");
    printQueue(*sections);
    printf("\nGroups: \t");
    printQueue(*groups);
    while(!(qIsEmpty(sections) || qIsEmpty(groups)))
        enqueue(merge, dequeue(sections)*10+dequeue(groups));
    printf("\nMerged queue: \t");
    printQueue(*merge);
}

size_t returnSize(Queue queue) {
    size_t counter = 0;
    while(!qIsEmpty(&queue)) {
        dequeue(&queue);
        counter++;
    }
    return counter;
}
void copy(Queue *dst, Queue src) {
    destroy(dst);
    while(!qIsEmpty(&src))
        enqueue(dst, dequeue(&src));
}
void destroy(Queue *queue) {
    while(!qIsEmpty(queue))
        dequeue(queue);
}
queue_entry returnFirstCpy(Queue queue) {
    return dequeue(&queue);
}
queue_entry returnLast(Queue* queue) {
    queue_entry result;
    Queue* tmp = newQueue();
    while(qsize(queue) > 1)
        enqueue(tmp, dequeue(queue));
    result = dequeue(queue);
    quecpy(queue, tmp);
    return result;
}
void printQueue(Queue queue) {
    while(!qIsEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
}
queue_entry returnFirst(Queue* queue) {
    return dequeue(queue);
}
