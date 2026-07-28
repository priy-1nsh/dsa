// to count all the ways, we use the same template of returning 1 when condition
// is satisfied and return 0 when conditon is not satisfied here we apply the
// above recursion technique since we need to explore all possible paths and
// count them
class Solution {
   public:
    int f(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        // 2.
        if (dp[i][j] != -1) return dp[i][j];

        int left = f(i, j - 1);
        int up = f(i - 1, j);

        // 3.
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        // recursion : top-down
        // (m-1, n-1) to (0, 0)

        // 1. declare a dp[m][n]
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(i, j, dp);
    }
};

// TC - O(m * n) = number of states
// SC - O(m * n) + O(m + n) = dp array size + path lenght or the height of the
// recursion tree