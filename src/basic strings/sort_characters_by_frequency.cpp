#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, char> a, pair<int, char> b) {
    // a must occur before b
    if (a.first > b.first) return true;
    if (a.first < b.first) return false;
    if (a.second < b.second) return true;
    return false;
}

vector<char> sortCharacters(string s) {
    vector<pair<int, char>> freq(26, {0, 'a'});
    for (int i = 0; i < 26; i++) {
        freq[i].second = 'a' + i;
    }
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a'].first++;
    }
    sort(freq.begin(), freq.end(), comparator);
    vector<char> ans;
    for (int i = 0; i < 26; i++) {
        if (freq[i].first == 0) break;
        ans.push_back(freq[i].second);
    }
    return ans;
}

int main() {
    string s = "paper";
    vector<char> ans = sortCharacters(s);
    for (auto i : ans) {
        cout << i;
    }
    return 0;
}

// TC - O(26) + O(N) + O(26log26) + O(26) ~ O(N)
// SC - O(26) * 2 + O(26) + O(26)