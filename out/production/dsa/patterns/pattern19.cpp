#include <iostream>
using namespace std;

class Solution {
   public:
    void upper(int N) {
        for (int i = 1; i <= N; i++) {
            // stars
            for (int j = 1; j <= N - i + 1; j++) {
                cout << "*";
            }
            for (int j = 1; j <= 2 * (i - 1); j++) {
                cout << " ";
            }
            for (int j = N - i + 1; j >= 1; j--) {
                cout << "*";
            }
            cout << endl;
        }
    }
    void lower(int N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                cout << "*";
            }
            for (int j = 1; j <= 2 * N - 2 * i; j++) {
                cout << " ";
            }
            for (int j = 1; j <= i; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution sol;
    sol.upper(5);
    sol.lower(5);
    return 0;
}