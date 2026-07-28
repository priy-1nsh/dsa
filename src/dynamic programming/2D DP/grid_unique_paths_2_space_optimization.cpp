class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // space optimisation solution we will write
        // first let's write tabulation code
        int m = grid.size(); // m rows
        int n = grid[0].size(); // n cols
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0; // loops should be self contained and shouldn't depend on this guard totally
        vector<int> dp(n, 0);

        // for loops
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) temp[j] = 0;
                else if (i == 0 && j == 0) temp[j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (i > 0) up = dp[j];
                    if (j > 0) left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};