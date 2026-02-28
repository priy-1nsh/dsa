#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findDays(vector<int> &arr, int capacity)
    {
        int i = 0;
        int load = 0;
        int days = 0;
        int n = arr.size();
        while (i < n)
        {
            if ((load + arr[i]) > capacity)
            {
                days++;
                load = 0;
            }
            load += arr[i];
            i++;
        }
        days++;
        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // binary-search
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int daysItTook = findDays(weights, mid);

            if (daysItTook <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                // increase the capacity
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{

    Solution sol;

    vector<int> v = {1, 2, 3, 1, 1};

    int days = 4;

    int ans = sol.shipWithinDays(v, days);

    cout << ans;

    return 0;
}