class Solution {
   public:
    ListNode* oddEvenList(ListNode*& head) {
        // your code goes here
        if (head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        vector<int> arr;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            // standing at the last index
            arr.push_back(temp->data);
        }
        temp = head->next;  // safeguard above : what if head->next = NULL
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->data);

        int i = 0;
        temp = head;
        while (temp != NULL) {
            temp->data = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};