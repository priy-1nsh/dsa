#include <bits/stdc++.h>
using namespace std;

// sum of array elements using recursion - functional recursion (which returns
// something)
int sumOfArrayElements(vector<int>& nums, int i) {
    int N = nums.size();
    if (i == N - 1) return 0;
    return nums[i] + sumOfArrayElements(nums, i + 1);
}

///////////////////////////// Another approach ////////////////////////////

int sumOfArrayElements2(vector<int>& nums) {
    if (nums.empty()) return 0;
    return nums.pop_back() + sumOfArrayElements2(nums);
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10, 12};
    cout << sumOfArrayElements2(arr, 0);
    return 0;
}
