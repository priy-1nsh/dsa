#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    // most optimal approach - two pointer
    // first point j to the first 0 element, the element which is 0
    int j = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for (int i = j + 1; i < nums.size(); i++) {
        if (nums[i] != 0) {
            // i is pointing to a non-zero element , although j will always
            // point to the 0
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 4, 0, 5, 2};
    moveZeroes(arr);
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}

// TC - O(N)
// SC - O(1) extra space