#include <bits/stdc++.h>
using namespace std;

void powerSet(int index, vector<int>& arr, int n, vector<vector<int>>& ans,
              vector<int>& temp) {
    if (index == n) {
        ans.push_back(temp);
        return;
    }

    // take
    temp.push_back(arr[index]);
    powerSet(index + 1, arr, n, ans, temp);
    temp.pop_back();

    // not take
    powerSet(index + 1, arr, n, ans, temp);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> temp;
    powerSet(0, arr, n, ans, temp);
    // print the ans
    for (auto it : ans) {
        for (auto jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}