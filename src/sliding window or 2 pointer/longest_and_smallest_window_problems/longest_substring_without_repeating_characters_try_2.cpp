#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string& s) {
    int n = s.length();
    int l = 0, r = 0;
    int maxLen = 0;
    int len = 0;
    set<char> st;
    string str = "";
    while (r < n) {
        while (st.find(s[r]) != st.end()) {
            // repeating
            st.erase(s[l]);
            l++;
        }
        str = s.substr(l, r - l + 1);
        st.insert(s[r]);
        len = str.length();
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
} 

int main() {
    string s = "aaabbbccc";
    int result = longestSubstring(s);
    cout << result;
    return 0;
}