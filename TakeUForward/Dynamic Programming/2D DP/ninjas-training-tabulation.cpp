#include <bits/stdc++.h>
using namespace std;

// tabulation solution : 2 parameter DP
// 1. declare dp[n][4] = {-1}
// 2. base case : dp[0][0], dp[0][1], dp[0][2], dp[0][3]
// 3. for loop : 1 to n-1
// 4. return dp[n-1][lastTask]

// dp[][] = dp[day][lastTask/task performed on previous day]

int f(vector<vector<int>>& points, int n) {
    // n = no. of days

    // declare the dp array - 2 parameters
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(
        points[0][0],
        max(points[0][1],
            points[0][2]));  // when there is no prev task - no prev day -day 1

    // now, we do for loop
    for (int day = 1; day <= n - 1; day++) {
        for (int lastTask = 0; lastTask <= 3; lastTask++) {
            int maxi = INT_MIN;
            for (int task = 0; task <= 2; task++) {
                if (task != lastTask) {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][lastTask] = maxi;
        }
    }
    return dp[n - 1][3];
}

int main() {
    int n = 5;
    vector<vector<int>> points = {
        {10, 20, 30}, {40, 50, 10}, {20, 30, 50}, {20, 40, 50}, {100, 20, 80}};
    cout << f(points, n);
    return 0;
}