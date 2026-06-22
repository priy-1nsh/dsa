#include <bits/stdc++.h>
using namespace std;

int printSubsequences(int index, vector<int>& arr, int n, vector<int>& temp,
                       int k, int sum, vector<vector<int>>& container) {
    if (sum == k) {
        container.push_back(temp);
        return 1;
    }
    if (index == n) return 0;

    // pick
    sum += arr[index];
    temp.push_back(arr[index]);
    int l = printSubsequences(index + 1, arr, n, temp, k, sum, container);
    // backtrack
    sum -= arr[index];
    temp.pop_back();

    // not take
    int r = printSubsequences(index + 1, arr, n, temp, k, sum, container);

    return l+r;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int sum = 0;
    int k = 3;
    vector<int> temp;
    vector<vector<int>> container;
    int result = printSubsequences(0, arr, n, temp, k, sum, container);
    cout << result << endl;
    return 0;
}