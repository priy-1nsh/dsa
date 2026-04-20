#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// best time to buy and sell stock IV
// Now, let's make the recursive function
int f(int i, int buy, int cap, int n, int arr[], int k, int dp[][2][k]) {
    // base case
    if (i == n) return 0;
    if (cap == 0) return 0;

    // memoisation
    if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

    // do all the stuff
    if (buy) {
        return dp[i][buy][cap] =
                   max((-arr[i] + f(i + 1, 0, cap, n, arr, k, dp)),
                       (0 + f(i + 1, 1, cap, n, arr, k, dp)));
    } else {
        return dp[i][buy][cap] =
                   max((arr[i] + f(i + 1, 1, cap - 1, n, arr, k, dp)),
                       (0 + f(i + 1, 0, cap, n, arr, k, dp)));
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int dp[n][2][k + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l < k + 1; l++) {
                dp[i][j][l] = -1;
            }
        }
    }

    int ans = f(0, 1, k, n, arr, k, dp);

    printf("%d", ans);

    return 0;
}