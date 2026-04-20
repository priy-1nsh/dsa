#include <bits/stdc++.h>
using namespace std;

// This is DP so think about the problem in terms of the index
// Recursion -> Tabulation (No recursion) : 4 steps
// 1. declare - declare an array of size n+1 initialized with -1
// 2. set base case - set the base cases in the array itself
// 3. loop - use a for loop for the computation of the solution for larger
// values, that iterates
//    from the smallest subproblem to n.
// 4. return last element

int climbingStairs(int ind) {
    vector<int> dp(ind + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= ind; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[ind];
}

int main() {
    int n = 5;
    cout << climbingStairs(n);
    return 0;
}

// TC -> O(N)
// SC -> O(N) due to the dp array (No recursion)