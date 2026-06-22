#include <bits/stdc++.h>
using namespace std;

// recursive implementation
int bs(vector<int>& arr, int low, int high) {
    if (low > high) return -1;
    int mid = (low+high) / 2;
    if (target == arr[mid]) return mid;
    else if (target < arr[mid]) return bs(arr, low, mid - 1);
    else return bs(arr, mid + 1, high); 
}

int main() {
    return 0;
}