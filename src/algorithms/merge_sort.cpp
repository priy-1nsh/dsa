#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void merge(int low, int mid, int high, vector<int>& arr) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else if (arr[right] < arr[left]) {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        // dump into the arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

   public:
    void mergeSort(int low, int high, vector<int>& arr) {
        if (low == high)  // low >= high is more robust but not necesssary cuz
                          // low > high can never occur
            return;       // just one element in the array - already sorted
        int mid = (low + high) / 2;
        // smaller bigger
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
};

int main() {
    Solution sol;
    vector<int> vec = {2, 4, 7, 19, 9, 7, 24, 16};
    sol.mergeSort(0, vec.size() - 1, vec);
    for (auto it : vec) {
        cout << it << " ";
    }
    return 0;
}