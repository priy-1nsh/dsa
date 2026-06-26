class Solution {
   private:
    bool checkBouquetFeasibility(vector<int>& arr, int k, int m, int day) {
        // we need to check if on day - day, do we have atleast m bouquets with
        // k roses in each of them
		int count = 0;
		int bouquets = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] <= day) count++;
			else count = 0;

			if (count >= k) bouquets++;
		}
		if (bouquets >= m) return true;
        return false;
    }

   public:
    int roseGarden(int n, vector<int> nums, int k, int m) {
		int l = *min_element(nums.begin(), nums.end());
		int n = nums.size();
		int h = *max_element(nums.begin(), nums.end());
		int ans = INT_MAX;
		while (l <= h) {
			int mid = (l + h) / 2;
			if (checkBouquetFeasibility(nums, k, m, mid)) {
				h = mid - 1;
				ans = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return ans;
	}
};