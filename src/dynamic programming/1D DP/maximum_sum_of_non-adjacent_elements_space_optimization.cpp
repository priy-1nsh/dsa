class Solution {
   public:
    int rob(vector<int> nums) {
        int prev = nums[0];  // dp[0];
        int prev2 = 0;       // dp[neg]
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i >= 2) take += prev2;
            int notTake = 0 + prev;
            int curri = max(take, notTake);

            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};