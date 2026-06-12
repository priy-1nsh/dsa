#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int>& arr) {
    int n = arr.size();
    // better : using hashset for finding the third element
    // still we need a set of vectors to only store unique vectors, which are themselves sorted
    set<vector<int>> ansSet;
    for (int i = 0; i < n; i++) {
        // start with an empty hashset to store all the elements between ith and jth element
        set<int> hashSet; // store elements between ith and jth element
        for (int j = i+1; j < n; j++) {
            int third = - (arr[i] + arr[j]);
            if (hashSet.find(third) != hashSet.end()) {
                // third element is present between the ith and jth element
                vector<int> temp = {arr[i], arr[j], third}; // make a triplet
                sort(temp.begin(), temp.end()); // sort them to only store unique triplets
                ansSet.insert(temp); // insert the triplet into the set, so that only the unique triplets are stored.
            }
            // whether you find the third on not, move j with storing the current element in the hashSet and then move
            hashSet.insert(arr[j]);
        }
    }
    
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

int main() {
    return 0;
}