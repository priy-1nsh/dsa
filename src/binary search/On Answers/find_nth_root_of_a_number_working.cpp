#include <bits/stdc++.h>
using namespace std;

// return 1, if mid^n == m
// return 2, if mid^n > m
// return 0, if mid^n < m
int f(int mid, int n, int m) {
    long long ans = 1; // as mid^n can become very large
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int M, int N) {
    // Nth root of M
    int l = 1, h = M;
    while (l <= h) {
        long long m = (l+h) / 2;
        if (f(m, N, M) == 1) return m;
        else if (f(m, N) == 0) l = m + 1;
        else h = m - 1;
    }
    return -1;
}

int main() {

    return 0;
}