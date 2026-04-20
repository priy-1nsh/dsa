#include <bits/stdc++.h>
using namespace std;

// points 2D array will be given to us
int f(int day, int lastTask, vector<vector<int>>& points,
      vector<vector<int>>& dp) {
    // base case
    if (day == 0) {
        // if the day is 0
        // then we cannot perform the last task and the task that we must
        // perform must yield the max number of points
        int maxi = INT_MIN;
        for (int task = 0; task <= 2; task++) {
            if (task != lastTask) {
                // perform it
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if (dp[day][lastTask] != -1) return dp[day][lastTask];

    int maxi = INT_MIN;
    // perform for the current day - not the zero day
    for (int task = 0; task <= 2; task++) {
        if (task != lastTask) {
            int thisTaskPoints =
                points[day][task] + f(day - 1, task, points, dp);
            // top-down approach : going to day - 1
            maxi = max(maxi, thisTaskPoints);
        }
    }
    return dp[day][lastTask] = maxi;
}

int main() {
    vector<vector<int>> points = {{70, 40, 10}, {180, 20, 5}, {200, 60, 30}};
    int n = 3;  // number of days
    vector<vector<int>> dp(
        n, vector<int>(4, -1));  // makes a dp array of size n * 4
    cout << f(n - 1, 3, points, dp) << endl;
    return 0;
}