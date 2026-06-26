class Solution {
private:
    bool possible(vector<int>& arr, int n, int k, int mid) {
        int current = arr[0];
        // greedy approach
        int countPlaced = 1;
        for (int i = 0; i < n; i++) {
            int distance = arr[i] - current;
            if (distance >= mid) {
                // can be placed : so place the cow
                countPlaced++;
                current = arr[i];
            }
        }
        if (countPlaced >= k) return true;
        return false;
    }
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 1, h = (*max_element(nums.begin(), nums.end()) - (*min_element(nums.begin(), nums.end())));
        while (l <= h) {
            int mid = (l + h) / 2;
            if (possible(nums, nums.size(), k, mid)) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return h;
    }
};