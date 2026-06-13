#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int>& arr, int k) {
    int n = arr.size();
    int lsum = 0, rsum = 0, maxSum = 0;
    // first we find the initial left sum
    for (int i = 0; i < k; i++) {
        lsum += arr[i];
    }
    maxSum = lsum;
    
    // now we calculate the other sums, by moving the window towards the left in the cyclic order
    int rindex = n - 1;
    for (int i = k - 1; i >= 0; i--) {
        // here, k-1 is the starting index since i have to subtract this from the lsum for the first time
        lsum -= arr[i];
        // at the same time, add the rindex-th element of the array to the rsum
        rsum += arr[rindex];
        rindex--;

        // ofcourse update the maxSum by comparing with the lsum+rsum
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}

int main() {
    vector<int> cardScore = {9, 10, 1, 2, 3, 5};
    int k = 5;
    int result = maxPoints(cardScore, k);
    cout << result;
    return 0;;
}