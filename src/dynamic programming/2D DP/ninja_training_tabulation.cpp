class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        // tabulation code
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // dp[day][next] = max points we can get from day 0 to day = day, when the task we will perform on day = day + 1 is `next`
        // base case
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2])); // if n = 1

        for (int day = 1; day < n; day++) {
            for (int next = 0; next < 4; next++) {
                // find dp[day][next]
                dp[day][next] = 0; // considering no negative points we can get
                for (int task = 0; task < 3; task++) {
                    if (task != next) {
                        dp[day][next] = max(dp[day][next], matrix[day][task] + dp[day-1][task]);
                    }
                }
            }
        }
        return dp[n-1][3]; // return the max points we can gether from day 0 to day = n - 1 when the task performed on the next day (day == n) is 3rd.
    }
};