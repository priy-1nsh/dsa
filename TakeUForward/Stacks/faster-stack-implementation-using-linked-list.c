#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// minimal implementation of stack using LL

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}

// push and pop functions
void push(Stack *st, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = st->top;
    st->top = temp;
}

int pop(Stack *st)
{

    // edge case - stack is empty
    if (!st->top)
    {
        printf("Nothing to pop - Empty Stack\n");
        return -1;
    }

    Node *temp = st->top;
    int el = temp->data;
    st->top = st->top->next;
    free(temp);
    return el;
}

int peek(Stack *st)
{
    // edge case - stack is empty
    if (!st->top)
    {
        printf("Nothing to pop - Empty Stack\n");
        return -1;
    }

    return st->top->data;
}

void freeStack(Stack *st)
{
    while (st->top)
    { // if it's not null, then it's true
        pop(st);
    }
    free(st);
}

int main()
{

    return 0;
}