#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b) {
    return (a>b) ? a : b;
}

// longest valid data block
// f(start, end) = longest contiguous string with each character occuring >= K times
int f(int start, int end, char* s, int k) {
    // base case
    if ((end - start + 1) < k) return 0; // no. of characters in the substring < K

    // calculate the freq of each character in the string
    int freq[26] = {0};
    for (int i = start; i <= end; i++) {
        freq[s[i] - 'a']++;
    }

    // now, check for invalid characters
    for (int i = start; i <= end; i++) {
        if (freq[s[i] - 'a'] < k) {
            // invalid character - split
            int left = f(start, i-1, s, k);
            int right = f(i+1, end, s, k);

            return max(left, right);
        }
    }
    // else all the characters are valid -> whole string is the answer
    return (end-start+1);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[n+1];
    scanf("%s", s);

    int ans = f(0, n-1, s, k);

    printf("%d", ans);

    return 0;
}