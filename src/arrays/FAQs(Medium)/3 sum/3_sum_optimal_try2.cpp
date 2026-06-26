class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        // target == 0
        int i = 0;  // fixed
        while (i < n) {
            // increment before doing continue
            if (i > 0 && arr[i] == arr[i - 1]) {
                i++;
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                // not j <= k as the same elt can't be taken twice
                int eltj = arr[j];
                int eltk = arr[k];
                int sum = arr[i] + eltj + eltk;
                if (sum == target) {
                    // already in sorted order arr[i], eltj, eltk
                    ans.push_back({arr[i], eltj, eltk});
                    // j++, k--
                    while (j < n && arr[j] == eltj) j++;
                    while (k >= 0 && arr[k] == eltk) k--;
                } else if (sum < target) {
                    // move j++
                    while (j < n && arr[j] == eltj) j++;
                } else {
                    // move k--
                    while (k >= 0 && arr[k] == eltk) k--;
                }
            }
            i++;
        }
        return ans;
    }
};