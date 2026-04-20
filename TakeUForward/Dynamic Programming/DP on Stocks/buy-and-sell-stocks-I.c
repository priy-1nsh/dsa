#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min (int a, int b) {
    return (a>b) ? b : a;
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

int maxiProfit(int n, int arr[n]) {
    // n -> no. of days
    // find the maxProfit from day 0 to day n-1
    int maxProfit = 0;
    int mini = arr[0];
    for (int i = 1; i < n; i++) {
        int profit = arr[i] - mini;
        maxProfit = max(maxProfit, profit);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main() {
    int n = 5;
    int arr[5] = {5, 4, 3, 2, 1};

    int ans = maxiProfit(n, arr);

    printf("%d", ans);

    return 0;
}