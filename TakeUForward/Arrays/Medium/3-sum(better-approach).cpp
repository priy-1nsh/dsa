#include <bits/stdc++.h>
using namespace std;

// O(n2) TC approach

vector<vector<int>> findTriplets(vector<int> &arr, int n)
{
    set<vector<int>> triplets; // to store unique triplets
    for (int i = 0; i < n; i++)
    {
        // re-initialize the hashset with all 0s
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            // now check if this third is in the hashset
            if (hashset.find(third) != hashset.end()) // found the element
            {
                // make the triplet
                vector<int> triplet = {arr[i], arr[j], third};
                // sort the triplet to check in case we are not adding a duplicate triplet
                sort(triplet.begin(), triplet.end());
                // now add it to the set of the triplets if it's unique
                triplets.insert(triplet);
            }
            hashset.insert(arr[j]); // add the visited element
        }
    }
    vector<vector<int>> ans(triplets.begin(), triplets.end());
    return ans;
}

int main()
{

    return 0;
}