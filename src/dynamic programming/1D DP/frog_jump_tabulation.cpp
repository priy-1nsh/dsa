class Solution {
   public:
    int frogJump(vector<int>& arr) {
        // tabulation
        int n = arr.size();
        vector<int> dp(n, -1);  // our answer is total energy required to go
                                // from 0 to n-1 step
        dp[0] = 0;
        dp[1] = abs(arr[1] - arr[0]);
        for (int i = 2; i < n; i++) {
            int fs = dp[i - 1] + abs(arr[i] - arr[i - 1]);
            int ss = dp[i - 2] + abs(arr[i] - arr[i - 2]);
            dp[i] = min(fs, ss);
        }
        return dp[n - 1];
    }
};