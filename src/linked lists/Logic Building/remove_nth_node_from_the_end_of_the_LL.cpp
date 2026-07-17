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
    int total(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
        // O(total)
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = total(head);
        int cntFromStart = total - n + 1;

        if (cntFromStart == 1) {
            // remove the first node
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt = 0;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != NULL) {
            cnt++;
            if (cnt == cntFromStart) {
                // gotta remove temp at this point
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};