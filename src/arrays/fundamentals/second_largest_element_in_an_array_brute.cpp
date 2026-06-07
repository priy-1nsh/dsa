#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int largest = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] != largest) return arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 5, 6, 7, 9, 10, 87, 56, 1245};
    cout << secondLargest(arr);
    return 0;
}