#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int m, int target)
{
    int low = 0;
    int high = m - 1;
    int ans = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            // since we want the first element, we going left - sorted
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int calcSmallerEquals(vector<vector<int>> &mat, int n, int m, int target)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += upperBound(mat[i], m, target);
    }
    return count;
}

int findMedian(vector<vector<int>> &mat, int n, int m)
{
    int required = m * n / 2;
    int low = mat[0][0];
    int high = -1;
    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallerEquals = calcSmallerEquals(mat, n, m, mid);

        if (smallerEquals >= required + 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {18, 19, 20}, {13, 14, 15}};
    cout << findMedian(matrix, 3, 3);

    return 0;
}