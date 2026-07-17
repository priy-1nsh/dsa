#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next, *prev;
        Node(int data) : data(data), next(next), prev(prev) {}
        
        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* reverseDoublyLL(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return NULL;

    Node* temp = head;
    while (temp->next != NULL) {
        swap(temp->next, temp->prev);
        temp = temp->back;
    }
    swap(temp->next, temp->prev);
    return temp;
}

int main() {
    return 0;
}