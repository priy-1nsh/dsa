#include <bits/stdc++.h>
using namespace std;

// works only for the positive values
// int majorityElement(vector<int>& arr) {
//     int n = arr.size();
//     int sizeHash = *max_element(arr.begin(), arr.end());
//     vector<int> hash(sizeHash + 1, 0);
//     for (int i = 0; i < n; i++) {
//         hash[arr[i]]++;
//     }
//     int majorityEl = -1;
//     for (int i = 0; i < sizeHash + 1; i++) {
//         if (hash[i] > n/2) {
//             majorityEl = i;
//             break; // majority element is unique in the array
//         }
//     }
//     return majorityEl;
// }

// for negative value dealing
int majorityElement(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    for (int x : arr) {
         freq[x]++; 
    }
    for (auto& entry : freq) {
        if (entry.second > n / 2) return entry.first;
    }
    return -1;
}

int main() {
    vector<int> vec = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    cout << majorityElement(vec);
    return 0;
}