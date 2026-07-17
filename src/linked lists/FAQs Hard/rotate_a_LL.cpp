/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        if (k == 0) return head;
        tail->next = head;

        ListNode* temp = head;
        int newTailPos = len - k - 1;

        while (newTailPos--) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};