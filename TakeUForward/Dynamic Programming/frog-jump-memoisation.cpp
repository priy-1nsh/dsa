#include <bits/stdc++.h>
using namespace std;

// recursion to memoisation
int frogJump(int ind, int heights[], vector<int>& dp) {
    // base case
    if (ind == 0) return 0;
    // return
    if (dp[ind] != -1) return dp[ind];

    int left =
        frogJump(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind >= 2) {
        right = frogJump(ind - 2, heights, dp) +
                abs(heights[ind] - heights[ind - 2]);
    }
    return dp[ind] = min(left, right);
}

int main() {
    int n = 4;
    int heights[] = {10, 20, 30, 40};
    vector<int> dp(n, -1);
    cout << frogJump(n - 1, heights, dp)
         << endl;  // we are finding the min energy to reach 0 to n-1
    return 0;
}