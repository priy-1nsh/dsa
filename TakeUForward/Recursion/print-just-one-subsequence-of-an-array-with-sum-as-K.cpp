#include <bits/stdc++.h>
using namespace std;

bool printS(int ind, vector<int>& ds, int s, int sum, int n, int arr[]) {
    // base case
    if (ind == n) {
        if (s == sum) {
            // print the subsequence and return true;
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else return false;
    }

    // pick the current index
    ds.push_back(arr[ind]);
    s += arr[ind];
    // call the next recursion for the next index
    if (printS(ind + 1, ds, s, sum, n, arr) == true) {
        return true; // to stop the further lines and recursion calls to execute
    }
    // back to the previous state of not picking the current index
    s -= arr[ind];
    ds.pop_back();

    // not pick the current index and call the next recursion call
    if (printS(ind + 1, ds, s, sum, n, arr) == true) return true;

    return false; // executes when the recursion for the current index doesn't yield any
    // subsequence with s == sum
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 5;
    int s = 0;
    vector<int> ds;
    int ind = 0;
    if (printS(ind, ds, s, sum, n, arr) == true)
        cout << "There exists atleast one subsequence.";
    else
        cout << "There doesn't exist any subsequence.";
    
    return 0;
}