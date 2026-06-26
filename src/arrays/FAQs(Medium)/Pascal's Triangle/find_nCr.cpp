#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    int res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1);
        res = res / (i);
    }
    return res;
}

int main() {
    int n = 5, r = 2;
    cout << nCr(n, r);
    return 0;
}