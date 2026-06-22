#include <bits/stdc++.h>
using namespace std;

// to print just one subsequence, we need to just a way to avoid further recursion calls, one we get any subsequence with sum == k
// To do this, we need a way to avoid further recursion calls
// Approach -

// base case :
// if (condition is satisfied) return true;
// else return false;

// take
// if (f() == true) return true; // no further calls will be done
// not take
// if (f() == true) return true;

// return false;
 
// Now, let's code it -

bool printSubsequences(int index, vector<int>& arr, int n, vector<int>& temp,
                       int k, int sum, vector<vector<int>>& container) {
    if (sum == k) {
        container.push_back(temp);
        return true;
    }
    if (index == n) return false;

    // pick
    sum += arr[index];
    temp.push_back(arr[index]);
    if(printSubsequences(index + 1, arr, n, temp, k, sum, container) == true) return true;
    // backtrack
    sum -= arr[index];
    temp.pop_back();

    // not take
    if(printSubsequences(index + 1, arr, n, temp, k, sum, container) == true) return true;

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int sum = 0;
    int k = 3;
    vector<int> temp;
    vector<vector<int>> container;
    printSubsequences(0, arr, n, temp, k, sum, container);
    for (auto it : container) {
        for (auto jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}