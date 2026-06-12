#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 3, 3};
    vector<int> b = {2, 3, 3, 4, 5, 7};
    vector<int> result = intersection(a, b);
    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}