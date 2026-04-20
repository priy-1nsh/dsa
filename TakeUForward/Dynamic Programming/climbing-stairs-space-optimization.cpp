#include <bits/stdc++.h>
using namespace std;

// use tabulation solution to arrive at space optimization solution

int climbingStairs(int ind) {
    int prev2 = 1;
    int prev = 1;
    int curr_i;
    for (int i = 2; i <= ind; i++) {
        curr_i = prev + prev2;
        prev2 = prev;
        prev = curr_i;
    }

    return curr_i;
}

int main() {
    int n = 5;
    cout << climbingStairs(n);
    return 0;
}

// TC -> O(N)
// SC -> O(1)