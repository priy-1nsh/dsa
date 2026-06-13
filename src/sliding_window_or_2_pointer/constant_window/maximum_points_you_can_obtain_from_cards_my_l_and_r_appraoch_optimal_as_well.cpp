#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;
    int maxSum = 0;
    // greedy approach won't work
    // so we will try out all the possibilities
    for (int i = 0; i < k; i++) {
        sum += arr[i]; // initial sum
    }
    maxSum = sum;
    int l = 0;
    int r = k - 1;
    
    // k times
    for (int i = 0; i < k; i++) {
        l--;
        if (l < 0) {
            l = n - 1;
        }
        sum = sum + arr[l];
        sum = sum - arr[r];
        r--;

        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    vector<int> cardScore = {9, 10, 1, 2, 3, 5};
    int k = 5;
    int result = maxPoints(cardScore, k);
    cout << result;
    return 0;
}