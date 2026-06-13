#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string& s) {
    int n = s.length();
    int len = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        string str = "";
        set<char> st;
        for (int j = i; j < n; j++) {
            if (st.find(s[j]) != st.end()) {
                break;
            }
            str.push_back(s[j]);
            st.insert(s[j]);
            len = str.length();
            
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

int main() {
    string s = "aaaa";
    int result = longestSubstring(s);
    cout << result;
    return 0;
}