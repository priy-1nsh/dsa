#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target) {
    int n = arr.size();
    
    // store {value, original_index} pairs
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({arr[i], i});
    
    sort(v.begin(), v.end());  // sort by value
    
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = v[left].first + v[right].first;
        if (sum == target) return {v[left].second, v[right].second};
        else if (sum > target) right--;
        else left++;
    }
    return {-1, -1};
}

int main() {
    return 0;
}