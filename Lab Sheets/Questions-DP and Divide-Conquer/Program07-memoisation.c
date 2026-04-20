#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// wildcard matching - match pattern with string s
bool f(int i, int j, char* s, char* pattern, int m, int n, int dp[][n]) {
    // i is for pattern pattern
    // j is for string s

    // base case
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;  // pattern over but s remaining
    // s over OR s empty but pattern remaining
    if (i >= 0 && j < 0) {
        for (int k = 0; k <= i; k++) {
            // going from 0 -> i
            if (pattern[k] != '*') return false;
        }
        return true;
    }
    // memoisation
    if (dp[i][j] != -1) return dp[i][j];

    // do all the stuff
    if (pattern[i] == s[j] || pattern[i] == '?') {
        return dp[i][j] = f(i - 1, j - 1, s, pattern, m, n, dp);
    } else if (pattern[i] == '*') {
        return dp[i][j] = f(i - 1, j, s, pattern, m, n, dp) ||
                          f(i, j - 1, s, pattern, m, n, dp);
    } else
        return dp[i][j] = false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // n = length of string S
    // m = length of pattern p

    // declare a dp array
    int dp[m][n];  // dp[i][j]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    char s[n + 1];
    scanf("%s", s);

    char pattern[m + 1];
    scanf("%s", pattern);

    bool ans = f(m - 1, n - 1, s, pattern, m, n, dp);

    if (ans) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}