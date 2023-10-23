#ifndef STACK_H
#define STACK_H

typedef char stack_entry;
typedef struct {
    int top;
    int capacity;
    stack_entry *data;
} Stack;

Stack* newStack();
stack_entry pop(Stack *stack);
stack_entry top(Stack *stack);
void push(Stack *stack, stack_entry data);
void stkcpy(Stack *stack1, Stack *stack2);
void expand(Stack *stack);
void destroy(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
int size(Stack *stack);

#endif // !STACK_H
