#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// longest increasing subsequence - recursion
int f(int ind, int prevInd, int n, int arr[], int dp[][n + 1]) {
    // base case
    if (ind == n) return 0;
    if (dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

    // do all the stuffs
    // not take
    int lis = 0 + f(ind + 1, prevInd, n, arr, dp);
    // take
    if (prevInd == -1 || arr[ind] > arr[prevInd]) {
        lis = max(lis, 1 + f(ind + 1, ind, n, arr, dp));
    }

    return dp[ind][prevInd + 1] = lis;
}

int main() {
    int n;
    scanf("%d", &n);

    // dp[N][N+1]
    int dp[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            dp[i][j] = -1;
        }
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = f(0, -1, n, arr, dp);

    printf("%d", ans);

    return 0;
}