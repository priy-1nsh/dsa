#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a > b) ? b : a; }

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap(arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// optimised cuts
int f(int i, int j, int cuts[], int m, int dp[][m + 1]) {
    // base case
    if (i > j) return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++) {
        int cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts, m, dp) +
                   f(ind + 1, j, cuts, m, dp);
        mini = min(mini, cost);
    }
    return mini;
}

int main() {
    int n, m;
    // n = size of the beam initially
    // m = no. of cuts to be made
    scanf("%d %d", &n, &m);

    int input[m];
    // accept the m integers
    for (int i = 0; i < m; i++) {
        scanf("%d", &input[i]);
    }

    // now we need to insert 0 at the front and n at the end of the cuts array
    int cuts[m + 2];
    cuts[0] = 0;
    for (int i = 0; i < m; i++) {
        cuts[i + 1] = input[i];
    }
    cuts[m + 1] = n;

    // declare dp array
    int dp[m + 1][m + 1];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            dp[i][j] = -1;
        }
    }

    // now we need to sort the array cuts
    bubbleSort(cuts, m + 2);

    // now, we call the recursion function
    int ans = f(1, m, cuts, m, dp);

    printf("%d", ans);

    return 0;
}