class Solution {
   public:
    int frogJump(vector<int>& arr, int k) {
        // tabulation way
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;  // base case
        for (int ind = 1; ind <= n - 1; ind++) {
            // for each index
            int mmStep = INT_MAX;
            for (int j = 1; j <= k; j++) {
                // find the minimum energy jump out of all the jumps that can be taken from ind to ind-1, ind-2, ind-3, ... ind-k.
                int jumpEnergy = 0;
                if (ind >= j) {
                    // that is, can jump from ind to ind-j
                    jumpEnergy = dp[ind - j] + abs(arr[ind] - arr[ind - j]);
                } else
                    break;
                mmStep = min(mmStep, jumpEnergy); // this is the minimum energy jump from ind to ind-j for all available j = [1, k]
            }
            dp[ind] = mmStep;
        }
        return dp[n - 1];
    }
};
