#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// implement queue using array
typedef struct Queue
{
    int *queueArray;
    int maxSize;
    int currSize;
    int start;
    int end;
} Queue;

// function to create a queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->currSize = 0;
    queue->end = -1;
    queue->start = -1;
    queue->maxSize = capacity;
    queue->queueArray = (int *)malloc(queue->maxSize * sizeof(int));
    return queue;
}

// function to destroy the queue
void destroyQueue(Queue *queue)
{
    free(queue->queueArray);
    free(queue);
}

// queue operations - push, pop, top, isEmpty
void push(Queue *queue, int x)
{
    // edge case
    if (queue->currSize == queue->maxSize)
    {
        // queue is full
        printf("Queue is full");
        return;
    }

    if (queue->currSize == 0) // both start and end pointing to -1
        queue->start = queue->end = 0;
    else
        queue->end = (queue->end + 1) % queue->maxSize;
    queue->currSize++;
    queue->queueArray[queue->end] = x;
}

int pop(Queue *queue)
{
    // edge case - queue is empty
    if (queue->currSize == 0)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    int el = queue->queueArray[queue->start];
    if (queue->currSize == 1)
        queue->start = queue->end = -1;
    else
        queue->start = (queue->start + 1) % queue->maxSize;
    queue->currSize--;
    return el;
}

int front(Queue *queue)
{
    if (queue->currSize == 0)
    {
        // queue is empty
        printf("Queue is Empty\n");
        return -1;
    }

    return queue->queueArray[queue->start];
}

bool isEmpty(Queue *queue)
{
    return (queue->currSize == 0);
}

int main()
{
    Queue *q = createQueue(1000);
    push(q, 7);
    push(q, 8);
    push(q, 0);
    printf("%d\n", pop(q));
    printf("%d\n", pop(q));
    printf("%d\n", pop(q));
    printf("%d\n", front(q));
    printf("%d\n", front(q));

    return 0;
}