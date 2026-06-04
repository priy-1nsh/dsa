#include <iostream>
using namespace std;

class Solution {
   public:
    void pattern6(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                cout << j;
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 5;
    Solution sol;
    sol.pattern6(n);
    return 0;
}