#include <bits/stdc++.h>
using namespace std;

// move zeros to end in place
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;
    int count = 0; // count of 0s encountered
    while (j < n)
    {
        if (nums[j] != 0)
        {
            nums[i] = nums[j];
            i++;
            j++;
        }
        else
        {
            count++;
            j++;
        }
    }
    for (int i = n - count; i < n; i++)
    {
        nums[i] = 0;
    }
}

// striver approach
void moverZeros(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;
    // point j to the first 0th element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // now, use 2 pointer approach
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}

int main()
{

    return 0;
}