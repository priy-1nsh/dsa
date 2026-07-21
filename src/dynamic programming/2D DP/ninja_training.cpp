class Solution {
   public:
    int maxPoints(int day, int lastTask, vector<vector<int>>& matrix) {
        if (day == 0) {
            int maxi = INT_MIN;
            for (int i = 0; i < 3; i++) {
                if (i != lastTask) {
                    maxi = max(maxi, matrix[0][i]);
                }
            }
            return maxi;
        }

        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (i != lastTask) {
                maxi = max(maxi, matrix[day][i]);
            }
        }
        return maxi;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        // doing ninja training
        int n = matrix.size();  // number of days
        // we have n X 3 matrix
        int day = n - 1;
        return maxPoints(day, lastTask, matrix);
    }
};