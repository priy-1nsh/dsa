#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    // find missing number
    int n = nums.size();
    vector<int> hash(n + 1, 0);  // hash will have indexes from 0 to n
    for (int i = 0; i < n; i++) {
        hash[nums[i]] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (hash[i] == 0) return i;
    }
}

int main() {
    vector<int> arr = {0, 2, 3, 1, 4};
    cout << missingNumber(arr);
    return 0;
}