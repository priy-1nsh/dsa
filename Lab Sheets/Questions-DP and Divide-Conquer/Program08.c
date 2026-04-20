#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int lisEnd(int ind, int n, int arr[], int dp[]) {
    if (dp[ind] != -1) return dp[ind];

    int maxLen = 1;  // include itself

    for (int j = 0; j < ind; j++) {
        if (arr[j] < arr[ind]) {
            int len = 1 + lisEnd(j, n, arr, dp);
            if (len > maxLen) maxLen = len;
        }
    }

    return dp[ind] = maxLen;
}

int ldsStart(int ind, int n, int arr[], int dp[]) {
    if (dp[ind] != -1) return dp[ind];

    int maxLen = 1;

    for (int j = ind + 1; j < n; j++) {
        if (arr[j] < arr[ind]) {
            int len = 1 + ldsStart(j, n, arr, dp);
            if (len > maxLen) maxLen = len;
        }
    }

    return dp[ind] = maxLen;
}

int main() {
    int n;
    scanf("%d", &n);

    // dp[N][N+1]
    int dp1[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            dp1[i][j] = -1;
        }
    }

    int dp2[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            dp2[i][j] = -1;
        }
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int inc = lisEnd(i, n, arr, dp1);
        int dec = ldsStart(i, n, arr, dp2);

        ans = max(ans, inc + dec - 1);
    }

    printf("%d", ans);
    return 0;
}