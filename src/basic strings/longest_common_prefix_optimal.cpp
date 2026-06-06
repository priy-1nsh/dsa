#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int N = strs.size();
        string first = strs[0];
        string last = strs[N - 1];
        string res = "";
        int minSize = min(first.length(), last.length());
        // compare the first and the last string
        for (int i = 0; i < minSize; i++) {
            if (first[i] == last[i]) {
                res += first[i];
            } else {
                return res;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "float", "flight"};
    cout << sol.longestCommonPrefix(strs);
    return 0;
}

// TC : O(NlogN * M) where N is the size of the array and M is the upper bound
// on the string comparison cost, which is taken to be the size of the longest
// string. Note : M is not necesssarily the longest string size in the strs
// array but serves as a good upper bound on the string comparison.

// https://docs.google.com/spreadsheets/d/1GqMvrQJUZHtqRpYYhD66CQo80EtnsRHvqYvGYbPSmOU/edit?usp=sharing