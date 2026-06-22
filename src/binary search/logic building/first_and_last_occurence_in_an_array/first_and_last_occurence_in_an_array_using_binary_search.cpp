#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& arr, int n, int target) {
    int first = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low+high) / 2;
        if (arr[mid] == target) {
            first = mid;
            // for the first occurence, search in the left
            high = mid - 1;
        }
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1; 
    }
    return first;
}

int lastOccurence(vector<int>& arr, int n, int target) {
    int last = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low+high) / 2;
        if (arr[mid] == target) {
            last = mid;
            // last occurence
            low = mid + 1;
        }
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return last;
}

vector<int> firstAndLastOccurence(vector<int>& arr, int n, int target) {
    int first = firstOccurence(arr, n, target);
    if (first == -1) return {-1, -1};
    return {first, lastOccurence(arr, n, target)};
}

int main() {
    return 0;
}