#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct Node
{
    double data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int size;
    struct Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node *createNode(double x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *st, double x)
{
    Node *newNode = createNode(x);
    newNode->next = st->top;
    st->top = newNode;
    st->size++;
}

double pop(Stack *st)
{
    double el = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    st->size--;
    free(temp);
    return el;
}

int currSize(Stack *st)
{
    return st->size;
}

int main()
{
    char expr[MAX];
    scanf("%s", expr);

    Stack *st = createStack();
    int len = strlen(expr);

    for (int i = 0; i < len; i++)
    {
        char ch = expr[i];

        if (isdigit(ch))
        {
            push(st, (double)(ch - '0'));
        }
        else
        {
            if (currSize(st) < 2)
            {
                printf("Invalid Expression\n");
                return 0;
            }

            double right = pop(st);
            double left = pop(st);
            double result;

            if (ch == '+')
                result = left + right;
            else if (ch == '-')
                result = left - right;
            else if (ch == '*')
                result = left * right;
            else if (ch == '/')
            {
                if (right == 0)
                {
                    printf("Invalid Expression\n");
                    return 0;
                }
                result = left / right;
            }
            else
            {
                printf("Invalid Expression\n");
                return 0;
            }

            push(st, result);
        }
    }

    if (currSize(st) != 1)
    {
        printf("Invalid Expression\n");
        return 0;
    }

    printf("%.2lf\n", pop(st));
    return 0;
}
