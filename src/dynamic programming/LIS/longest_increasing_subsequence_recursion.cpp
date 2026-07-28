class Solution {
   public:
    int f(int ind, int prev, int n, vector<int>& nums) {
        // base case
        if (ind == n)
            return 0;  // run out of all the elements in the subsequence

        int len = 0 + f(ind + 1, prev, n, nums);  // not take case

        if (prev == -1 || nums[ind] > nums[prev]) {
            // can take
            len = max(len, 1 + f(ind + 1, ind, n, nums));  // take case
        }

        return len;
    }
    int LIS(vector<int>& nums) {
        int n = nums.size();
        return f(0, -1, n, nums);
    }
};