#include <bits/stdc++.h>
using namespace std;

// tabulation
int frogJump(int heights[], int n) {
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i >= 2) {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

int main() {
    int n = 5;
    int heights[] = {10, 20, 30, 40, 50};
    cout << frogJump(heights, n) << endl;
    return 0;
}