#include <bits/stdc++.h>
using namespace std;

// finding previous smaller element
vector<int> findPSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        // if stack is not empty or has elements >= arr[i], pop them out
        while (!st.empty() && st.top() >= arr[i])
            st.pop();

        if (st.empty())
        {
            // stack is empty
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top();
        }
        st.push(arr[i]);
    }
    return pse;
}

int main()
{

    return 0;
}