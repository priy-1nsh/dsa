/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
    if (head == null || head.next == null ) return head;
    let oddHead = head;
    let evenHead = head.next;
    let even = evenHead;
    let odd = oddHead;
    while (even != null && even.next != null) {
        odd.next = odd.next.next;
        even.next = even.next.next;
        even = even.next;
        odd = odd.next;
    }

    odd.next = evenHead;
    return oddHead;;
};