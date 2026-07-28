class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // space optimisation solution we will write
        // first let's write tabulation code
        int m = grid.size(); // m rows
        int n = grid[0].size(); // n cols
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0; // loops should be self contained and shouldn't depend on this guard totally
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // for loops
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (i > 0) up = dp[i-1][j];
                    if (j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};