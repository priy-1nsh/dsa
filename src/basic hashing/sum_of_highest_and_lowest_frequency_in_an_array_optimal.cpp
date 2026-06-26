#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int sumOfHighestAndLowestFreq(vector<int>& arr) {
        int N = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> hash(maxi + 1, 0);
        int minFreq = N, maxFreq = 0;
        for (int i = 0; i < N; i++) {
            hash[arr[i]]++;
        }

        // Now, hash[i] stores the frequnecy of the i th element
        for (int i = 0; i < maxi + 1; i++) {
            if (hash[i] == 0) continue;  // important
            if (hash[i] > maxFreq) maxFreq = hash[i];
            if (hash[i] < minFreq) minFreq = hash[i];
        }
        return minFreq + maxFreq;
    }
};
int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 1};
    Solution sol;  // on stack
    cout << sol.sumOfHighestAndLowestFreq(v);
    return 0;
}