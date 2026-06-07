#include <bits/stdc++.h>
using namespace std;

int maximumConsecutiveOnes(vector<int> arr, int n) {
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1)
            count++;
        else if (arr[i] == 0)
            count = 0;
        if (count > maxCount) maxCount = count;
    }
    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0};
    cout << maximumConsecutiveOnes(nums, nums.size());
    return 0;
}