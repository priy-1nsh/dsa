#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Full Dequeue Implementation
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Dequeue
{
    Node *front;
    Node *back;
    int size;
} Dequeue;

Node *createNode(int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Dequeue *createDequeue()
{
    Dequeue *dequeue = malloc(sizeof(Dequeue));
    dequeue->size = 0;
    dequeue->front = NULL;
    dequeue->back = NULL;
    return dequeue;
}

bool isEmpty(Dequeue *dq)
{
    return (dq->size == 0);
}

// push at front
void push_front(Dequeue *dq, int x)
{
    Node *temp = createNode(x);

    if (isEmpty(dq))
    {
        dq->front = dq->back = temp;
    }
    else
    {
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }

    dq->size++;
}

// push at back
void push_back(Dequeue *dq, int x)
{
    Node *temp = createNode(x);

    if (isEmpty(dq))
    {
        dq->front = dq->back = temp;
    }
    else
    {
        temp->prev = dq->back;
        dq->back->next = temp;
        dq->back = temp;
    }

    dq->size++;
}

// pop from front
int pop_front(Dequeue *dq)
{
    if (dq->size == 0)
    {
        printf("DQ is Empty, nothing to pop\n");
        return -1;
    }

    Node *temp = dq->front;
    int el = dq->front->data;

    if (dq->size == 1)
    {
        dq->front = dq->back = NULL;
    }
    else
    {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    dq->size--;
    free(temp);
    return el;
}

int pop_back(Dequeue *dq)
{
    if (dq->size == 0)
    {
        printf("DQ is Empty, nothing to pop\n");
        return -1;
    }

    Node *temp = dq->back;
    int el = dq->back->data;
    if (dq->size == 1)
    {
        dq->front = dq->back = NULL;
    }
    else
    {
        dq->back = dq->back->prev;
        dq->back->next = NULL;
    }

    dq->size--;
    free(temp);
    return el;
}

int front(Dequeue *dq)
{
    if (isEmpty(dq))
    {
        printf("DQ is Empty\n");
        return -1;
    }
    return dq->front->data;
}

int back(Dequeue *dq)
{
    if (isEmpty(dq))
    {
        printf("DQ is Empty\n");
        return -1;
    }
    return dq->back->data;
}

// Sliding Window Maximum
int *slidingWindowMaximum(int *arr, int n, int k)
{
    int *ans = malloc((n - k + 1) * sizeof(int));

    Dequeue *dq = createDequeue();

    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(dq) && front(dq) < i - k + 1)
        {
            pop_front(dq);
        }
        while (!isEmpty(dq) && arr[back(dq)] <= arr[i])
        {
            pop_back(dq);
        }

        push_back(dq, i);

        if (i >= k - 1)
        {
            ans[i - k + 1] = arr[front(dq)];
        }
    }
    return ans;
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }

    int *ans = slidingWindowMaximum(arr, n, k);

    // print the ans array
    for (int i = 0; i < n - k + 1; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}