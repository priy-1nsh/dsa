<p>Read Notes - 
3 steps to make a recurrence.
3 steps to convert recurrence into memoization
2 steps to convert recursion into tabulation
and if dp[i] depends only on dp[i-1] and dp[i-2] or at make something like dp[i-k] where k is fixed, then we can convert tabulation into space optimization as well.</p>

> Go to leetcode and look at your submissions since they are the best submissions.

# Patters and Questions

1. Climbing Stairs and frog Jump

https://takeuforward.org/plus/dsa/problems/climbing-stairs?subject=dsa&approach=optimal

DESC - Read Notes

2. Frog Jump with K Jumps

https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances?subject=dsa&approach=optimal

DESC - Very Important pattern - how to write recursion with a for loop for a fixed k with conditions

3. Maximum Sum of non-adjacent elements / House Robber 1

https://takeuforward.org/plus/dsa/problems/maximum-sum-of-non-adjacent-elements?subject=dsa&approach=optimal

Leetcode - go to leetcode to look at your submitted code.

DESC - base case - pick the element at ind == 0 to maximise the loot for the robber. and for ind < 0, return 0.

4. House Robber 2 - circular array

https://takeuforward.org/plus/dsa/problems/house-robber?subject=dsa&approach=optimal

DESC - Apply house robber 1 on two arrays temp1 and temp2 which are nothing but nums array from index 0 to n-2 and from index 1 to n-1.

5. House Robber 3

https://leetcode.com/problems/house-robber-iii/editorial/

DESC - Read the notes for the recursion approach and memo approach using the unordered map <TreeNode*, int>.

Learn the new recursion patern - **return a vector of states for each node**.
