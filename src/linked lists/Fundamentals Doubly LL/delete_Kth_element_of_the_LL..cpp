#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data, Node* next, Node* prev) : data(data), next(next), back(back) {}
    Node(int data) : data(data), next(nullptr), back(nullptr) {}
};

// delete Kth
deleteKthEl(Node* head, int k) {
    if (head == nullptr) return nullptr; // empty LL

    if (head->next == nullptr && head->back = nullptr) { // single element LL
        delete head;
        return nullptr;
    }

    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            break;
        }
        temp = temp->next;
    }

    if (temp->back == nullptr && temp->next != nullptr) {
        // at the head
        Node* front = temp->next;
        temp->next = nullptr;
        front->back = nullptr;
        delete temp;
        return front;
    }

    else if (temp->next == nullptr) {
        // at the tail
        Node* prev = temp->back;
        temp->back = nullptr;
        prev->next = nullptr;
        delete temp;
        return prev;
    }

    else {
        // in somewhere middle
        Node* front = temp->next;
        Node* prev = temp->back;

        prev->next = front;
        front->back = prev;

        temp->back = nullptr;
        temp->next = nullptr;

        delete temp;
        return head;
    }
    return head;
    
}

int main() {

    return 0;
}