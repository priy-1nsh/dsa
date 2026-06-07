#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& arr) {
    int largest = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) largest = arr[i];
    }
    return largest;
}

int main() {
    vector<int> v = {2, 3, 7, 8, 19};
    cout << largestElement(v);
    return 0;
}