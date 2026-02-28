#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack Implementation
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

Node *createNode(int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// stack operations
void push(Stack *st, int x)
{
    Node *temp = createNode(x);
    temp->next = st->top;
    st->top = temp;
    st->size++;
}

int pop(Stack *st)
{
    if (st->top == NULL)
    {
        printf("Stack is Empty, nothing to pop !\n");
        return -1;
    }

    int el = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    free(temp);
    return el;
}

int top(Stack *st)
{
    if (st->top == NULL)
    {
        printf("Stack is Empty, nothing to pop !\n");
        return -1;
    }

    return st->top->data;
}

bool isEmpty(Stack *st)
{
    return (st->top == NULL);
}

int currSize(Stack *st)
{
    return st->size;
}

// Implement Queue using Stacks
// making push expensive

void enqueue(Stack *st1, Stack *st2, int x)
{
    while (!isEmpty(st1))
    {
        push(st2, pop(st1));
    }

    push(st1, x);

    while (!isEmpty(st2))
    {
        push(st1, pop(st2));
    }
}

int dequeue(Stack *st1)
{
    if (isEmpty(st1))
    {
        return -1;
    }
    return pop(st1);
}

int peek(Stack *st1)
{
    if (isEmpty(st1))
    {
        return -1;
    }
    return top(st1);
}

int main()
{

    Stack *st1 = createStack();
    Stack *st2 = createStack();

    int n;
    scanf("%d", &n);

    int choice;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &choice);

        if (choice == 1)
        {
            // enqueue
            int x;
            scanf("%d", &x);
            enqueue(st1, st2, x);
        }
        else if (choice == 2)
        {
            // dequeue and print the removed element
            printf("%d\n", dequeue(st1));
        }
        else if (choice == 3)
        {
            // peek
            printf("%d\n", peek(st1));
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}