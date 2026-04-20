#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// grid unique path with obstacles
// a cell with 0 is safe and a cell with 1 is a dead cell
int f(int i, int j, int m, int n, int dp[m][n], int grid[m][n]) {
    // base case
    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;  // valid cell and also a dead cell
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    // memoise
    if (dp[i][j] != -1) return dp[i][j];

    // do all possible stuff
    int up = f(i - 1, j, m, n, dp, grid);  // [ Imp : just pass the array name ]
    int left = f(i, j - 1, m, n, dp, grid);

    // return the count + save (memoise)
    return dp[i][j] = up + left;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // dp array and initialise
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int grid[m][n];

    // read the grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // call the function
    int ans = f(m - 1, n - 1, m, n, dp, grid);

    printf("%d", ans);

    return 0;
}