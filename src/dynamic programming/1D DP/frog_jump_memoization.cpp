class Solution {
public:
    int f(int ind, vector<int>& arr, int n, vector<int>& dp) {
        // if (ind == 1) return f(ind-1) + abs(arr[i] - arr[i-1]);
        if (ind == 0) {
            return 0; // 0 cost of energy to go from 0 to 0
        }
        if (dp[ind] != -1) return dp[ind];
        int left = f(ind-1, arr, n, dp) + abs(arr[ind] - arr[ind-1]);
        int right = INT_MAX;
        if (ind >= 2) {
            right = f(ind-2, arr, n, dp) + abs(arr[ind] - arr[ind-2]);
        }
        return dp[ind] = min(left, right);
    }
    int frogJump(vector<int>& heights) {
        // recursive way
        // we need to find f(n)
        vector<int> dp(n, -1);
        return f(n-1, heights, heights.size(), dp);
    }
};