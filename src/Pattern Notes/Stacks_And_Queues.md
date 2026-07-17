> Whenever you see that you want to access the previous / last-seen element, you use stack

1. Stack using Queue - need one queue since stack has only one end

https://leetcode.com/problems/implement-stack-using-queues/

Just need to use one queue, push into queue, reverse the queue for size-1 element, it keeps the front element as the top

2. Queue using Stacks - need two stacks since queue has two ends

https://leetcode.com/problems/implement-queue-using-stacks/description/

Can either make push expensive - O(2N)

Or can make top and pop expensive - both O(N) 

Look at Notes

3. Valid Parenthese - Easy

https://leetcode.com/problems/valid-parentheses/description/

Good Easy Question on Stack. Every opening must have closing, every closing must have opening, and must be in order. Draw many samples and you will crack it.

4. Next Greater Element - 1

https://takeuforward.org/plus/dsa/problems/next-greater-element?subject=dsa&approach=optimal

Use the monotonic stack concept, move from right to left since we need to keep the track of only the next greater element for each element to the right, so sitting at an element we need to know the elements to the right of it.

5. Next Greater Element - 2

https://takeuforward.org/plus/dsa/problems/next-greater-element---2?subject=dsa&approach=optimal

Brute - **concept of hypothetical circular array** : j = (i+1) to j = (i + n - 1), index = j % n in the real array.

Optimal - Concept of Hypothetical circular array + monotonic stack - basically boils down to two times array traversals from right to left and using the same monotonic stack.

6. Sum of all subarray minimums (Super HARD MONOTONIC STACK QUESTION)

https://takeuforward.org/plus/dsa/problems/sum-of-subarray-minimums?subject=dsa&approach=optimal&tab=editorial

DESC - make sure you remember that here we are finding nse and pse, then using them, we find no of left sub arrays and no of right subarrays and then we use counting principle, left * right for finding the total number of subarrays for a particular element, and ALSO VERY IMPORTANT - remember that nse here is nse , but pse is actually previous smaller or equal element, and also we stores indexes in them.

> Note - they will ask this question if they don't wanna take you, but you prove them wrong !

7. Sum of all subarray ranges (Very Hard - based on sum of subarrays minimum and subarray maximum)

https://takeuforward.org/plus/dsa/problems/sum-of-subarray-ranges?subject=dsa&approach=optimal&tab=editorial

DESC - Super Hard , must know nse, psee and nge, pgee and using nse, psee, we find the sum of subarray minimums, and using nge, pgee, we find the sum of subarray maximums. THEN, we subtract sum of subarray minimums from sum of subarray maximums.

8. 
