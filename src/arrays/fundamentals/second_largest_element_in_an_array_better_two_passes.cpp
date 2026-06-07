#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {
    int largest = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) largest = arr[i];
    }
    // we have got the largest
    int sLargest = INT_MIN;  // if arr contains negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > sLargest && arr[i] != largest) {
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int main() {
    vector<int> arr = {1, 2, 5, 6, 7, 9, 10, 87, 56, 1245};
    cout << secondLargest(arr);
    return 0;
}