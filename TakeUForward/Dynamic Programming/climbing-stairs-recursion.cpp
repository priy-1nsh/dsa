#include <bits/stdc++.h>
using namespace std;

int climbingStairs(int ind) {
    // base case
    if (ind == 0) return 1;
    if (ind == 1) return 1;

    int left = climbingStairs(ind-1);
    int right = climbingStairs(ind-2);

    return left + right;
}

int main () {
    int n = 2;
    // no. of ways to go from 0th stair to the 5th stair
    cout << climbingStairs(n);
    return 0;
}