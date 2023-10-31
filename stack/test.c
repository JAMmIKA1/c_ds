#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void printStack(Stack stack);
int sizeStack(Stack stack);
void copyStack(Stack stack, Stack *target);
void destroyStack(Stack *stack);
stack_entry Last(Stack stack);
stack_entry First(Stack stack);

int main() {
    Stack* group_ids = newStack();
    Stack* group_codes = newStack();
    Stack* section_codes = newStack();

    for(int i = 1 ; i <= 10; i++) {
        push(group_ids, i*10+ i*i + i+i/2);
    }
    printf("Group IDs:\t");
    printStack(*group_ids);
    while(!stkIsEmpty(group_ids)) {
        push(group_codes, top(group_ids)%10);
        push(section_codes, pop(group_ids)/10);
    }
    printf("\nSection codes:\t");
    printStack(*section_codes);
    printf("\nGroup codes:\t");
    printStack(*group_codes);
}

void printStack(Stack stack) {
    while(!stkIsEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
}
stack_entry First(Stack stack) {
    stack_entry x;
    while(!stkIsEmpty(&stack)) {
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
    stkDestroy(target);
    target = newStack();
    while(!stkIsEmpty(&stack)) {
        push(temp, pop(&stack));
    }
    while(!stkIsEmpty(temp)) {
        push(target, pop(temp));
    }
}
int sizeStack(Stack stack) {
    int x = 0;
    while(!stkIsEmpty(&stack)) {
        pop(&stack);
        x++;
    }
    return x;
}
