#include <bits/stdc++.h>
using namespace std;

int printS(int ind, int s, int sum, int n, int arr[]) {
    // base case
    // condition satisfied - return 1
    if (ind == n) {
        if (s == sum) {
            return 1;
        }
        // condition not satisfied - return 0
        else
            return 0;
    }

    // pick
    s += arr[ind];
    int l = printS(ind + 1, s, sum, n, arr);

    // not pick
    s -= arr[ind];
    int r = printS(ind + 1, s, sum, n, arr);

    return (l + r);
}

int main() {
    // find the number of subsequnces with sum as K
    int arr[] = {1, 2, 1};
    int n = 3;
    int ind = 0;
    int sum = 3;  // [1, 2] and [2, 1]
    int s = 0;
    cout << printS(ind, s, sum, n, arr) << endl;
    return 0;
}