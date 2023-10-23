#include <stdlib.h>
#include "stack.h"

Stack* newStack() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = -1;
    new_stack->capacity = 10;
    new_stack->data = (stack_entry*) malloc(sizeof(stack_entry) * new_stack->capacity);
    return new_stack;
}
stack_entry pop(Stack *stack) {
    if(isEmpty(stack)) {
        return -1;
    }
    stack->top--;
    return *(stack->data + stack->top + 1);
}
stack_entry top(Stack *stack) {
    if(isEmpty(stack)) {
        return -1;
    }
    return *(stack->data + stack->top);
}
void push(Stack *stack, stack_entry value) {
    if(isFull(stack)) {
        expand(stack);
    }
    stack->top++;
    *(stack->data + stack->top) = value;
}
void stkcpy(Stack *stack1, Stack *stack2) {
    free(stack1);
    stack1 = (Stack*) malloc(sizeof(Stack));
    stack1->top = stack2->top;
    stack1->capacity = stack2->capacity;
    stack1->data = (stack_entry*) malloc(sizeof(stack_entry) * stack1->capacity);
    for(int i = 0; i <= stack2->top; i++) {
        *(stack1->data + i) = *(stack2->data + i);
    }
}
void expand(Stack *stack) {
    stack_entry *old_data = stack->data;
    stack->capacity *= 2;
    stack->data = (stack_entry*) malloc(sizeof(stack_entry) * stack->capacity);
    for(int i = 0; i <= stack->top; i++) {
        *(stack->data + i) = *(old_data + i);
    }
    free(old_data);
}
void destroy(Stack *stack) {
    free(stack->data);
    free(stack);
}
int isEmpty(Stack *stack) {
    return (stack->top < 0);
}
int isFull(Stack *stack) {
    return (stack->top >= stack->capacity - 1);
}
int size(Stack *stack) {
    return (stack->top + 1);
}
