class Solution {
   public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // square matrix
        // brute force approach : (i, j) -> (j, n-1-i) but with a new matrix :
        // ans[][] optimal approach : transpose the matrix then reverse each
        // array

        // taking the transpose
        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        // reversing each array
        for (int i = 0; i <= n - 1; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};