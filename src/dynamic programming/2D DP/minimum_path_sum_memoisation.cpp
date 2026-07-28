class Solution {
   public:
    int f(int i, int j, vector<vector<int>>& grid) {
        if (i == 0 && j == 0) return grid[0][0];

        int up = INT_MAX, left = INT_MAX;
        if (i > 0) up = grid[i][j] + f(i - 1, j, grid);
        if (j > 0) left = grid[i][j] + f(i, j - 1, grid);
        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return f(m - 1, n - 1, grid);
    }
};