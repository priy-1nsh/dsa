class Solution {
   private:
    long long totalTime(vector<int>& arr, int mid) {
        long long totalHours = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalHours += (arr[i] + mid - 1) / mid;
        }
        return totalHours;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (totalTime(piles, mid) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high + 1;
    }
};