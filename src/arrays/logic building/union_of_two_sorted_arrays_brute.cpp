#include <bits/stdc++.h>
using namespace std;

vector<int> unionSorted(vector<int> arr1, vector<int> arr2) {
    set<int> st;
    for (int i = 0; i < arr1.size(); i++) {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++) {
        st.insert(arr2[i]);
    }
    vector<int> ans;

    // no index concept in sets, hence use iterators for traversal
    for (auto it : st) {
        ans.push_back(it);
    }
    return ans;
}

int main() {
    vector<int> arr1 = {3, 4, 6, 7, 9, 9};
    vector<int> arr2 = {1, 5, 7, 8, 8};
    vector<int> result = unionSorted(arr1, arr2);
    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}