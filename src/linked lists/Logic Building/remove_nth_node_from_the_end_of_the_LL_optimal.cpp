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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        int cnt = n;
        while (fast != NULL) {
            if (cnt == 0) {
                break;
            }
            cnt--;
            fast = fast->next;
        }
        // if fast has reached null, then we need to delete the first head
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* slow = head;
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // now we remove the node
        slow->next = slow->next->next;
        return head;
    }
};