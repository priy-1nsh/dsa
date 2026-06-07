#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count++;
            continue;
        }
        nums[i - count] = nums[i];
    }
    for (int i = n - count; i < n; i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> vec = {0, 1, 4, 0, 5, 2};
    moveZeros(vec);
    for (auto it : vec) {
        cout << it << " ";
    }
    return 0;
}

// TC - O(N) + O(noOfZeroes)