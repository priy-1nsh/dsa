#include <bits/stdc++.h>
using namespace std;

string toLower(string s) {
    for (char& c : s) c = tolower((unsigned char)c);
    return s;
}

vector<string> returnHashtags(vector<string>& strings, vector<int>& timestamps, int currentTime, int timeWindow) {
    int n = strings.size();
    int lo = currentTime - timeWindow, hi = currentTime;
    // return the vector<int> ans which contain frequently occuring hashtags

    unordered_map<string, int> cnt_hashtags;
    // word count
    unordered_map<string, int> firstSeen;
    // word timestamp at which i first saw this word

    for (int i = 0; i < n; i++) {
        if (timestamps[i] < lo || timestamps[i] > hi) continue;
        stringstream ss(strings[i]);
        string tok;
        while (ss >> tok) { // data flows from stream ss into token tok
            if (tok[0] == '#') {
                // is a valid string
                tok = toLower(tok);
                cnt_hashtags[tok]++;
                string key = tok;
                if (firstSeen.find(key) != firstSeen.end()) {
                    firstSeen[key] = min(firstSeen[key], timestamps[i]);
                }
                else firstSeen[key] = timestamps[i];
            }
        }
    }

    // now take only those which occur more than 2 times
    vector<pair<string, int>> occurMoreThanOrEqual2Times;
    // word timestamp
    for (auto &it : cnt_hashtags) {
        if (it.second >= 2) {
            occurMoreThanOrEqual2Times.push_back({it.first, firstSeen[it.first]});
        }
    }

    // now let's find the final answer
    // first sort the occurMoreThanOrEqual2Times
    sort(occurMoreThanOrEqual2Times.begin(), occurMoreThanOrEqual2Times.end(), [&](const auto &a, const auto &b) {
        if (cnt_hashtags[a.first] != cnt_hashtags[b.first]) return cnt_hashtags[a.first] > cnt_hashtags[b.first];
        if (a.second != b.second) {
            // they occur for the same number of times, decide based on the second
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    vector<string> ans;
    for (auto it : occurMoreThanOrEqual2Times) {
        ans.push_back(it.first);
    }
    
    return ans;
}

int main() {
    return 0;
}