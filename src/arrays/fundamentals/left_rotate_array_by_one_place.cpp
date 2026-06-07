#include <bits/stdc++.h>
using namespace std;

void leftRotateByOne(vector<int>& arr, int n) {
    int temp = arr[0];
    for (int i = 0; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main() {
    vector<int> arr = {1, 2, 5, 6, 7, 9, 10, 87, 56, 1245};
    leftRotateByOne(arr, arr.size());
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}