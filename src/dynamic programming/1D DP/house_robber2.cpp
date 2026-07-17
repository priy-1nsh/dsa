// using the same solution as the house robber 1, just applying it to first 0 to
// n - 2, and then 1 to n -1
class Solution {
   public:
    int houseRobber1(int ind, vector<int>& arr, vector<int>& dp) {
        if (ind == 0) return arr[0];
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];

        return dp[ind] = max(houseRobber1(ind - 2, arr, dp) + arr[ind],
                             houseRobber1(ind - 1, arr, dp) + 0);
    }
    int rob(vector<int>& nums) {
        // hoouse robber 1 code will work applied to nums from 0 to n - 2 and
        // from 1 to n-1
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1(n - 1, -1), dp2(n - 1, -1);
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);  // temp1 doesn't contain index == 0
            if (i != n - 1)
                temp2.push_back(nums[i]);  // temp2 doesn't contain index == n-1
        }
        // if n == 1, both temp1 and temp2 would not contain it and we will have
        // empty arrays
        return max(houseRobber1(n - 2, temp1, dp1),
                   houseRobber1(n - 2, temp2, dp2));
    }
};