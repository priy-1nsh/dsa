// Recursive approach
class Solution {
   public:
    // dp problrm - climb stairs
    int climbStairs(int n) {
        // recursion way
        if (n <= 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Memoization
class Solution {
   public:
    // memoization : top - down approach from n to the base case
    int f(int ind, vector<int>& dp) {
        if (ind <= 1) return 1;  // only one way to reach from (0->0) and (0->1)
        if (dp[ind] != -1) return dp[ind];

        return dp[ind] = f(ind - 1, dp) + f(ind - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

// Tabulation
class Solution {
   public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Space Optimization
class Solution {
   public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
        int curri;
        for (int i = 2; i <= n; i++) {
            curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};