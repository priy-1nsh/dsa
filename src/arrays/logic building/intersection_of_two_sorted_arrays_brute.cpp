#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    int visSize = n1 > n2 ? n2 : n1;
    vector<int> vis(visSize, 0);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr[i] == arr[j] && vis[j] == 0) {
                ans.push_back(arr[i]);
                break;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}