#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int sumOfHighestAndLowest(vector<int>& arr) {
        int N = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> visited(maxi + 1, 0);
        int minFreq = N, maxFreq = 0;
        for (int i = 0; i < N; i++) {
            if (visited[arr[i]] == 0) {
                // not yet visited
                visited[arr[i]] = 1;
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (arr[i] == arr[j]) count++;
                }
                // for loop ends - count contains the count of the arr[i] in the
                // arr
                if (count > maxFreq) maxFreq = count;
                if (count < minFreq) minFreq = count;
            }
        }
        return maxFreq + minFreq;
    }
};

int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 1};
    Solution sol;  // on stack
    cout << sol.sumOfHighestAndLowest(v);
    return 0;
}