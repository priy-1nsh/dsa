#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> arr) {
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n-1; i >= 0; i--s) {
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}