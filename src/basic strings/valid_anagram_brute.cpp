#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    string s = "eat";
    string t = "ate";
    bool result = validAnagram(s, t);
    cout << result;
    return 0;
}

// TC - O(2*NlogN), where N is the length of the string