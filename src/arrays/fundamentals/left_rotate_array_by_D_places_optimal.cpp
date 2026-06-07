#include <bits/stdc++.h>
using namespace std;

void leftRotateByDPlaces(vector<int>& arr, int n, int d) {
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.begin() + n);
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {3, 4, 7, 10, 8, 78, 45, 66, 23, 34, 12};
    leftRotateByDPlaces(arr, arr.size(), 3);
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}