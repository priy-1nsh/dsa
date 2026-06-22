#include <bits/stdc++.h>
using namespace std;

// recursive implementation
int lowerBound(vector<int>& arr, int low, int high, int ans, int target) {
    if (low > high) return ans;

    int mid = (low + high) / 2;

    if (arr[mid] > target) {
        // ans = mid
        // high = mid - 1
        return lowerBound(arr, low, mid - 1, mid, target);
    }
    // target > arr[mid]
    return lowerBound(arr, mid + 1, high, ans, target);
}

int main() {
    vector<int> arr = {1, 3, 7, 8, 19, 49, 34, 23};
    int target = 8;
    int ans = arr.size();
    cout << lowerBound(arr, 0, ans - 1, ans, target);
    return 0;
}