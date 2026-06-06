#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validAnagram(string s, string t) {
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freqS[i] != freqT[i]) return false;
        }
        return true;
    }
};

int main() {
    string s = "eat";
    string t = "ahe";
    Solution sol;
    bool result = sol.validAnagram(s, t);
    cout << result;
    return 0;
}