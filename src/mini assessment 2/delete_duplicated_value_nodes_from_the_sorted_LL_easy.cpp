SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    SinglyLinkedListNode* prev = head;
    SinglyLinkedListNode* temp = head->next;
    while (temp != NULL) {
        if (prev->data == temp->data) {
            temp = temp->next;
        } else {
            prev->next = temp;
            prev = temp;
            temp = temp->next;
        }
    }
    prev->next = NULL;
    return head;
}