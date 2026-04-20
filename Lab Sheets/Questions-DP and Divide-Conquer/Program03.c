#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// recurrence for the number of distinct subsequence in s[0 -> n-1] of t[0 ->
// m-1] i -> s and j -> t
long long f(int i, int j, int n, int m, char* s, char* t, long long dp[][m]) {
    // base case
    // s = bagbag    i
    // t = bag       j
    // if j exhasuted => means found
    // if i exhausted => means not found
    if (j < 0) return 1;
    if (j >= 0 && i < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    // do all the stuff
    if (s[i] == t[j]) {
        return dp[i][j] = f(i - 1, j - 1, n, m, s, t, dp) + f(i - 1, j, n, m, s, t, dp);
    } else {
        return dp[i][j] = f(i - 1, j, n, m, s, t, dp);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // n is the lenght of source s
    // m is the length of target t

    char s[n + 1];
    scanf("%s", s);

    char t[m + 1];
    scanf("%s", t);

    long long dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    long long ans = f(n - 1, m - 1, n, m, s, t, dp);

    printf("%lld", ans);

    return 0;
}