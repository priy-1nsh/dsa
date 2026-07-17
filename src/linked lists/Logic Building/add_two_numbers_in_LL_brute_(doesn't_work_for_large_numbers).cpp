/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* &head1, ListNode* &head2) {
            //your code goes here
            ListNode* temp1 = head1;
            ListNode* temp2 = head2;

            long long num1 = 0;
            long long num2 = 0;

            long long multiplier = 1;

            while (temp1 != NULL) {
                num1 = num1 + (temp1->data) * multiplier;
                multiplier = multiplier * 10;
                temp1 = temp1->next;
            }

            multiplier = 1;

            while (temp2 != NULL) {
                num2 = num2 + (temp2->data) * multiplier;
                multiplier = multiplier * 10;
                temp2 = temp2->next;
            }

            long long sum = num1 + num2;

            ListNode dummy(-1);
            ListNode* temp = &dummy;
            if (sum == 0) {
                return new ListNode(0, nullptr);
            }
            while (sum > 0) {
                int lastDigit = sum % 10;
                temp->next = new ListNode(lastDigit, nullptr);
                temp = temp->next;
                sum = sum / 10;
            }
            return dummy.next;
        }
};