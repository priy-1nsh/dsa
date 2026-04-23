#include <stdio.h>
#include <stdlib.h>

// step 1 : insert into the hashTable
// step 2 : search into the hashTable

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}

// Now, insert in a linked list in the sorted order
Node* sortedInsert(Node* head, int key) {
    Node* newNode = createNode(key);
    // insert key at the correct place

    // insert at the beginning
    if (head == NULL || head->data > key) {
        newNode->next = head;
        return newNode;
    }

    // insert at the correct place
    Node* temp = head;
    while (temp->next != NULL && temp->next->data < key) {
        temp = temp->next;
    }

    // we are at the correct Node temp
    // we need to insert after this temp Node
    // insert
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// search in a sorted linked list in O(N)
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

    int A[nA];
    for (int i = 0; i < nA; i++) {
        scanf("%d", &A[i]);
    }

    int B[nB];
    for (int i = 0; i < nB; i++) {
        scanf("%d", &B[i]);
    }

    // create the hashTable of heads of the linked lists
    Node* hashTable[m];

    // initialize it with NULL
    for (int i = 0; i < m; i++) {
        hashTable[i] = NULL;
    }

    // insert the elements
    for (int i = 0; i < nA; i++) {
        // find the index of the hashTable where we need to insert
        int index = A[i] % m;
        hashTable[index] = sortedInsert(hashTable[index], A[i]);
        // head = return head at that index
    }

    // printf("\nHash Table:\n");
    // for (int i = 0; i < m; i++) {
    //     printf("%d: ", i);
    //     Node* temp = hashTable[i];
    //     while (temp) {
    //         printf("%d -> ", temp->data);
    //         temp = temp->next;
    //     }
    //     printf("NULL\n");
    // }

    // search elements of B
    int found = 0;
    printf("Intersection : ");

    for (int i = 0; i < nB; i++) {
        // find hash index
        int index = B[i] % m;
        if (search(hashTable[index], B[i])) {
            printf("%d ", B[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }

    return 0;
}