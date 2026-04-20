#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a > b) ? b : a; }

int max(int a, int b) { return (a > b) ? a : b; }

// buy and sell stock but with the cap of maximum 2 transactions
int f(int ind, int buy, int cap, int n, int arr[n], int dp[][2][3]) {
    // base case
    if (cap == 0) return 0;
    if (ind == n) return 0;  // out of the trading period
    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    // do all the stuffs
    if (buy) {
        // buy is permitted
        profit = max((-arr[ind] + f(ind + 1, 0, cap, n, arr, dp)),
                     (0 + f(ind + 1, 1, cap, n, arr, dp)));
    } else {
        // buy is not permitted - sell
        profit = max((arr[ind] + f(ind + 1, 1, cap - 1, n, arr, dp)),
                     (0 + f(ind + 1, 0, cap, n, arr, dp)));
    }
    return dp[ind][buy][cap] = profit;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // memoisation
    // declare a dp array
    int dp[n][2][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int ans = f(0, 1, 2, n, arr, dp);

    printf("%d", ans);

    return 0;
}