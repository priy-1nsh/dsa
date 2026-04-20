#include <bits/stdc++.h>
using namespace std;

// ds is the data structure to carry the subsequences
void printSubsequence(int ind, vector<int>& ds, int arr[], int n) {
    // base case
    if (ind == n) {
        // print
        for (auto it : ds) {
            cout << it << " ";
        }
        if (ds.size() == 0) cout << "{}";  // to print the NULL
        cout << endl;
        return;
    }

    // pick the element
    ds.push_back(arr[ind]);
    printSubsequence(ind + 1, ds, arr, n);
    ds.pop_back();

    // don't pick the element
    printSubsequence(ind + 1, ds, arr, n);
}

int main() {
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printSubsequence(0, ds, arr, n);

    return 0;
}