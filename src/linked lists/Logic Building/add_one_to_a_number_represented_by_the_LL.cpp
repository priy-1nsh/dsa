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
    void printLL(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val;
            temp = temp->next;
        }
    }

   private:
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
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
    ListNode* addOne(ListNode* head) {
        ListNode* newHead = reverseLL(head);
        int carry = 1;
        ListNode* temp = newHead;
        while (temp != NULL) {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            temp = temp->next;
        }
        if (carry) temp = new ListNode(carry);

        // now again reverse the LL
        ListNode* finalHead = reverseLL(newHead);
        return finalHead;
    }
};
