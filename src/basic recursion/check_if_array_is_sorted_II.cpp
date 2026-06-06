#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool isSort(vector<int>& nums, int i) {
        // base case
        if (i > nums.size() - 1) return true;

        // job
        if (nums[i - 1] > nums[i]) return false;

        return isSort(nums, i + 1);
    }

   public:
    bool isSorted(vector<int>& nums) {
        // your code goes here
        return isSort(nums, 1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 10, 12, 17};
    Solution sol;
    cout << sol.isSorted(nums);
    return 0;
}