#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int lowerBound(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= x)
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

public:
    int rowWithMax1s(vector<vector<int>> &mat, int n, int m)
    {
        int countMax = 0;
        int row = 0;
        for (int i = 0; i < n; i++)
        {
            int count = m - lowerBound(mat[i], m, 1);
            if (count > countMax)
            {
                countMax = count;
                row = i;
            }
        }
        return row;
    }
};

int main()
{

    return 0;
}