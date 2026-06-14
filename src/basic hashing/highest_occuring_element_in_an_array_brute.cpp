#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int highestOccuringElement(vector<int>& arr) {
        int N = arr.size();
        vector<bool> visited(N, false);
        int maxFreq = 0;
        int maxElement = -1;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (visited[arr[i]] == false) {
                // if not yet visited
                // visit it
                visited[arr[i]] = true;
                // initialize count to 0
                count = 0;
                for (int j = 0; j < N; j++) {
                    if (arr[i] == arr[j]) count++;
                }
                // count calculated
                if (count > maxFreq) {
                    maxFreq = count;
                    maxElement = arr[i];
                } else if (count == maxFreq && arr[i] < maxElement) {
                    maxElement = arr[i];
                }
            }
        }
        return maxElement;
    }
};

int main() {
    // highest occuring element in an array
    vector<int> v = {2, 3, 5, 6, 8, 8, 7, 3, 3, 2, 2};
    Solution sol;  // on stack
    cout << sol.highestOccuringElement(v);
    return 0;
}