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
    ListNode* sortList(ListNode*& head) {
        // your code goes here
        ListNode zeroDummy = ListNode(-1);
        ListNode oneDummy = ListNode(-1);
        ListNode twoDummy = ListNode(-1);

        ListNode* zero = &zeroDummy;
        ListNode* one = &oneDummy;
        ListNode* two = &twoDummy;

        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } else {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        if (zeroDummy.next != nullptr && oneDummy.next != nullptr &&
            twoDummy.next != nullptr) {
            // we have 0s, 1s, 2s
            zero->next = oneDummy.next;
            one->next = twoDummy.next;
            two->next = nullptr;
            return zeroDummy.next;
        } else if (zeroDummy.next != nullptr && oneDummy.next != nullptr) {
            // we have 0s, and 1s
            zero->next = oneDummy.next;
            one->next = nullptr;
            return zeroDummy.next;
        } else if (oneDummy.next != nullptr && twoDummy.next != nullptr) {
            // we have 1s, and 2s
            one->next = twoDummy.next;
            two->next = nullptr;
            return oneDummy.next;
        } else if (zeroDummy.next != nullptr && twoDummy.next != nullptr) {
            // we have 0s, and 2s
            zero->next = twoDummy.next;
            two->next = nullptr;
            return zeroDummy.next;
        } else if (zeroDummy.next) {
            return zeroDummy.next;
        } else if (oneDummy.next) {
            return oneDummy.next;
        } else if (twoDummy.next) {
            return twoDummy.next;
        }
        return nullptr;
    }
};

// better version -
// zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
// one->next = twoDummy.next;
// two->next = nullptr;

// if (zeroDummy.next) return zeroDummy.next;
// if (oneDummy.next) return oneDummy.next;
// return twoDummy.next;