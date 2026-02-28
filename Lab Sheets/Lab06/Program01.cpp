#include <bits/stdc++.h>
using namespace std;

// stock span - no.of consecutive days with stock prices <= the current day
// calculate the pge array storing the indexes - previous greater element
vector<int> findPGE(vector<int> &arr, int n)
{
    vector<int> pge(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            // means stack isn't empty and the element in the array stored at the
            // index stored in the stack is <= arr[i] - we want > arr[i]
            st.pop();
        }
        // took out all the elements which are <= arr[i] from the stack
        // now the index stored at the top of the stack is of the element which
        // is > arr[i]
        if (st.empty())
        {
            pge[i] = -1;
        }
        else
        {
            pge[i] = st.top();
        }
        st.push(i);
    }
}
vector<int> findSpan(vector<int> &arr, int n)
{
    vector<int> pge = findPGE(arr, n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = i - pge[i]; // current index - index of the nearest left element
                             // which is > this element stored at this index
    }
    return ans;
}

int main()
{

    return 0;
}