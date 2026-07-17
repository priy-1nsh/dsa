/*
Definition of singly linked list:
class ListNode{
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* &head1, ListNode* &head2) {
            //your code goes here

            // dummy Node concept
            ListNode dummy = ListNode(-1);
            ListNode* curr = &dummy;

            // can write the same thing as above like this -
            // ListNode* dummy = new ListNode(-1);
            // ListNode* curr = dummy;
            
            ListNode* temp1 = head1;
            ListNode* temp2 = head2;

            int carry = 0;

            while (temp1 != NULL || temp2 != NULL) {
                // run until both does not become NULL, because even if one is not NULL, then we still have numbers left
                int sum = carry;
                if (temp1) sum = sum + temp1->val;
                if (temp2) sum = sum + temp2->val;

                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                if (temp1) temp1 = temp1->next;
                if (temp2) temp2 = temp2->next;
                // can't go to the next of the nullptr

                carry = sum / 10;
            }
            if (carry) {
                // carry is still there
                curr->next = new ListNode(carry);
            }
            return dummy.next; // dummy.next is of type pointer
        }
};