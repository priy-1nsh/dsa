#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

// optimal game
// recursion
// f(i, j) = max value that Alpha can get from arr[i, .... , j]
int f(int arr[], int i, int j) {
    // base case
    if (i > j) return 0;
    if (i == j) return arr[i];

    // do all the stuff
    int pickLeft = arr[i] + min(f(arr, i + 2, j), f(arr, i + 1, j - 1));
    int pickRight = arr[j] + min(f(arr, i, j - 2), f(arr, i + 1, j - 1));

    return max(pickLeft, pickRight);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = f(arr, 0, n - 1);

    printf("%d", ans);

    return 0;
}