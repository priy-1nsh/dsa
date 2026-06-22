#include <bits/stdc++.h>
using namespace std;

// check if here exists a subsequence with sum == k
bool checkSubsequence(int index, vector<int>& arr, int n, int sum) {

    if (sum == 0) return true; // not including && index == n for optimisation
    if (sum < 0 || index == n) return false; // sum < 0 to elimiate further recursion calls if we ever encounter the sum < 0 , and index==n is a necessary condition to stop further recursion calls.

    bool take = checkSubsequence(index+1, arr, n, sum - arr[index]);
    // minor optimisation : if (take) return true;

    bool notTake = checkSubsequence(index+1, arr, n, sum);

    return take || notTake;
}

int main() {
    return 0;
}