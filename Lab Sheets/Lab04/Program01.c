#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pair
{
    int first;
    int second;
} Pair;

Pair searchMatrix(int **mat, int n, int m, int target)
{
    Pair indexes;
    indexes.first = -1;
    indexes.second = -1;
    // n - number of rows
    // m - number of columns
    // start at the top-right corner
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (mat[row][col] == target)
        {
            indexes.first = row;
            indexes.second = col;
            return indexes;
        }
        else if (mat[row][col] < target)
            row++; // increase - go down
        else
            col--; // decrease
    }
    return indexes;
}

int main()
{

    int m, n;
    scanf("%d %d", &m, &n);

    int **mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    // take user input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int target;
    scanf("%d", &target);

    Pair result = searchMatrix(mat, m, n, target);

    if (result.first == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d, %d\n", result.first, result.second);
    }

    // free memory
    for (int i = 0; i < m; i++)
    {
        free(mat[i]);
    }

    free(mat);

    return 0;
}