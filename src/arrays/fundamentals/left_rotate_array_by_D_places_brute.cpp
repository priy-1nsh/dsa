#include <bits/stdc++.h>
using namespace std;

void leftRotateByDPlaces(vector<int>& arr, int n, int d) {
    d = d % n;
    vector<int> temp;
    for (int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

int main() {
    vector<int> arr = {3, 4, 7, 10, 8, 78, 45, 66, 23, 34, 12};
    leftRotateByDPlaces(arr, arr.size(), 3);
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}