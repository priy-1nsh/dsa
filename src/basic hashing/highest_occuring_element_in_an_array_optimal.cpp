#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int highestOccuringElement(vector<int>& arr, int N) {
        // N - size of the array
        // find the max element first
        int maxi = -1;
        for (int i = 0; i < N; i++) {
            maxi = max(maxi, arr[i]);
        }

        // hash array of size maxi + 1
        vector<int> hash(maxi + 1, 0);
        // each index of the hash array will correspond to the frequency of the
        // element i of the arr

        for (int i = 0; i < N; i++) {
            hash[arr[i]]++;
        }

        int maxFreq = 0, maxEl = -1;
        for (int i = 0; i <= maxi; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                maxEl = i;
            } else if (hash[i] == maxFreq && i < maxEl) {
                maxEl = i;
            }
        }
        return maxEl;
    }
};

int main() {
    // highest occuirng element in an Array
    Solution sol;
    vector<int> v = {2, 2, 3, 3, 3, 1, 1, 1, 8};
    cout << sol.highestOccuringElement(v, v.size());
    return 0;
}