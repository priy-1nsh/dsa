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

// Program Start
// modify the next greater element to get the wait
int *findNGL(int *arr, int n)
{
    int *ans = malloc(n * sizeof(int));
    Stack *st = createStack();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty(st) && arr[peek(st)] <= arr[i])
        {
            pop(st);
        }

        if (isEmpty(st))
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = peek(st) - i;
        }
        push(st, i);
    }
    return ans;
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

    int *ans = findNGL(arr, n);

    // print the ans
    // print the answer array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}