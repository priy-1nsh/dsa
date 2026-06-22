class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        // let's find the peak element
        int n = arr.size();
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n-1] > arr[n-2]) return n-1;

        int l = 1, h = n - 1;
        while (l <= h) {
            int m = (l+h) / 2;
            if (arr[m] > arr[m-1] && arr[m] > arr[m+1]) return m;
            else if (arr[m] > arr[m-1]) {
                // peak is on right
                l = m + 1;
            }
            else {
                // handling multiple peaks : m pointing to the valley
                // peak is on left
                h = m - 1;
            }
        }
        return -1;
    }
};