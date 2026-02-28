#include <bits/stdc++.h>
using namespace std;

// left - right approach

// function to check
bool checkEqual(string &s, string &goal)
{
    // considering lengths of both strings are equal
    int n = s.length();
    string left = "";
    int i = 0;
    while (i < n)
    {
        string right = s.substr(i);
        if (right + left == goal)
            return true;
        left += s[i];
        i++;
    }
    return false;
}

int main()
{
    string s = "abcde";
    string goal = "cdeab";
    if (checkEqual(s, goal))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}