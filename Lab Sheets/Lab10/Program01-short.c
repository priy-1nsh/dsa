#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node* sortedInsert(Node* head, int key) {
    Node* newNode = createNode(key);

    if (head == NULL || key < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data < key) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int m, nA, nB;
    scanf("%d %d %d", &m, &nA, &nB);

    int A[nA], B[nB];

    for (int i = 0; i < nA; i++) scanf("%d", &A[i]);
    for (int i = 0; i < nB; i++) scanf("%d", &B[i]);

    Node* hashTable[m];

    for (int i = 0; i < m; i++) hashTable[i] = NULL;

    for (int i = 0; i < nA; i++) {
        int index = A[i] % m;
        hashTable[index] = sortedInsert(hashTable[index], A[i]);
    }

    int found = 0;
    printf("Intersection: ");

    for (int i = 0; i < nB; i++) {
        int index = B[i] % m;
        if (search(hashTable[index], B[i])) {
            printf("%d ", B[i]);
            found = 1;
        }
    }

    if (!found) printf("None");

    return 0;
}