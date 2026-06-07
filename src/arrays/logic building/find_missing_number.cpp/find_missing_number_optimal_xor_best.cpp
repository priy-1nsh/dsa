#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int xor1 = 0;
    int xor2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        xor1 = xor1 ^ i;
        xor2 = xor2 ^ nums[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int main() {
    vector<int> arr = {0, 2, 3, 1, 4};
    cout << missingNumber(arr);
    return 0;
}