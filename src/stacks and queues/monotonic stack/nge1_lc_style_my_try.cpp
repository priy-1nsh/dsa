class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans(n1);

        stack<int> st;
        // if i cover the bigger array, it automatically covers the smaller
        // array
        for (int j = n2 - 1; j >= 0; j--) {
            bool found = false;
            while (!st.empty() && st.top() <= nums2[j]) {
                st.pop();
            }
            // now you have to find i st. nums1[i] == nums2[j] and based on the
            // stack data we will update the ans[i]
            int i = 0;
            for (i = 0; i < n1; i++) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                    break;
                }
            }

            if (st.empty() && found)
                ans[i] = -1;
            else if (found)
                ans[i] = st.top();

            st.push(nums2[j]);
        }
        return ans;
    }
};