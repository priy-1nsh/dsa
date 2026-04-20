#include <bits/stdc++.h>
using namespace std;

void printS(vector<int>& ds, int ind, int s, int arr[], int sum, int n) {
    if (ind == n) {
        if (s == sum) {
            // print the subsequence
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        // stop recursion
        return;
    }

    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ds, ind + 1, s, arr, sum, n);

    ds.pop_back();
    s -= arr[ind];

    // not pick
    printS(ds, ind + 1, s, arr, sum, n);
}

int main() {
    int arr[] = {1, 2, 1};
    int sum = 3;
    int n = 3;
    vector<int> ds;
    int ind = 0;
    int s = 0;
    printS(ds, ind, s, arr, sum, n);

    return 0;
}