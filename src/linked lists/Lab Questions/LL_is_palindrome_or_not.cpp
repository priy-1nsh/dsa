#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;

    ListNode(int data,

         ListNode* next)
        : data(data), next(next) {}

    ListNode(int data) : data(data), next(nullptr) {}
};

class Solution {
   private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

   public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midListNode = slow->next;
        ListNode* newHead = reverseLL(midListNode);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != NULL) {
            if (first->data != second->data) {
                newHead = reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        newHead = reverseLL(newHead);
        return true;
    }
};

int main() { return 0; }