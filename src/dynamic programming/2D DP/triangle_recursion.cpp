class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int n) {
        if (i == n-1) return triangle[n-1][j];

        int down = triangle[i][j] + f(i+1, j, triangle, n);
        int downRight = triangle[i][j] + f(i+1, j+1, triangle, n);

        return min(down, downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // move from row 0 to row n-1
        int row = 0, col = 0;
        return f(row, col, triangle, triangle.size());
    }
};