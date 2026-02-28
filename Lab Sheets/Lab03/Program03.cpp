#include <bits/stdc++.h>
using namespace std;

// koko eating bananas

int findMaxEl(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

int getTotalHours(vector<int> &arr, int n, int speed)
{
    // speed - bananas / perhour
    int totalHours = 0;

    for (int i = 0; i < n; i++)
    {
        totalHours += (int)ceil((double)arr[i] / (double)speed);
    }
    return totalHours;
}

int minimumEatingSpeed(vector<int> &arr, int n, int h)
{
    int low = 1, high = findMaxEl(arr, n);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        int totalHoursToEatThePile = getTotalHours(arr, n, mid);

        if (totalHoursToEatThePile <= h)
        {
            // total hours taken is more than the limited time
            // faster the speed
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

    int n;
    cin >> n;

    vector<int> piles;
    int pile;

    // accept the number of bananas in each pile
    for (int i = 0; i < n; i++)
    {
        cin >> pile;
        piles.push_back(pile);
    }

    int h;
    cin >> h;

    int ans = minimumEatingSpeed(piles, n, h);

    cout << ans;

    return 0;
}