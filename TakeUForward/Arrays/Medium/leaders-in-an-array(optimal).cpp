#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &arr)
{
    int n = arr.size();

    int maxi = INT_MIN;

    vector<int> leaders;

    for (i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            leaders.push_back(arr[i]);
            maxi = arr[i]; // keep track of the right maximum
        }
    }

    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main()
{

    return 0;
}