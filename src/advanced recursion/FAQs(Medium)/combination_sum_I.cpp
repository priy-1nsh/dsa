#include <bits/stdc++.h>
using namespace std;

void combinationSum1(int index, vector<int>& arr, int n, vector<int>& temp, vector<vector<int>>& ans, int sum) {
    if (sum == 0) {
        ans.push_back(temp);
        return;
    }
    if (sum < 0) return;
    if (index == n) return;

    // take and remain at the same index
    temp.push_back(arr[indes]);
    combinationSum(index, arr, n, temp, ans, sum-arr[ind]);
    // backtrack
    temp.pop_back();

    // not take and move to the next index
    combinationSum(index+1, arr, n, temp, ans, sum);
}

int main() {
    return 0;
}