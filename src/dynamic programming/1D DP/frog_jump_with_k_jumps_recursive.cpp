class Solution {
   public:
    int f(int ind, vector<int>& arr, int n, int k) {
        if (ind == 0) return 0;  // 0 cost to go from 0 to 0
        // from ind to ind-1, ind-2, etc
        int mmStep = INT_MAX;  // this is the minimum energy cost to go from ind
                               // to 0 and vice versa
        for (int j = 1; j <= k; j++) {
            // k jumps
            int jumpCost = 0;
            if (ind >= j) {
                jumpCost = f(ind - j, arr, n, k) + abs(arr[ind] - arr[ind - j]);
            } else
                break;
            mmStep = min(mmStep, jumpCost);
        }
        return mmStep;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return f(n - 1, heights, n, k);
    }
};
