#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int data,

         Node* next)
        : data(data), next(next) {}

    Node(int data) : data(data), next(nullptr) {}
};

// segregate even and odd values
Node* segregateEvenOdd(Node* head) {
    Node* evenHead = new Node(-1);
    Node* oddHead = new Node(-1);

    Node* even = evenHead;
    Node* odd = oddHead;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            even->next = temp;
            even = even->next;
        }
        else if (temp->data % 2 == 1) {
            odd->next = temp;
            odd = odd->next;
        }
        temp = temp->next;
    }

    even->next = oddHead->next;
    odd->next = NULL;
    return evenHead->next;
}

int main() {
    return 0;
}