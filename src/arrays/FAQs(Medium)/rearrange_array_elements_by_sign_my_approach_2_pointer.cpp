#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangedArrayBySign(vector<int>& arr) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < n) {
        // point i and j to the first positive and negative elements
        while (arr[i] < 0) i++;
        while (arr[j] > 0) j++;
        ans.push_back(arr[i]);
        ans.push_back(arr[j]);
        i++;
        j++;
    }
    return ans;
}

int main() {
    return 0;
}