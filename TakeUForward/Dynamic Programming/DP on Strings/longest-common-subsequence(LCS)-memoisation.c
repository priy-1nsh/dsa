#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// longest common subsequence - recursion
// f(ind1, ind2) = lcs od s1(0->ind1) and s2(0->ind2)
int f(int ind1, int ind2, int m, int n, char* s1, char* s2, int dp[][n]) {
    // base case
    if (ind1 < 0 || ind2 < 0)
        return 0;  // ofcourse nothing to compare so length = 0

    // memoisation base case
    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

    // do all the stuffs
    // either mathches
    if (s1[ind1] == s2[ind2]) {
        return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, m, n, s1, s2, dp);
    } else {
        // doesn't match
        return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, m, n, s1, s2, dp),
                                        f(ind1, ind2 - 1, m, n, s1, s2, dp));
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // declare dp array
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    char s1[m + 1];
    char s2[n + 1];

    scanf("%s", s1);
    scanf("%s", s2);

    int ans = f(m - 1, n - 1, m, n, s1, s2, dp);

    printf("%d", ans);

    return 0;
}