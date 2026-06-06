#include <bits/stdc++.h>
using namespace std;

int checkPrimeWheelFactorisation(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    // only check factors of the form 6k+1 and 6k-1
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int N = 31;
    cout << checkPrimeWheelFactorisation(N);
    return 0;
}