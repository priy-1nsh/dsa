class Solution {
   public:
    int rob(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int neg = 0;
        for (int i = 1; i <= n - 1; i++) {
            int take = nums[i];  // + dp[i-2]
            if (i >= 2) take += dp[i - 2];
            int notTake = 0 + dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }
};