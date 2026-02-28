#include <bits/stdc++.h>
using namespace std;

// linear search
int maximumOnesLinearSearch(vector<vector<int>> &mat, int n)
{
    int maxOnes = 0;
    int row = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxOnes)
        {
            maxOnes = count;
            row = i;
        }
        if (count == maxOnes && i < row)
            row = i;
    }
    return row;
}

int main()
{

    return 0;
}