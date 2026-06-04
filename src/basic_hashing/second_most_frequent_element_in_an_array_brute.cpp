#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int secondMostFrequent(vector<int>& arr) {
        int N = arr.size();

        // most Frequent Element = el1
        // second most frequent Element = el2
        int el1Freq = 0, el2Freq = 0;
        int el1 = -1, el2 = -1;

        vector<int> visited(N, 0);

        for (int i = 0; i < N; i++) {
            if (visited[arr[i]] == 0) {
                visited[arr[i]] = 1;
                int count = 0;  // by using count, we will track the most
                                // frequent element
                for (int j = 0; j < N; j++) {
                    if (arr[i] == arr[j]) {
                        count++;
                    }
                }
                // now we have the most frequent element as arr[i];
                if (count > el1Freq) {
                    el2 = el1;
                    el2Freq = el1Freq;
                    el1 = arr[i];
                    el1Freq = count;
                } else if (count <= el1Freq && count > el2Freq) {
                    el2 = arr[i];
                    el2Freq = count;
                } else if (count == el2Freq && arr[i] < el2) {
                    el2 = arr[i];
                }
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

// TC = O(N2);