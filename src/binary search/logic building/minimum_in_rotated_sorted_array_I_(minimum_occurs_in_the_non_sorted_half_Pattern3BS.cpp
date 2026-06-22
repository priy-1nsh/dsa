#include <bits/stdc++.h>
using namespace std;

// find minimum in the rotated sorted array - I (unique elements)
int findMinimumSortedArrayI(vector<int>& arr, int n) {
    int l = 0, h = n - 1;
    int mini = INT_MAX;
    while (l <= h) {
        int m = (l + h) / 2;
        // optimisation : both halves are sorted
        if (arr[l] <= arr[h]) {
            mini = min(mini, arr[l]);
            continue;
        }

        // left half is sorted
        if (arr[l] <= arr[m]) {
            // arr[l] is the smallest element in this left sorted half
            if (arr[l] < mini) mini = arr[l];
            // whether or not we update mini with arr[l] based on if it is
            // smaller than the mini, we still need to eliminate the sorted
            // half, as the minimum definitely lies in the non-sorted half
            l = m + 1;
        } else if (arr[m] <= arr[h]) {
            // right half is sorted
            if (arr[m] < mini) mini = arr[m];
            h = m - 1;
        }
    }
    return mini;
}

int main() { return 0; }