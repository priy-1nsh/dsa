#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }
// arr[] = {2, 1, 4, 9}
// pick / not pick

// function to find the maximum sum of subsequences with non-adjacent elements
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

// Now, we will break the given arr into two parts
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // edge case - if arr contains only one element
    if (n == 1) {
        printf("%d", arr[0]);
        return 0;
    }

    // break arr into two arrays - temp1 and temp2
    int temp1[n - 1];
    int temp2[n - 1];

    // now, put arr elements into temp1 and temp2
    for (int i = 0; i < n - 1; i++) {
        temp1[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        temp2[i - 1] = arr[i];
    }

    // dp array
    int dp[n - 1];
    for (int i = 0; i < n - 1; i++) {
        dp[i] = -1;
    }

    int ans1 = f(n - 2, temp1, n - 1, dp);

    // reinitialize dp for the second call
    for (int i = 0; i < n - 1; i++) {
        dp[i] = -1;
    }

    int ans2 = f(n - 2, temp2, n - 1, dp);

    int ans = max(ans1, ans2);

    printf("%d", ans);
}