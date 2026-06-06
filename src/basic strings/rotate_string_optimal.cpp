#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    string doubleS = s + s;
    if (s.length() != goal.length()) return false;

    if (doubleS.find(goal) == string::npos)
        return false;
    else
        return true;
}

int main() {
    string s = "abcde";
    string t = "cdeba";
    cout << rotateString(s, t);
    return 0;
}