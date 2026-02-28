#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

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

int findMaxLength(char *string)
{
    int result = 0;
    int len = strlen(string);

    Stack *st = createStack();

    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (string[i] == '(')
        {
            push(st, i);
        }
        else
        {
            // a closing bracket
            pop(st);

            if (!isEmpty(st))
                result = max(result, i - peek(st));
            else
            {
                push(st, i); // make it new base
            }
        }
    }
    return result;
}

int main()
{

    char str[1000];
    scanf("%s", str);

    int ans = findMaxLength(str);

    printf("%d\n", ans);

    return 0;
}