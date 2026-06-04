#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    // let's write better code using vector and not using clumsy pointers
    string longestCommonPrefixUsingVector(vector<string>& strs) {
        if (strs.empty()) return "";  // now this actually works
        string res = "";
        for (int i = 0; i < strs[0].length(); i++) {
            res += strs[0][i];
            for (int j = 0; j < strs.size(); j++) {  // .size() works
                if (res.size() > strs[j].size() ||
                    res != strs[j].substr(0, res.size())) {
                    res.pop_back();
                    return res;
                }
            }
        }
        return res;
    }

   public:
    string longestCommonPrefix(string* strs, int n) {
        if (strs->empty()) return "";
        string first = strs[0];
        string res = "";
        for (int i = 0; i < first.length(); i++) {
            res += first[i];
            // compare this newly added res with all the other strings
            for (int j = 0; j < n; j++) {
                if (res.size() > strs[j].size() ||
                    res != strs[j].substr(0, i - 0 + 1)) {
                    res.pop_back();
                    // if this condition is satisfied, then this means that the
                    // last added character to the string res is not matching
                    // with one of the strings, so we just pop the last added
                    // character and return the string res
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string strs[] = {"flower", "flow", "float", "flowers"};
    cout << sol.longestCommonPrefix(strs, 4);
    return 0;
}

// TC : O(N * M2) where N = size of the strs array, and M is the size of the
// first string, look at Notes.
