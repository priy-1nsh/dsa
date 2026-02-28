#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// implement stack
// struct definitions for Node and Stack
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int size;
    struct Node *top;
} Stack;

// helper functions
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node *createNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Stack Operations
void push(Stack *st, int x)
{
    Node *newNode = createNode(x);
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
    int el = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    st->size--;
    free(temp);
    return el;
}

int peek(Stack *st)
{
    if (st->top == NULL)
    {
        printf("Stack is Empty, nothing to peek.\n");
        return -1;
    }
    return st->top->data;
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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// findPSE and findNSE
int *findPSE(int *arr, int n)
{
    int *pse = malloc(n * sizeof(int));
    Stack *st = createStack();
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(st) && arr[peek(st)] >= arr[i])
        {
            pop(st);
        }

        if (isEmpty(st))
            pse[i] = -1;
        else
        {
            pse[i] = peek(st); // <
        }

        push(st, i);
    }
    return pse;
}

int *findNSE(int *arr, int n)
{
    int *nse = malloc(n * sizeof(int));
    Stack *st = createStack();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty(st) && arr[peek(st)] >= arr[i])
        {
            pop(st);
        }

        if (isEmpty(st))
            nse[i] = n;
        else
        {
            nse[i] = peek(st); // <
        }
        push(st, i);
    }
    return nse;
}

// Program Start
int largestRectangleArea(int *arr, int n)
{
    int *pse = findPSE(arr, n);
    int *nse = findNSE(arr, n);

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, arr[i] * (nse[i] - pse[i] - 1));
    }
    return maxArea;
}

int main()
{

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = largestRectangleArea(arr, n);

    printf("%d", ans);

    free(arr);

    return 0;
}