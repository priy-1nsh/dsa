#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

class Solution {
   public:
    Node* insertBeforeX(Node* head, int el, int x) {
        if (head == nullptr) {
            return head;
        }

        if (head->data == x) {
            Node* newNode = new Node(el, head);
            return newNode;
        }

        Node* prev = nullptr;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == x) {
                Node* newNode = new Node(el, temp);
                prev->next = newNode;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};

int main() { return 0; }