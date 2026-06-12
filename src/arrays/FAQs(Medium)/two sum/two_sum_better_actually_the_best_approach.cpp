#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target) {
    unordered_map<int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int remaining = target - arr[i];
        if (mpp.find(remaining) != mpp.end()) {
            // found
            return {i, mpp[remaining]};
        }
        mpp[arr[i]] = i;
    }
}

int main() {
    return 0;
}