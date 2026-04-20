#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int max(int a, int b) { return (a > b) ? a : b; }

// lcs - recursion based
// now - let's memoise it
int lcs(int ind1, int ind2, int n, char* s1, char* s2, int dp[][n]) {
    // base case
    if (ind1 < 0 || ind2 < 0) return 0;
    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

    // do all the stuff
    // match or not-matched
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, n, s1, s2, dp);
    else
        return dp[ind1][ind2] = 0 + max(lcs(ind1 - 1, ind2, n, s1, s2, dp),
                       lcs(ind1, ind2 - 1, n, s1, s2, dp));
}

int main() {
    int n;
    scanf("%d", &n);

    // declare dp array
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    char s2[n + 1];
    scanf("%s", s2);

    char s1[n + 1];
    strcpy(s1, s2);

    // reverse s2
    reverse(s2);

    // now we call lcs on s1 and s2 to find the longest common subsequence
    // between the original string and the reversed string
    int ans = lcs(n - 1, n - 1, n, s1, s2, dp);

    printf("%d", ans);

    return 0;
}