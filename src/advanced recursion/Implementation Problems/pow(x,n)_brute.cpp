#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long num = n;
    double ans = 1;
    if (num < 0) {
        x = 1 / x;
        num = -1 * num;
    }
    for (int i = 1; i <= num; i++) {
        ans *= x;
    }
    return ans;
}

// TC :- O(N) - gives TLE

int main() {
    return 0;
}