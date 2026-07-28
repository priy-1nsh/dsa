class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; j++) {
            dp[j] = triangle[n-1][j];
        }

        for (int i = n-2; i >= 0; i--) {
            vector<int> temp(n, 0);
            for (int j = i; j >= 0; j--) {
                temp[j] = min(triangle[i][j] + dp[j],triangle[i][j] + dp[j+1]);
            }
        }
        return dp[0];
    }
};