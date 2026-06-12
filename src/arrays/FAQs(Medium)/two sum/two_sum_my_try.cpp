#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target) {
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        int remaining = target - arr[i];
        for (int j = i+1; j<n; j++) {
            if (arr[j] == remaining) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}