class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string res = "";
        string first = strs[0];

        for (int i = 0; i < first.size(); i++) {
            int j = 1;
            while (j < strs.size()) {
                if (first[i] != strs[j][i]) {
                    return res;
                }
                j++;
            }
            res += first[i];
        }
        return res;
    }
};