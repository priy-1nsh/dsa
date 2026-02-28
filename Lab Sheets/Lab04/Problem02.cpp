#include <bits/stdc++.h>
using namespace std;

// search in a 2D matrix such that first elt in each row is > than the last elt of the prev
// row

bool searchMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
    int low = 0, high = m * n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / n;
        int col = mid % n;
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    return 0;
}