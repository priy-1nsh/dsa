#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class Solution {
    // converting array to LL
    Node* convertArrToLL(vector<int>& arr, int n) {
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(arr[i]);
            temp->next = newNode;
            newNode->prev = temp;

            temp = newNode;
        }
        return head;
    }
};

int main() { return 0; }