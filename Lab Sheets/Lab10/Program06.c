#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* createNode(int k, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = k;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// insert the n keys using separate chaining
Node* insertIntoLL(Node* head, int k) {
    if (head == NULL) {
        return createNode(k, 1);
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp->key == k) {
            temp->value++;
            return head;
        }
        if (temp->next == NULL) break;

        temp = temp->next;
    }
    // else - insert at the end
    temp->next = createNode(k, 1);
    return head;
}

int main() {
    int m, N;
    scanf("%d %d", &m, &N);

    int keys[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &keys[i]);
    }

    Node* hashTable[m];
    // initialize hashTable
    for (int i = 0; i < m; i++) {
        hashTable[i] = NULL;
    }

    // insert into the hashTable
    for (int i = 0; i < N; i++) {
        int index = keys[i] % m;
        hashTable[index] = insertIntoLL(hashTable[index], keys[i]);
    }

    // print the final state of the hashTable
    for (int i = 0; i < m; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] == NULL)
            printf("Empty");
        else {
            Node* temp = hashTable[i];
            while (temp != NULL) {
                printf("[%d:%d]", temp->key, temp->value);
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
        }
        printf("\n");
    }

    // find the most frequent element
    int maxFreq = -1;
    int answer = -1;
    for (int i = 0; i < m; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            if (temp->value > maxFreq) {
                maxFreq = temp->value;
                answer = temp->key;
            } else if (temp->value == maxFreq && temp->key < answer) {
                answer = temp->key;
            }
            temp = temp->next;
        }
    }
    printf("%d %d", answer, maxFreq);

    return 0;
}