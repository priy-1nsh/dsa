#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int>& arr) {
    int n = arr.size();
    set<vector<int>> ansSet;
    
    // brute force
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

int main() {
    return 0;
}