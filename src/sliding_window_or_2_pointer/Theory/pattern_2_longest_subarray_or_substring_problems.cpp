#include <bits/stdc++.h>
using namespace std;

// Ques. Longest Subarray/Substring with sum <= k
int maxLengthSubArray(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxLength = 0;

    // brute approach - expanding the window in every iteration and shrinking the window only when the sum becomes invalid : sliding non-constant window appraoach, better than checking for all the subarrays
    while (r < n) {
        sum += arr[r];
        // increased the sum

        // check if the new sum is invalid or not, if invalid, shrink the window size
        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        // if the new sum is valid, update the maxLength with the current window lenght by comparing with the previous maxLength
        if (sum <= k) {
            maxLength = max(maxLength, r - l + 1);
        }

        // expand the window everytime since we want the longest subArray
        r++;
    }
    return maxLength;
}

int main() {
    vector<int> arr = {2, 5, 1, 7, 10}; // Example array
    int K = 14; // Example value of K

    // Find and print the length of the longest subarray with sum <= K
    int result = maxLengthSubArray(arr, K);
    cout << "The longest subarray length with sum <= " << K << " is: " << result << endl;

    return 0;
}

// TC :- O(N + N) since both l and r can visit each element of the array once hypotheically
// SC :- In this question, it is O(1)