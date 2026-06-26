class Solution {
   public:
    vector<int> pascalTriangleII(int r) {
        vector<int> ans;
        int res = 1;
        ans.push_back(res);
        for (int i = 2; i <= r; i++) {
            res = res * (r - i + 1) / (i - 1);
            ans.push_back(res);
        }
        return ans;
    }
};