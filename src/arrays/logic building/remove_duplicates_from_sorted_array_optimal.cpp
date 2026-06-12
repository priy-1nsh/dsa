#include <bits/stdc++.h>
using namespace std;

int removeDuplicates (vector<int>& arr) {
    int n = arr.size();
    int i = 0, j = 1;
    while (j < n) {
        if (arr[i] == arr[j]) j++;
        else {
            i = i + 1;
            arr[i] = arr[j];
            j++;
        }
    }
    return (i+1);
}

int main() {
    vector<int> vec = {-2, 2, 4, 4, 4, 4, 5, 5};
    int ans = removeDuplicates(vec);
    cout << ans << endl;
    for (int i = 0; i <= ans - 1; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}