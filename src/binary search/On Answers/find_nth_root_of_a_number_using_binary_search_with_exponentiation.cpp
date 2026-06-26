#include <bits/stdc++.h>
using namespace std;

long long f(int m, int n) {
    // find m to the power n
    if (n == 0) return 1;

    if (n % 2 == 0) {
        return f(m*m, n/2);
    }
    return m * f(m, n - 1);
}

int findNthRoot(int M, int N) {
    // Nth root of M
    int l = 1, h = M;
    while (l <= h) {
        long long m = (l+h) / 2;
        if (f(m, N) == M) return m;
        else if (f(m, N) < M) l = m + 1;
        else h = m - 1;
    }
    return -1;
}

int main() {

    return 0;
}