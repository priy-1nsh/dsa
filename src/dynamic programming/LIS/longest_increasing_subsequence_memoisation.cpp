class Solution {
   public:
    int f(int ind, int prev, int n, vector<int>& nums,
          vector<vector<int>>& dp) {
        // base case
        if (ind == n)
            return 0;  // run out of all the elements in the subsequence

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int len = 0 + f(ind + 1, prev, n, nums, dp);  // not take case

        if (prev == -1 || nums[ind] > nums[prev]) {
            // can take
            len = max(len, 1 + f(ind + 1, ind, n, nums, dp));  // take case
        }

        return dp[ind][prev + 1] = len;
    }
    int LIS(vector<int>& nums) {
        int n = nums.size();
        // dp array
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, nums, dp);
    }
};