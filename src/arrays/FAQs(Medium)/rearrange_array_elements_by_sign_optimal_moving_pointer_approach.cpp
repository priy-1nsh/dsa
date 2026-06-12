#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayElementsBySign(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    // positive elements need to be at the even index - 0 , 2 , 4 , etc
    // negative elements need to be at the odd index - 1 , 3 , 5 , etc
    int posInd = 0, negInd = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            ans[posInd] = arr[i];
            posInd+=2;
        }
        else {
            // arr[i] < 0
            ans[negInd] = arr[i];
            negInd+=2;
        }
    }
    return ans;
}

int main() {
    return 0;
}