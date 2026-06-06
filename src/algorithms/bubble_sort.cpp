#include <bits/stdc++.h>
using namespace std;

// Push the maximum to the last by adjacent swapping
// TC - worst/average - O(N2)
// TC - best - O(N)

class Solution {
   public:
    int bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            int didSwap = 0;
            for (int j = 0; j <= i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    didSwap = 1;
                }
            }
            if (didSwap == 0)
                break;  // breaks from the outer loop after N-1 iterations, if
                        // no swaps happen in the first iteration of the outer
                        // loop
        }
    }
};
int main() {
    Solution sol;
    vector<int> vec = {2, 4, 7, 19, 9, 7, 24, 16};
    sol.bubbleSort(vec);
    for (auto it : vec) {
        cout << it << " ";
    }
    return 0;
    return 0;
}