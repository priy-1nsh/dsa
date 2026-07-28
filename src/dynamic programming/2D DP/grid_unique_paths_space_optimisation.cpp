// To convert tabulation to space optimisation -
// write the tabulation code and then make changes

// here, we will use the up row as the dp row, current row as the temp row and
// then will make the dp row as the temp row
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0) up = dp[j];
                if (j > 0) left = temp[j - 1];
                temp[j] = left + up;
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};