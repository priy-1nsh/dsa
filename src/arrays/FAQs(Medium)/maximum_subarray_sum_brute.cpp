#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    // check all the subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            // sum from ith index to the jth index
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            // found the sum in `sum`
            if (sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    return 0;
}