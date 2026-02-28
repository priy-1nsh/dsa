#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int size;
    Node *top;
} Stack;

// functions
// function to create a new node
Node *createNode(int x)
{
    // create a node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// function to create a Stack
Stack *createStack()
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;
}

// Stack Operations
void push(Stack *st, int x)
{
    Node *temp = createNode(x);
    temp->next = st->top;
    st->top = temp;
    st->size++;
}

int pop(Stack *st)
{
    // edge case - if stack is empty
    if (st->top == NULL)
    {
        printf("Stack is empty, you cannot pop.\n");
        return -1;
    }

    int el = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    st->size--;
    free(temp);
    return el;
}

int top(Stack *st)
{
    // edge case - if stack is empty
    if (st->top == NULL)
    {
        printf("Stack is empty, nothing to peek.\n");
        return -1;
    }

    return st->top->data;
}

int currSize(Stack *st)
{
    return st->size;
}

int main()
{
    Stack *st = createStack();
    push(st, 8);
    push(st, 9);
    push(st, 5);

    printf("%d\n", pop(st));
    printf("%d\n", top(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", currSize(st));

    return 0;
}