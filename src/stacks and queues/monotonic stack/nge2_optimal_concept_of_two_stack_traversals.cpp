class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        // move i from 2*n - 1 to 0
        // ans[i] = something only when i < n
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; --i) {
            int index = i % n;
            while (!st.empty() && st.top() <= arr[index]) {
                st.pop();
            }

            if (i < n) {
                if (st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }

            st.push(arr[index]);
        }
        return ans;
    }
};