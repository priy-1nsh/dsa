#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    // point j to the first 0th element
    // then point i to the non-zero element
    // swap them and move both by 1 place ahead
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        // no zeros
        return;
    }
    // there are zeros
    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() { return 0; }