#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    // edge case : what if n is negative
    if (n < 0) {
        return myPow(1/x, -n);
    }
    // base case
    if (n == 0) return 1;
    if (n % 2 == 1) {
        // odd
        return x * myPow(x, n - 1);
    }
    return myPow(x*x, n / 2);
}

int main() {
    return 0;
}