// to count all the ways, we use the same template of returning 1 when condition
// is satisfied and return 0 when conditon is not satisfied here we apply the
// above recursion technique since we need to explore all possible paths and
// count them
class Solution {
   public:
    int f(int i, int j) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;

        int left = f(i, j - 1);
        int up = f(i - 1, j);

        return up + left;
    }
    int uniquePaths(int m, int n) {
        // recursion : top-down
        // (m-1, n-1) to (0, 0)
        return f(i, j);
    }
};

// TC - O(2^(n*m))
// SC - O(path length) = (n+m)