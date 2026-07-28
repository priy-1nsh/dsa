class Solution {
public:
    int maxPoints(int ind, int last, vector<vector<int>>& matrix) {
        // base case
        if (ind == 0) {
            // day 0
            int maxi = INT_MIN; // in case there are negative tasks
            for (int i = 0; i < (int)matrix.size(); i++) {
                maxi = max(maxi, matrix[0][i]);
            }
            return maxi;
        }

        int maxi = INT_MIN;
        // now for the day == ind
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                // i is not same as the last performed task which is actually the task performed on the next day
                int points = matrix[ind][i] + maxPoints(ind-1, i, matrix);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        // reattempt to grasp the whole 2d dp thing
        int n = matrix.size();
        return maxPoints(n-1, 3, matrix);
        // passing 3 as the last task since we can choose from any task on the day n-1 since it has no previous day(which actually means that there is no next day)
    }
};