#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a >= b) ? a : b; }

// freelancer developer's dilemma - knapsack problem
// return max of the payment sum
int f(int i, int h, int payments[], int hours[], int dp[][h+1]) { // always specify columns when passing 2D arrays in C functions
    // h hours are left

    // base case
    // going from top to bottom
    if (i == 0) {
        if (hours[0] <= h)
            return payments[0];
        else
            return 0;
    }
    if (dp[i][h] != -1) return dp[i][h];

    // not pick the job
    int notPick = f(i - 1, h, payments, hours, dp);

    // pick the job
    int pick = 0;
    if (hours[i] <= h) {
        pick = f(i - 1, h - hours[i], payments, hours, dp) + payments[i];
    }

    return dp[i][h] = max(notPick, pick);
}

int main() {
    int N, H;
    scanf("%d %d", &N, &H);

    // payments array
    int payments[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &payments[i]);
    }

    // hours array
    int hours[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &hours[i]);
    }

    int dp[N][H + 1];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = f(N-1, H, payments, hours, dp);

    printf("%d", ans);

    return 0;
}