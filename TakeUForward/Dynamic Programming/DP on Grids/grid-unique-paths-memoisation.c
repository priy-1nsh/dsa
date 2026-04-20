    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>

    // unique paths memoisation
    int f(int i, int j, int m, int n, int dp[m][n]) {
        // base case
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // do all stuffs
        int up = f(i - 1, j, m, n, dp);
        int left = f(i, j - 1, m, n, dp);

        // return the count
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

        // call the funciton
        int ans = f(m - 1, n - 1, m, n, dp);

        printf("%d", ans);

        return 0;
    }