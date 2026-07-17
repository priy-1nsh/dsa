class Solution {
   public:
    int f(int ind, vector<int>& arr, int n, int k, vector<int>& dp) {
        if (ind == 0) return 0;  // 0 cost to go from 0 to 0
        if (dp[ind] != -1) return dp[ind];
        // from ind to ind-1, ind-2, etc
        int mmStep = INT_MAX;  // this is the minimum energy cost to go from ind
                               // to 0 and vice versa
        for (int j = 1; j <= k; j++) {
            // k jumps
            int jumpCost = 0;
            if (ind >= j) {
                jumpCost =
                    f(ind - j, arr, n, k, dp) +
                    abs(arr[ind] - arr[ind - j]);  // energy difference is
                                                   // arr[ind] - arr[ind-j]
            } else
                break;
            mmStep = min(mmStep, jumpCost);
        }
        return dp[ind] = mmStep;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return f(n - 1, heights, n, k, dp);
    }
};
