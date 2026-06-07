#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> nums) {
    // missing number
    int n = nums.size();
    for (int i = 0; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            // check each i in the array
            if (i == nums[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
}

int main() {
    vector<int> arr = {0, 2, 3, 1, 4};
    cout << missingNumber(arr);
    return 0;
}