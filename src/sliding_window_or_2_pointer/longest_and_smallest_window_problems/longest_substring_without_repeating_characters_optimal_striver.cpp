#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string& s) {
    int n = s.length();
    int maxLen = 0;
    int l = 0, r = 0;

    vector<int> hash(256, -1); // initialised with -1 meaning not have encountered anything
    while (r < n) {
        if (hash[s[r]] != -1) {
            // have seen this element before
            if (hash[s[r]] >= l) {
                // this previous occurence is also a part of the current subarray
                l = hash[s[r]] + 1;
                // update the l
            }
        }
        // not have seen this element before
        maxLen = max(maxLen, r - l + 1);
        hash[s[r]] = r; // store the index where s[j] is encountered

        r++;
    }
    return maxLen;
}

int main() {
    return 0;
}