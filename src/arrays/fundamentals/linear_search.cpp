#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> v = {2, 3, 7, 8, 19};
    int target = 3;
    cout << linearSearch(v, target);
    return 0;
}