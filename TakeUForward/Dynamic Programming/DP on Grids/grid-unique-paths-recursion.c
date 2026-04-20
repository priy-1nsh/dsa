#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// unique paths recursion approach
f(int i, int j) {
    // base case
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) {
        return 0;
    }

    // do all stuffs
    int up = f(i - 1, j);
    int left = f(i, j - 1);

    // return the count
    return up + left;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[m][n];

    // read the grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // call the funciton
    int ans = f(m - 1, n - 1);

    printf("%d", ans);

    return 0;
}