#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int index = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1]) continue;
        else {
            arr[index] = arr[i];
            index++;
        }
    }
    return (index);
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