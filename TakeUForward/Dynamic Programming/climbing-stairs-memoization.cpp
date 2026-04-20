#include <bits/stdc++.h>
using namespace std;

// Steps to convert recursion to memoization
// 1. declare - declare a dp array or ds of size n+1 initialized with -1
// 2. return - if encounter a subproblem which has already been solved, return
// the value of that subproblem
// 3. store - store the value of the subproblem if it has not been solved

int climbingStairs(int ind, vector<int>& dp) {
    if (ind == 1) return 1;
    if (ind == 0) return 1;

    // return
    if (dp[ind] != -1) return dp[ind];

    // store
    // not yet solved
    dp[ind] = climbingStairs(ind - 1, dp) + climbingStairs(ind - 2, dp);
    return dp[ind];
}

int main() {
    int ind = 5;
    vector<int> dp(ind + 1, -1);
    cout << climbingStairs(ind, dp);
    return 0;
}

// TC -> O(N) due to pre-storing
// SC -> O(N) + O(N) [recursive stack space + dp vector/array]