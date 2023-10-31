#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef int stack_entry;
typedef struct {
    long top;
    size_t capacity;
    stack_entry *data;
} Stack;

Stack* newStack();
stack_entry pop(Stack *stack);
stack_entry top(Stack *stack);
stack_entry returnFirst(Stack *stack);
size_t stkSize(Stack *stack);
void push(Stack *stack, stack_entry data);
void stkcpy(Stack *stack1, Stack *stack2);
void stkExpand(Stack *stack);
void stkDestroy(Stack *stack);
int stkIsEmpty(Stack *stack);
int stkIsFull(Stack *stack);
int blncchk(char *target);

#endif // !STACK_H
