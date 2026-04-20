#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int f(int m, int n, char* s1, char* s2) {
    // base case
    // declare a dp array
    int dp[m + 1][n + 1];
    // base case
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    // skip i = 0 and j = 0
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // copy the recurrence
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() { 
    int m, n;
    scanf("%d %d", &m, &n);

    char s1[m + 1];
    char s2[n + 1];

    scanf("%s", s1);
    scanf("%s", s2);

    int ans = f(m, n, s1, s2);

    printf("%d", ans);

    return 0; 
}