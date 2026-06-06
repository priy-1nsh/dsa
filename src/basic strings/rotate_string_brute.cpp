#include <bits/stdc++.h>
using namespace std;

string rotateByOne(string s) {
    int n = s.length();
    string t;
    // returns the string s after one shift;
    char temp = s[0];
    for (int i = 1; i <= n - 1; i++) {
        t.push_back(s[i]);
    }
    t.push_back(temp);
    return t;
}

string rotate(string s) { return s.substr(1) + s[0]; }

bool checkGoal(string s, string goal) {
    for (int i = 0; i < s.length(); i++) {
        s = rotate(s);
        if ((s) == goal) return true;
    }
    return false;
}

int main() {
    string s = "abcde";
    string goal = "bdeac";
    bool result = checkGoal(s, goal);
    cout << result;
    return 0;
}

// TC - O(N2)
// SC - O(2N)