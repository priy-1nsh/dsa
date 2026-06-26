class Solution {
   public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            vector<int> temp;
            int res = 1;
            temp.push_back(res);
            for (int j = 2; j <= n - (n - i); j++) {
                // res = res * (row-col) / (col)
                res = res * (i - j + 1) / (j - 1);  //  using 1 based indexing
                temp.push_back(res);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};