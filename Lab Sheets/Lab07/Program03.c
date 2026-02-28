#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// stack implementation

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

// queue implementation

typedef struct Queue
{
    Node *start;
    Node *end;
    int size;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 0;
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

// queue operations
void enqueue(Queue *queue, int x)
{

    Node *temp = createNode(x);

    // if q is empty
    if (queue->start == NULL)
    {
        queue->start = queue->end = temp;
    }
    else
    {
        queue->end->next = temp;
        queue->end = temp;
    }
    queue->size++;
}

int dequeue(Queue *queue)
{
    if (queue->start == NULL)
    {
        printf("Queue is empty, nothing to pop\n");
        return -1;
    }

    int el = queue->start->data;
    Node *temp = queue->start;
    queue->start = queue->start->next;
    free(temp);
    queue->size--;

    if (queue->start == NULL)
    {
        // queue got empty
        queue->end = NULL;
    }
    return el;
}

int front(Queue *queue)
{
    if (queue->start == NULL)
    { // ALTERNATE CONDITION IS queue->end == NULL
        // queue is Empty
        printf("Queue is Empty, Nothing to peek\n");
        return -1;
    }
    return queue->start->data;
}

void interleaveQueue(Queue *q, int size)
{
    int n = size / 2;
    Stack *st = createStack();

    // q -> st
    for (int i = 1; i <= n; i++)
    {
        push(st, front(q));
        dequeue(q);
    }

    // st -> q
    for (int i = 1; i <= n; i++)
    {
        enqueue(q, pop(st));
    }

    // q -> st
    for (int i = 1; i <= n; i++)
    {
        push(st, front(q));
        dequeue(q);
    }

    // final reversed queue
    for (int i = 1; i <= n; i++)
    {
        enqueue(q, pop(st));
        enqueue(q, front(q));
        dequeue(q);
    }

    // reverse the queue
    for (int i = 1; i <= size; i++)
    {
        push(st, front(q));
        dequeue(q);
    }

    for (int i = 1; i <= size; i++)
    {
        enqueue(q, top(st));
        pop(st);
    }
}

int main()
{

    Queue *q = createQueue();

    int size;
    scanf("%d", &size);

    int x;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &x);
        enqueue(q, x);
    }

    interleaveQueue(q, size);

    // print the queue
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", dequeue(q));
    }
}