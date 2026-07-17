class Solution {
   public:
    int frogJump(vector<int> arr) {
        int n = arr.size();
        int prev2 = 0;  // cost of 0 to 0
        int prev = 0;   // cost of 0 to 1
        int curri = 0;
        for (int i = 1; i < n; i++) {
            int fs = prev + abs(arr[i] - arr[i - 1]);
            int ss = INT_MAX;
            if (i > 1) ss = prev2 + abs(arr[i] - arr[i - 2]);
            curri = min(fs, ss);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};