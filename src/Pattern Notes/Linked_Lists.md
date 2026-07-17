1. Segregae Odd and Even Nodes in LL

   https://takeuforward.org/plus/dsa/problems/segregate-odd-and-even-nodes-in-ll?subject=dsa&approach=optimal&tab=submissions

   Desc - **Odd and even pointer advancing together**, even always ahead of odd pointer. We know where we will point the odd and even pointer after every iteration, it is deterministic since it's positional.

2. Segregate Even and Odd Values

   LabSheet2 Q2

   Desc - **Single Pointer Scan with two build-up chains with starting nodes as dummy nodes.**

3. Middle of the LL

   https://takeuforward.org/plus/dsa/problems/find-middle-of-linked-list?subject=dsa&approach=optimal

   Desc - **Tortoise-Hare Algorithm / Concept of slow and fast pointers.**

   Note - 1 middle in odd-length LL, call it m2
    2 middles in even-length LL, call it m2

4. Reverse the LL (Iterative and **Recursive** Important)

   https://takeuforward.org/plus/dsa/problems/reverse-a-ll?subject=dsa&approach=optimal

   Desc - use of prev, front, temp in iterative solution. Recursive solution is different ball game - break the problem for 1 node, 2 nodes, 3 nodes and so on.

5. LL is palindrome or not

   https://takeuforward.org/plus/dsa/problems/check-if-ll-is-palindrome-or-not?subject=dsa&approach=optimal

   Desc - Reverse the LL from the position m2 + 1, and then reverse the linked list taking m2 as head and then compare both the halves.

6. Whenever we are creating a new list, use the **concept of dummy Node**.
   Create a dummy Node with -1 as the data in it, make a node `curr`, point it to dummyNode and then use `curr->next` to store the new nodes.

   https://takeuforward.org/plus/dsa/problems/add-two-numbers-in-ll?subject=dsa&approach=optimal-approach&tab=submissions

   Also read notes on Pointers and Reference, Stack v/s Heap variables.
   `new` keyword is the only way to make objects on Heap.
   whereas, every other local variable is created on the stack.

7. Sort a LL of 0s, 1s, and 2s

   https://takeuforward.org/plus/dsa/problems/sort-a-ll-of-0's-1's-and-2's?subject=dsa&approach=optimal-approach

   Desc - 

   Concept of 3 dummy Nodes

   ```cpp
   Node zeroDummy = Node(-1);
   Node oneDummy = Node(-1);
   Node twoDummy = Node(-1);
   
   Node* zero = &zeroDummy;
   Node* one = &oneDummy;
   Node* two = &twoDummy;    
   ```

And, 7 cases using just 6 lines using ternary operator -

```cpp
zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
one->next = twoDummy.next;
two->next = nullptr;

if (zeroDummy.next) return zeroDummy.next;
else if (oneDummy.next) return oneDummy.next;
else return twoDummy.next;
```

8. Delete Node in a LL

https://leetcode.com/problems/delete-node-in-a-linked-list/

Desc -

Trick : copy the value of the next into the node and point the node to the next of next.
The problem encountered was that we can't go to the left of the given node, so we just copy the content of the next node into the current given node and pointing it to the next of next.

9. Remove Nth node from the back of the LL : **concept of slow and fast pointer**

Note that we need to point temp to the node just before the node to be deleted, to do `temp->next  = temp->next->next`.

https://takeuforward.org/plus/dsa/problems/remove-nth-node-from-the-back-of-the-ll?subject=dsa&approach=optimal

Desc - 

Optimal Approach : **slow and fast pointer approach**

Point fast to the head, move it by n places, point slow to the head, we want to reach the node which is (len-n) from the start, move both slow and fast together, as fast moves till the last node, it has moved (len - n) places more, and alongwith it, slow has also moved (len - n) places from the start, pointing to the node we need to delete.

10. Add one to a number represented by the LL

https://takeuforward.org/plus/dsa/problems/add-one-to-a-number-represented-by-ll?subject=dsa&approach=recursive-solution

Desc -
Iterative solution : reverse the LL, add 1 to the head, reverse again.

Recursive solution : return what carry to return 0, or 1.
