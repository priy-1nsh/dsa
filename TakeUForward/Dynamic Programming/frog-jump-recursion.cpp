#include <bits/stdc++.h>
using namespace std;
// min energy
int f(int ind, vector<int> heights) {
    if (ind == 0) return 0;
    int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind >= 2) {
        right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }

    return min(left, right);
}

int frogJump(vector<int> heights, int n) { return f(n - 1, heights); }

int main() {
    int n = 4;
    vector<int> heights = {10, 20, 30, 40};
    cout << frogJump(heights, n);
    return 0;
}