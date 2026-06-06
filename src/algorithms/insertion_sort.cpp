#include <bits/stdc++.h>
using namespace std;

// Takes an element and places it in its correct position
// TC - worst/average = O(N2) or O((N-1)N/2)
// TC - best = O(N)

class Solution {
   public:
    void insertionSort(vector<int>& arr) {
        for (int i = 1; i < N; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) {
                // j > 0 since if j = 0 then j-1 will become -1
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
};

int main() { return 0; }