#include <bits/stdc++.h>
using namespace std;

// Ques - Find the sum of all the windows of constant length k

// Notice i - k is always the index of the element that just fell out of the window. That's the key pointer arithmetic here — there's no explicit left variable, but i - k is the left pointer.

void slidingWindowSum(const vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;

    // Main Idea : new_sum = old_sum - arr[left] + arr[right], so we first find the sum of the first window

    // find the sum of the initial window
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    cout << "Sum of window 1: " << sum << endl;

    for (int i = k; i < n; i++) {
        // update the sum : with moving the window
        sum -= arr[i-k];
        sum += arr[i];
        cout << "Sum of window " << i - k + 2 << ": " << sum << endl;
        // why i - k + 2 ? i-k just gives 0 for the first time, but it is the 2nd window
    }

}

int main() {
    vector<int> arr = {1, 3, 2, 6, 4, 8, 5};
    int k = 3;
    slidingWindowSum(arr, k);
    return 0;
}