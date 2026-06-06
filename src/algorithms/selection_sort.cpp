#include <bits/stdc++.h>
using namespace std;

// select minimum and swap - takes the min to the front
// TC - O(N2) or O(N(N+1)/2)

class SelectionSort {
   public:
    void selectionSort(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            int minimumIndex = -1;
            for (int j = i; j < arr.size(); j++) {
                if (arr[j] < arr[minimumIndex]) {
                    minimumIndex = j;
                }
            }
            swap(arr[minimumIndex], arr[i]);
        }
    }
};
int main() {
    SelectionSort sol;
    vector<int> vec = {2, 4, 7, 19, 9, 7, 24, 16};
    sol.selectionSort(vec);
    for (auto it : vec) {
        cout << it << " ";
    }
    return 0;
}