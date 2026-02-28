#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

// implement stack
// struct definitions for Node and Stack and Pair
typedef struct Pair
{
    int first;
    int second;
} Pair;

typedef struct Node
{
    Pair data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int size;
    struct Node *top;
} Stack;

bool isEmpty(Stack *st);
int getMin(Stack *st);

// helper functions
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node *createNode(Pair p)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    (newNode->data).first = p.first;
    (newNode->data).second = p.second;
    newNode->next = NULL;
    return newNode;
}

// Stack Operations
void push(Stack *st, int x)
{
    Pair p;
    if (isEmpty(st))
    {
        p.first = x;
        p.second = x;
    }
    else
    {
        // non empty stack
        int mini = min(x, getMin(st));
        p.first = x;
        p.second = mini;
    }

    Node *newNode = createNode(p);
    newNode->next = st->top;
    st->top = newNode;
    st->size++;
}

int pop(Stack *st)
{
    if (st->top == NULL)
    {
        printf("Stack is Empty, nothing to pop.\n");
        return -1;
    }
    Pair el = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    st->size--;
    free(temp);
    return el.first;
}

int peek(Stack *st)
{
    if (st->top == NULL)
    {
        printf("Stack is Empty, nothing to peek.\n");
        return -1;
    }
    return (st->top->data).first;
}

int currSize(Stack *st)
{
    return st->size;
}

bool isEmpty(Stack *st)
{
    if (st->top == NULL)
    {
        return true;
    }
    else
        return false;
}

int getMin(Stack *st)
{
    if (isEmpty(st))
    {
        return -1;
    }
    return (st->top->data).second;
}

int main()
{
    Stack *st = createStack();
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            int x;
            scanf("%d", &x);
            push(st, x);
        }
        else if (choice == 2)
        {
            if (isEmpty(st))
            {
                printf("Stack Empty\n");
            }
            else
            {
                printf("Popped: %d\n", pop(st));
            }
        }
        else if (choice == 3)
        {
            if (isEmpty(st))
            {
                printf("Stack Empty\n");
            }
            else
            {
                printf("Minimum: %d\n", getMin(st));
            }
        }
        else if (choice == 4)
        {
            if (isEmpty(st))
            {
                printf("Stack Empty\n");
            }
            else
            {
                printf("Top: %d\n", peek(st));
            }
        }
    }
    return 0;
}