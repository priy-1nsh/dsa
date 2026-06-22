#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int index, vector<int>& arr, int n, vector<int>& temp,
                       int k, int sum, vector<vector<int>>& container) {
    if (sum == k) {
        container.push_back(temp);
        return;
    }
    if (index == n) return;

    // pick
    sum += arr[index];
    temp.push_back(arr[index]);
    printSubsequences(index + 1, arr, n, temp, k, sum, container);
    // backtrack
    sum -= arr[index];
    temp.pop_back();

    // not take
    printSubsequences(index + 1, arr, n, temp, k, sum, container);
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