#include <bits/stdc++.h>
using namespace std;

// Ques. Count the number of binary subArrays with sum == k

// Idea : Exactly(k) = atMost(K) - atMost(k-1) : basic set theory and for atMost, use pattern 2 template

int atMostK(vector<int>& arr, int k) {
    // just an edge case : if k = negative then there will definitely be no subArrays in a Binary Array whivh will add up to a negative number.
    if (k < 0) return 0; // 0 such subArrays

    // given the binary array arr, find the number of subArrays with sum <= k
    int n = arr.size();
    int res = 0; // result variable
    int sum = 0;
    int l = 0, r = 0;
    
    while (r < n) {
        sum += arr[r];

        // if invalid subArray, shrink till it gets valid
        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        // if valid, add the number of valid subArrays upto index r in the result res
        if (sum <= k) {
            res += r - l + 1;
        }
        r++;
    }
    return res;
    
}

int main() {
    vector<int> A = {1, 0, 1, 0, 1};
    int K = 2;
    int result = atMostK(A, K) - atMostK(A, K - 1);
    cout << result;
    return 0;
}