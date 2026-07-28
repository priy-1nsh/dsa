#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        // base case
        // out of bounds case
        if (j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c - 1)
            return -1e8;  // we need maximum

        // condn satisfied base case
        if (i == r - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // recurrence
        int maxi = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int newj1 = j1 + dj1;
                int newj2 = j2 + dj2;

                int value = 0;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += f(i + 1, newj1, newj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    // tabulation code using the above recurrence
    int maxChocolates(vector<vector<int>>& grid) {
        int m = grid.size();     // number of rows
        int n = grid[0].size();  // number of columns

        // 3d dp array dp[m][n][n] = dp[i][j1][j2]
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, 0)));

        // base case
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                if (j1 == j2)
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                else
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        // for loop for all the dp states
        for (int i = m - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    // copy the recurrence
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int newj1 = j1 + dj1;
                            int newj2 = j2 + dj2;

                            // skip invalid moves
                            int value = 0;
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if (newj1 >= 0 && newj1 < n && newj2 >= 0 &&
                                newj2 < n)
                                value += dp[i + 1][newj1][newj2];
                            else
                                value = -1e8;  // out of bound must be discarded
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};