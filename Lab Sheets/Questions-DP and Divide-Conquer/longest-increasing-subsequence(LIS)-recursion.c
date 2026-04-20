#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// longest increasing subsequence - recursion
int f(int ind, int prevInd, int n, int arr[]) {
    // base case
    if (ind == n) return 0;

    // do all the stuffs
    // not take
    int lis = 0 + f(ind + 1, prevInd, n, arr);
    // take
    if (prevInd == -1 || arr[ind] > arr[prevInd]) {
        lis = max(lis, 1 + f(ind + 1, ind, n, arr));
    }

    return lis;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = f(0, -1, n, arr);

    printf("%d", ans);

    return 0;
}