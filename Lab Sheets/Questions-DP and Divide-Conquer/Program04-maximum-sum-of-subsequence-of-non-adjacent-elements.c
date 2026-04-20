#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }
// arr[] = {2, 1, 4, 9}
// pick / not pick

int f(int ind, int arr[], int n, int dp[n]) {
    // base case
    if (ind == 0) return arr[0];
    if (ind < 0) return 0;
    // memeoisation
    if (dp[ind] != -1) return dp[ind];

    // do all the stuffs
    int pick = arr[ind] + f(ind - 2, arr, n, dp);
    int notPick = 0 + f(ind - 1, arr, n, dp);

    return dp[ind] = max(pick, notPick);
}

int main() {
    int n;
    scanf("%d", &n);

    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans =
        f(n - 1, arr,
          n, dp);  // max sum of subsequence in the array from index = [0 -> n-1]

    printf("%d", ans);

    return 0;
}