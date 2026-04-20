#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }

// edit distance
// f(i, j) = min. number of steps to convert s1[0->i] into s2[0->j]
int f(int i, int j, int n, int m, char* s1, char* s2, int dp[][m]) {
    // base case
    if (i < 0) return (j + 1);
    if (j < 0) return (i + 1);
    if (dp[i][j] != -1) return dp[i][j];

    // do all the stuff
    // match
    if (s1[i] == s2[j]) return dp[i][j] = 0 + f(i - 1, j - 1, n, m, s1, s2, dp);
    // not match
    else {
        return dp[i][j] = 1 + min(f(i - 1, j, n, m, s1, s2, dp),
                                  min(f(i, j - 1, n, m, s1, s2, dp),
                                      f(i - 1, j - 1, n, m, s1, s2, dp)));
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    char s1[n + 1];
    scanf("%s", s1);

    char s2[m + 1];
    scanf("%s", s2);

    // convert s1 into s2
    int ans = f(n - 1, m - 1, n, m, s1, s2, dp);

    printf("%d", ans);

    return 0;
}