#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr) {
    int n = arr.size();
    // 1. Moore's Voting
    int count = 1;
    int el = arr[0];
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            count = 1;
            el = arr[i];
        }
        else if (arr[i] == el) count++;
        else count--;
    }
    
    // 2. Verify if the highest voted element is the majority element
    int countOfEl = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el) countOfEl++;
    }
    if (countOfEl > n/2) return el;
    return -1; // if no majority element exists
}

int main() {
    return 0;
}