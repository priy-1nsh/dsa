#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int>& arr) {
    // kadane's algorithm
    int maxSumTillNow = INT_MIN;
    int currMaxSum = 0;
    for (int i = 0; i < n; i++) {
        currMaxSum = max(arr[i], currMaxSum + arr[i]);
        maxSumTillNow = max(maxSumTillNow, currMaxSum);
    }
    return maxSumTillNow;
}

int main() {
    return 0;
}