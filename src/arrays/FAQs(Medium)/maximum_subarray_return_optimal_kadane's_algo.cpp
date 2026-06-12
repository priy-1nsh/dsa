#include <bits/stdc++.h>
using namespace std;

vector<int> maximumSubArray(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    int maxSumTillNow = INT_MIN;
    int currMaxSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] + currMaxSum > currMaxSum) {
            ans.push_back(arr[i]);
        }
        else if (arr[i] > currMaxSum) {
            ans.clear();
            ans.push_back(arr[i]);
        }
        maxSumTillNow = max(maxSumTillNow, currMaxSum);
    }
    return maxSumTillNow;
}

int main() {
    return 0;
}