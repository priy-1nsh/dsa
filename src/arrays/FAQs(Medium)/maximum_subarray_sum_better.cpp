#include <bits/stdc++.h>
using namespace std;

int maximumSubArraySum(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    return 0;
}