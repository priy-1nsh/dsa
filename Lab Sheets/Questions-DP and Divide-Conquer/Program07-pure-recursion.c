#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// wildcard matching
bool f(int i, int j, char* s, char* pattern) {
    // i is for pattern pattern
    // j is for string s

    // base case
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;  // pattern over but s remaining
    // s over OR s empty but pattern remaining
    if (i >= 0 && j < 0) { // match with empty s
        for (int k = 0; k <= i; k++) {
            // going from 0 -> i
            if (pattern[k] != '*') return false;
        }
        return true;
    }

    // do all the stuff
    if (pattern[i] == s[j] || pattern[i] == '?') {
        return f(i - 1, j - 1, s, pattern);
    } else if (pattern[i] == '*') {
        return f(i - 1, j, s, pattern) || f(i, j - 1, s, pattern);
    } else
        return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // n = length of string S
    // m = length of pattern p

    char s[n + 1];
    scanf("%s", s);

    char pattern[m + 1];
    scanf("%s", pattern);

    bool ans = f(m - 1, n - 1, s, pattern);

    if (ans) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}