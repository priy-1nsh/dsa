#include <bits/stdc++.h>
using namespace std;

bool palindromeOrNot(string& s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return palindromeOrNot(s, l + 1, r - 1);
}

int main() {
    string s = "mom";
    int n = s.size();
    cout << palindromeOrNot(s, 0, n - 1);
    return 0;
}