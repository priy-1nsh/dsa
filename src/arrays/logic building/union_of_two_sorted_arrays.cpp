#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> unionArray;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            // this driver code is important and repeated :-
            if (unionArray.size() == 0 || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
            // uncomment it
        } else {
            // arr1[i] > arr2[j]
            if (unionArray.size() == 0 || unionArray.back() != arr2[j]) {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n1) {
        if (unionArray.size() == 0 || unionArray.back() != arr1[i]) {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }
    while (j < n2) {
        if (unionArray.size() == 0 || unionArray.back() != arr2[j]) {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    return unionArray;
}

int main() {
    vector<int> arr1 = {3, 4, 6, 7, 9, 9};
    vector<int> arr2 = {1, 5, 7, 8, 8};
    vector<int> result = unionArray(arr1, arr2);
    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}