#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* newStack() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = -1;
    new_stack->capacity = 10;
    new_stack->data = (stack_entry*) malloc(sizeof(stack_entry) * new_stack->capacity);
    return new_stack;
}
stack_entry pop(Stack *stack) {
    if(stkIsEmpty(stack)) {
        return -1;
    }
    stack->top--;
    return *(stack->data + stack->top + 1);
}
stack_entry top(Stack *stack) {
    if(stkIsEmpty(stack)) {
        return -1;
    }
    return *(stack->data + stack->top);
}
void push(Stack *stack, stack_entry value) {
    if(stkIsFull(stack)) {
        stkExpand(stack);
    }
    stack->top++;
    *(stack->data + stack->top) = value;
}
void stkcpy(Stack *stack1, Stack *stack2) {
    stkDestroy(stack1);
    stack1 = (Stack*) malloc(sizeof(Stack));
    stack1->top = stack2->top;
    stack1->capacity = stack2->capacity;
    stack1->data = (stack_entry*) malloc(sizeof(stack_entry) * stack1->capacity);
    memcpy(stack1->data, stack2->data, sizeof(stack_entry)*(stack1->top + 1));
}
void stkExpand(Stack *stack) {
    stack_entry *old_data = stack->data;
    stack->capacity *= 2;
    stack->data = (stack_entry*) malloc(sizeof(stack_entry) * stack->capacity);
    memcpy(stack->data, old_data, sizeof(stack_entry)*(stack->top + 1));
    free(old_data);
}
int blncchk(char *target) {
    Stack* stack = newStack();
    char opened[] = {'(', '{', '[', '<'};
    char closed[] = {')', '}', ']', '>'};
    for(int i = 0; *(target + i) != '\0'; i++) {
        char current = *(target + i);
        for(int j = 0; j < 4; j++) {
            if(current == opened[j]) {
                push(stack, opened[j]);
                break;
            }
        }
        for(int j = 0; j < 4; j++) {
            if(current == closed[j]) {
                if(opened[j] == top(stack)) {
                    pop(stack);
                    break;
                }
                else {
                    stkDestroy(stack);
                    return 0;
                }
            }
        }
    }
    if(stkIsEmpty(stack)) {
        stkDestroy(stack);
        return 1;
    }
    else {
        stkDestroy(stack);
        return 0;
    }
}
void stkDestroy(Stack *stack) {
    free(stack->data);
    free(stack);
}
int stkIsEmpty(Stack *stack) {
    return (stack->top < 0);
}
int stkIsFull(Stack *stack) {
    return (stack->top >= stack->capacity - 1);
}
long stkSize(Stack *stack) {
    return (stack->top + 1);
}
