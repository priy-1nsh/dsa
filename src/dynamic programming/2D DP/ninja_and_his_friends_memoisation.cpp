#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        // base case
        // out of bounds case
        if (j1 < 0 || j1 > c-1 || j2 < 0 || j2 > c-1) return -1e8; // we need maximum

        // condn satisfied base case
        if (i == r-1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int newj1 = j1 + dj1;
                int newj2 = j2 + dj2;

                int value = 0;
                if (j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                value += f(i+1, newj1, newj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
        
    }
    int maxChocolates(vector<vector<int>>& grid) {
        int m = grid.size(); // number of rows
        int n = grid[0].size(); // number of columns

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return f(0, 0, n-1, m, n, grid, dp);
    }
};