class Solution {
   private:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;  // st will contain indexes not elements since we need
                        // indexes not elements
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }

    // pse = previous smaller or equal element
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return pse;
    }

   public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        const int mod = (int)(1e9 + 7);
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);

        for (int i = 0; i < n; i++) {
            int noOfLeftSubArrays = i - pse[i];
            int noOfRightSubArrays = nse[i] - i;

            sum = (sum +
                   ((noOfLeftSubArrays * noOfRightSubArrays * 1ll * arr[i]) %
                    mod)) %
                  mod;
        }
        return sum;
    }
};