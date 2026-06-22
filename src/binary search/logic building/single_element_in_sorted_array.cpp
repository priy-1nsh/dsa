class Solution {
   public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 1, h = n - 2;

        // check separately for index = 0 and index = n - 1 since if mid hits
        // any of them, we wouldn't be able to access mid-1 (for index 0) and
        // mid+1 (for index n-1). edge case (there is no 0th index and 1st index
        // for the single element array)
        if (n == 1) return arr[0];
        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        // start the algorithm
        while (l <= h) {
            int m = (l + h) / 2;
            if (arr[m] != arr[m + 1] && arr[m] != arr[m - 1]) {
                // single element found
                return arr[m];
            }

            if (m % 2 == 0) {
                // m is even : 2 cases (even, odd) OR (odd, even)
                if (arr[m] == arr[m - 1]) {
                    // (odd, even) case : single elt is on the left
                    h = m - 1;
                } else {
                    // arr[m] == arr[m+1]
                    // (even, odd) : single elt is on the right
                    l = m + 1;
                }
            } else {
                // m is odd
                if (arr[m] == arr[m + 1]) {
                    // (odd, even)
                    h = m - 1;
                } else {
                    // (even, odd)
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};