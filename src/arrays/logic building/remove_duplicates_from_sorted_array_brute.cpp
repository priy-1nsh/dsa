#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
        // will only insert the unique elements of the array arr
    }
    // now fill the array arr with the set elements
    int index = 0;
    for (auto it : st) {
        arr[index] = it;
        index++;
    }
    return index;
}

int main() {
    vector<int> vec = {0, 0, 3, 3, 5, 6};
    int ans = removeDuplicates(vec);
    cout << ans << endl;
    for (int i = 0; i <= ans - 1; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}