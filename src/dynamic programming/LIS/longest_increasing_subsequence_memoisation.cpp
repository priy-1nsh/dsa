class Solution {
   public:
    int f(int ind, int prev, vector<int>& nums, int n,
          vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = 0 + f(ind + 1, prev, nums, n);
        int take = INT_MIN;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, nums, n);
        }
        return dp[ind][prev + 1] = max(take, notTake);
    }
    int LIS(vector<int>& nums) {
        // recursion and memoisation
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // ind can be 0 to n-1 and prev can be -1 to n-1, so we increase prev to
        // 0 to n+1
        return f(0, -1, nums, nums.size(), dp);
    }
};