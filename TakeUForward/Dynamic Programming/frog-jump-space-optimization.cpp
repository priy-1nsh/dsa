#include <bits/stdc++.h>
using namespace std;

// space optimization
int frogJump(int heights[], int n) {
    // no dp array
    // base case
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i <= n - 1; i++) {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i >= 2) ss = prev2 + abs(heights[i] - heights[i - 2]);

        int curr_i = min(fs, ss);
        prev2 = prev;
        prev = curr_i;
    }
    return prev;
}

int main() {
    int n = 5;
    int heights[] = {10, 20, 30, 40, 50};
    cout << frogJump(heights, n) << endl;
    return 0;
}