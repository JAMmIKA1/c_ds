#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_entry First(Stack stack) {
    stack_entry x;
    while(!isEmpty(&stack)) {
        x = pop(&stack);
    }
    return x;
}
stack_entry Last(Stack stack) {
    return top(&stack);
}
void destroyStack(Stack *stack) {
    free(stack);
}
void copyStack(Stack stack, Stack *target) {
    Stack *temp = malloc(sizeof(Stack));
    temp = newStack();
    destroy(target);
    target = newStack();
    while(!isEmpty(&stack)) {
        push(temp, pop(&stack));
    }
    while(!isEmpty(temp)) {
        push(target, pop(temp));
    }
}
int sizeStack(Stack stack) {
    int x = 0;
    while(!isEmpty(&stack)) {
        pop(&stack);
        x++;
    }
    return x;
}
void printStack(Stack stack) {
    while(!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
}
int main() {
    Stack* stack = newStack();
    Stack* tmp = newStack();
    for(int i = 0; i < 10; i++) {
        push(stack, i*i);
    }
    stkcpy(tmp, stack);
    printStack(*tmp);
}
