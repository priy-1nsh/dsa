#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    // 2-pointer technique
    // Why ? When we are trying to find three numbers which add up to give target, keeping any one fixed, we would have to change the other two both
    for (int i = 0; i < n; i++) {
        // we also don't want to keep the ith element the same
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        // if j >= k then the sorted order of the triplet will be distorted
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > 0) {
                k--;
                // we don't want to keep either the jth element same or kth element the same since we checked them
                // impose a check
                while (k > j && arr[k] == arr[k+1]) k--;
            }
            else if (sum < 0) {
                j++;
                // impose a check to check if the jth elt reamins the same as previous
                while (j < k && arr[j] == arr[j-1]) j++;
            }
            else {
                // sum == 0
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j-1]) j++;
                while (k > j && arr[k] == arr[k+1]) k--;

            }
        }
    }
    return ans;
}

int main() {
    return 0;
}