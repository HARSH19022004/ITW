#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack is full. Cannot push %d.\n", item);
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
}

int top(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", top(&stack));

    printf("Popped elements: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}
