#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    // finding the leaders in the array
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int flag = 1;
        for (int j = i+1; j<n; j++) {
            if (arr[i] < arr[j]) flag = 0;
        }
        if (flag==1) ans.push_back(arr[i]);
    }
    ans.push_back(arr[n-1]);
    return ans;
}

int main() {

    return 0;
}