#include <bits/stdc++.h>
using namespace std;

// floor of x is the largest element smaller than or equal to x
int getFloor(vector<int>& arr, int low, int high, int ans, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] <= target) {
        // ans = mid
        // low = mid + 1
        return getFloor(arr, mid + 1, high, mid, target);
    }
    return getFloor(arr, low, mid - 1, ans, target);
}

// ceil of x is the smallest element greater than or equal to x
int getCeil(vector<int>& arr, int low, int high, int ans, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] >= target) {
        // ans = mid
        // smallest element : high = mid - 1;
        return getCeil(arr, low, mid - 1, mid, target);
    }
    // arr[mid] < target
    return getCeil(arr, mid + 1, high, ans, target);
}

int main() {
    // ans = -1 passed as the initial value of the ans variable
    int ans = -1;
    return 0;
}