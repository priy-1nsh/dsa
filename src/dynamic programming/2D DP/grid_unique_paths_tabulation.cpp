// To convert recursion to tabulation -
// 1. base case (1.5 step - make sure the for loop doesn't clobber the base
// case.) - if it does, make sure to explicity skip them, like by doing continue
// 2. for loop
// 3. copy the recurrence

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] == 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
        return dp[m - 1][n - 1];
    }
};