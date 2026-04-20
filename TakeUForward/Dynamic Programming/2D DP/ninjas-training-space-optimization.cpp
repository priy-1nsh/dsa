#include <bits/stdc++.h>
using namespace std;

// space optmization
int f(int n, vector<vector<int>>& points) {
    vector<int> prev(4, 0);
    // prev[i] = points we get on the previous day if the task performed on the
    // day which is still previous to it is i
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day <= n - 1; day++) {
        vector<int> curr(4, 0);
        for (int lastTask = 0; lastTask <= 3; lastTask++) {
            int maxi = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != lastTask) {
                    int point =
                        points[day][task] + prev[task];  // prev[task] signifies
                    // that now, this task is the prevTask for the previous day
                    maxi = max(maxi, point);
                }
            }
            curr[lastTask] = maxi;
        }
        prev = curr;
    }

    return prev[3];
}

int main() {
    int n = 5;
    vector<vector<int>> points = {
        {10, 20, 30}, {40, 50, 10}, {20, 30, 50}, {20, 40, 50}, {100, 20, 80}};
    cout << f(n, points);
    return 0;
}