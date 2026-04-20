#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// longest common subsequence - recursion
// f(ind1, ind2) = lcs od s1(0->ind1) and s2(0->ind2)
int f(int ind1, int ind2, int m, int n, char* s1, char* s2) {
    // base case
    if (ind1 < 0 || ind2 < 0)
        return 0;  // ofcourse nothing to compare so length = 0

    // do all the stuffs
    // either mathches
    if (s1[ind1] == s2[ind2]) {
        return 1 + f(ind1 - 1, ind2 - 1, m, n, s1, s2);
    } else {
        // doesn't match
        return 0 + max(f(ind1 - 1, ind2, m, n, s1, s2),
                       f(ind1, ind2 - 1, m, n, s1, s2));
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char s1[m + 1];
    char s2[n + 1];

    scanf("%s", s1);
    scanf("%s", s2);

    int ans = f(m - 1, n - 1, m, n, s1, s2);

    printf("%d", ans);

    return 0;
}