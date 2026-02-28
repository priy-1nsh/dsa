#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }
            }
        }
    }
    // copy resulting set into a vector of vectors
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{

    return 0;
}