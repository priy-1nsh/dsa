#include <iostream>
using namespace std;

int main() {
    int N = 5;
    int top = 0, left = 0, right = 0, bottom = 0;
    for (int i = 0; i <= 2 * N - 2; i++) {
        for (int j = 0; j <= 2 * N - 2; j++) {
            top = i;
            left = j;
            right = 2 * N - 2 - j;
            bottom = 2 * N - 2 - i;
            cout << N - min(min(top, left), min(right, bottom));
        }
        cout << endl;
    }
    return 0;
}