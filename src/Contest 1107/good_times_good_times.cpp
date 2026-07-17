#include <bits/stdc++.h>
using namespace std;

// resubmit

bool isGood(long long x) {
    if (x == 0) return true;
    set<int> st;
    while (x > 0) {
        st.insert(x % 10);
        x = x / 10;
    }
    if (st.size() <= 2) return true;
    return false;
}

long long findY(long long x) {
    long long y = 0;
    for (int i = 2;; i++) {
        if (isGood(i) && isGood(i * x)) {
            y = i;
            break;
        }
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        long long y = findY(x);

        cout << y << "\n";
    }

    return 0;
}