#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
   Each node represents a gas station index
*/
typedef struct Node {
    int index;
    struct Node *next;
} Node;

/*
   Queue structure
*/
typedef struct Queue {
    Node *front;
    Node *back;
    int size;
} Queue;

/* Create new node */
Node* createNode(int index) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

/* Create queue */
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->back = NULL;
    q->size = 0;
    return q;
}

/* Check if queue is empty */
bool isEmpty(Queue *q) {
    return (q->size == 0);
}

/* Enqueue station index */
void enqueue(Queue *q, int index) {
    Node *temp = createNode(index);

    if (isEmpty(q)) {
        q->front = q->back = temp;
    } else {
        q->back->next = temp;
        q->back = temp;
    }

    q->size++;
}

/* Dequeue station index */
int dequeue(Queue *q) {
    if (isEmpty(q))
        return -1;

    Node *temp = q->front;
    int index = temp->index;

    if (q->size == 1) {
        q->front = q->back = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    q->size--;
    return index;
}

/*
   Function to find starting index
*/
int circularTour(int *gas, int *dist, int n) {

    int total = 0;

    // Step 1: Check overall feasibility
    for (int i = 0; i < n; i++) {
        total += gas[i] - dist[i];
    }

    if (total < 0)
        return -1;   // impossible

    // Step 2: Try to find valid start using queue simulation
    Queue *q = createQueue();

    int start = 0;
    int petrol = 0;
    int count = 0;

    while (start < n) {

        // Add current station into tour
        enqueue(q, start);
        petrol += gas[start] - dist[start];
        count++;

        // If petrol becomes negative, reset tour
        if (petrol < 0) {

            // Remove all stations from queue
            while (!isEmpty(q))
                dequeue(q);

            // Move start to next station
            start = start + count;

            petrol = 0;
            count = 0;
        }
        else if (count == n) {
            // Completed full circle
            return q->front->index;
        }
        else {
            // Move to next station circularly
            start = (start + 1) % n;
        }
    }

    return -1;
}

int main() {

    int n;
    scanf("%d", &n);

    int *gas = (int*)malloc(n * sizeof(int));
    int *dist = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &gas[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &dist[i]);

    int result = circularTour(gas, dist, n);

    printf("%d\n", result);

    free(gas);
    free(dist);

    return 0;
}