class Node {
    constructor(x, next = null) {
        this.data = x;
        this.next = null;
    }
};

class Solution {
    insertBeforeX(head, el, x) {
        if (head == null) return null;

        let prev = null;
        let temp = head;

        // can't access next of null so have to handle this case separately
        if (head.data === el) {
            let newNode = new Node(el);
            newNode.next = head;
            return newNode;
        }

        while (temp != null) {
            if (temp.data == x) {
                let newNode = new Node(el);
                prev.next = newNode;
                newNode.next = temp;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }
};

function printLL(head) {
    let temp = head;
    while (temp !== null) {
        console.log(temp.data + " ");
        temp = temp.next;
    }
}

function main() {
    // make a LL
    let head = new Node(3);
    head.next = new Node(1);
    head.next.next = new Node(5);
    head.next.next.next = new Node(8);

    let sol = new Solution();
    head = sol.insertBeforeX(head, 0, 5);

    printLL(head);
}

main();