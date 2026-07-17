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
    private:
        // recursive function
        int addOneToList(ListNode* temp) {
            if (temp == NULL) {
                return 1;
            }
            int carry = addOneToList(temp->next);
            int sum = temp->data + carry;
            temp->data = sum % 10;
            return sum / 10;
        }

   public:
    ListNode* addOne(ListNode* head) {
        int carry = addOneToList(head);
        if (carry) {
            ListNode* newNode = new ListNode(1)
            newNode->next = head;
            return newNode;
        }
        return head;
    }
};