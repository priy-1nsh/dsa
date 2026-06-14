#include <bits/stdc++.h>
using namespace std;

double pow(double x, int n) {
    long num = n;
    double ans = 1;
    if (num < 0) {
        x = 1 / x;
        num = -1 * num;
    }
    while (num > 0) {
        if (num % 2 == 1) {
            // n is odd
            num = num - 1;
            ans = ans * x;
        } else {
            // n is even
            x = x * x;
            num = num / 2;
        }
    }
    return ans;
}

int main() { return 0; }