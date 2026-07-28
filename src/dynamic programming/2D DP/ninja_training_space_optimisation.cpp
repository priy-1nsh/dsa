// space optimisation
int ninjaTraining(vector<vector<int>>& points) {
    // base case
    vector<int> prev(
        4, 0);  // stores points for the ith day for all the 4 cases - when the
                // task performed on the next day is 0, 1 or 2

    int n = points.size();

    // base case
    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][0], matrix[0][1]);
    prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));  // if n prev

    // run the for loop and find the next vector for the next day while using
    // the prev for the prev day
    for (int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++) {
            // find dp[day][next]
            curr[last] = 0;
            // considering no negative points we can get
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    curr[last] =
                        max(curr[last], matrix[day][task] + prev[task]);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}

// TC - O(N*4*3)
// TC - O(4)