#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a > b) ? b : a; }

int max(int a, int b) { return (a > b) ? a : b; }

// find maxProfit
int f(int ind, int buy, int n, int arr[n], int dp[][2]) {
    // base case
    if (ind == n) return 0;  // can't buy can't sell cuz the last day was n-1
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    // do all the stuff
    int profit = 0;
    if (buy) {
        // buying is permitted
        // let's buy
        int profit1 = -arr[ind] + f(ind + 1, 0, n, arr, dp);
        // let's not buy
        int profit2 = 0 + f(ind + 1, 1, n, arr, dp);
        profit = max(profit1, profit2);
    } else {
        // buying is not permitted - so we can sell
        // let's sell
        int profit1 = arr[ind] + f(ind + 1, 1, n, arr, dp);
        // let's not sell
        int profit2 = 0 + f(ind + 1, 0, n, arr, dp);
        profit = max(profit1, profit2);
    }

    return dp[ind][buy] = profit;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // memoisation
    // declare dp array
    int dp[n + 1][2];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }

    // call the function
    int ans = f(0, 1, n, arr, dp);

    printf("%d", ans);

    return 0;
}