#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr, int n) {
    int largest = arr[0];
    int sLargest = -1;  // non-negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            sLargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > sLargest) {
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int secondSmallest(vector<int>& arr, int n) {
    // second smallest
    int smallest = arr[0];
    int sSmallest = INT_MAX;  // IMPORTANT
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest) {
            sSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && arr[i] < sSmallest) {
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}

int main() {
    vector<int> arr = {1, 2, 5, 6, 7, 9, 10, 87, 56, 1245};
    cout << secondLargest(arr, arr.size()) << endl;
    cout << secondSmallest(arr, arr.size());
    return 0;
}