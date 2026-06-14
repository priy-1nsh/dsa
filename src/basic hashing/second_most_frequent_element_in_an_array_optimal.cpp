#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int secondMostFrequent(vector<int>& arr) {
        int N = arr.size();
        int maxi = arr[0];
        int el1 = -1, el2 = -1;
        int el1Freq = 0, el2Freq = 0;
        for (int i = 0; i < N; i++) {
            maxi = max(maxi, arr[i]);
        }

        vector<int> hash(maxi + 1, 0);
        for (int i = 0; i < N; i++) {
            hash[arr[i]]++;
        }

        for (int i = 0; i <= maxi; i++) {
            // count = hash[i]
            // element = i
            if (hash[i] > el1Freq) {
                el2 = el1;
                el2Freq = el1Freq;
                el1 = i;
                el1Freq = hash[i];
            } else if (hash[i] <= el1Freq && hash[i] > el2Freq) {
                el2 = i;
                el2Freq = hash[i];
            } else if (hash[i] == el2Freq && el2 > i) {
                el2 = i;
            }
        }
        return el2;
    }
};

int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 1};
    Solution sol;  // on stack
    cout << sol.secondMostFrequent(v);
    return 0;
}