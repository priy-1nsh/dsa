#include <bits/stdc++.h>
using namespace std;

bool prime(int i, int num) {
    if (i * i > num) return true;
    if (num % i == 0) return false;
    return prime(i + 1, num);
}

bool checkPrime(int num) {
    if (num <= 1) return true;
    return prime(2, num);
}

int main() {
    int num = 31;
    cout << checkPrime(num);
    return 0;
}