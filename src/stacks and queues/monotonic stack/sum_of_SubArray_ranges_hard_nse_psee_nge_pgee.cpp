class Solution {
   private:
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }
        return nge;
    }
    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pgee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty())
                pgee[i] = -1;
            else
                pgee[i] = st.top();

            st.push(i);
        }
        return pgee;
    }
    // using the above two, we find the sum of subarray maximums
    long long sumOfSubArrayMaximums(vector<int>& arr) {
        int n = arr.size();
        long long sumMax = 0;
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        for (int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            sumMax += (left * right * 1LL * arr[i]);
        }
        return sumMax;
    }

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
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return psee;
    }
    long long sumOfSubArrayMinimums(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            sum += (left * right * 1LL * arr[i]);
        }
        return sum;
    }

   public:
    long long subArrayRanges(vector<int>& nums) {
        long long sumMax = sumOfSubArrayMaximums(nums);
        long long sumMin = sumOfSubArrayMinimums(nums);
        return sumMax - sumMin;
    }
};