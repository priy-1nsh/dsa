class Solution {
public:
    int maxPoints(int ind, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // base case
        if (ind == 0) {
            // day 0
            int maxi = INT_MIN; // in case there are negative tasks
            for (int i = 0; i < (int)matrix.size(); i++) {
                maxi = max(maxi, matrix[0][i]);
            }
            return maxi;
        }
        if (dp[ind][last] != -1) return dp[ind][last];

        int maxi = INT_MIN;
        // now for the day == ind
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                // i is not same as the last performed task which is actually the task performed on the next day
                int points = matrix[ind][i] + maxPoints(ind-1, i, matrix, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[ind][last] = maxi;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        // reattempt to grasp the whole 2d dp thing
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return maxPoints(n-1, 3, matrix, dp);
        // passing 3 as the last task since we can choose from any task on the day n-1 since it has no previous day(which actually means that there is no next day)
    }
};