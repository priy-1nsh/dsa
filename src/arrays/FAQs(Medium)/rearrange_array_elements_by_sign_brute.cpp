#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayBySign(vector<int>& arr) {
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for (auto it : arr) {
        if (it < 0) neg.push_back(it);
        else pos.push_back(it);
    }
    for (int i = 0; i < n; i++) {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    return arr;
}

int main() {
    return 0;
}