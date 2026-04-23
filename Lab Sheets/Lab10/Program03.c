#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* createNode(int k, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->key = k;
    newNode->value = v;
    return newNode;
}

void printHashTable(Node* hashTable[], int m) {
    for (int i = 0; i < m; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] == NULL) {
            printf("Empty");
        } else {
            // print the LL
            Node* temp = hashTable[i];
            while (temp != NULL) {
                printf("[%d:%d]", temp->key, temp->value);
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

Node* insertIntoLL(Node* head, int productID, int quantity) {
    if (head == NULL) {
        Node* newNode = createNode(productID, quantity);
        return newNode;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp->key == productID) {
            // replace with new quantity
            temp->value += quantity;
            return head;
        }

        // if the last node
        if (temp->next == NULL) break;

        temp = temp->next;
    }

    // not found so insert at the end
    temp->next = createNode(productID, quantity);
    return head;
}

int main() {
    int m, q;
    scanf("%d %d", &m, &q);

    // hashTable of the headers of the linked lists
    Node* hashTable[m];
    // initialize with NULL
    for (int i = 0; i < m; i++) {
        hashTable[i] = NULL;
    }

    for (int i = 0; i < q; i++) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int prodID, quantity;
            scanf("%d %d", &prodID, &quantity);
            // find hash
            int index = prodID % m;
            // insert
            hashTable[index] = insertIntoLL(hashTable[index], prodID, quantity);
        }

        else {
            // choice == 2;
            printHashTable(hashTable, m);
        }
    }

    return 0;
}