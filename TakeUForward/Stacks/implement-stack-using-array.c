#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *stackArray;
    int top;
    int capacity;
} ArrayStack;

// constructor
ArrayStack *createStack(int size)
{
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    stack->capacity = size;
    stack->top = -1;
    stack->stackArray = (int *)malloc(size * sizeof(int));
    return stack;
}

// destructor
void destroyStack(ArrayStack *stack)
{
    free(stack->stackArray);
    free(stack);
}

// functions with a pointer to the struct
void push(ArrayStack *stack, int x)
{
    if (stack->top >= stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->stackArray[stack->top] = x;
}

int pop(ArrayStack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    int el = stack->stackArray[stack->top];
    stack->top--;
    return el;
}

int top(ArrayStack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    return stack->stackArray[stack->top];
}

bool isEmpty(ArrayStack *stack)
{
    return stack->top == -1;
}

int size(ArrayStack *stack)
{
    return stack->top + 1;
}

int main()
{
    ArrayStack *stack = createStack(1000);
    push(stack, 5);
    push(stack, 6);
    push(stack, 8);

    printf("%d\n", pop(stack));

    printf("%d\n", top(stack));

    pop(stack);
    pop(stack);

    pop(stack);

    return 0;
}