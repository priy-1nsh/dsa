#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isomorphicStrings(string s, string t) {
        vector<int> sMap(256, 0);
        vector<int> tMap(256, 0);
        // given that s.length() = t.length()
        for (int i = 0; i < s.length(); i++) {
            if (sMap[s[i]] != tMap[t[i]]) return false;

            sMap[s[i]] = i + 1;
            tMap[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    string s = "ghgti";
    string t = "title";
    Solution sol;
    cout << sol.isomorphicStrings(s, t);
    return 0;
}