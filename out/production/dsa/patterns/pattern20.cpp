#include <iostream>
using namespace std;

int main() {
    int N = 5;
    for (int i = 1; i <= 2 * N - 1; i++) {
        int stars = 0;
        int spaces = 0;
        if (i <= N) {
            stars = i;
            spaces = 2 * N - 2 * i;
        } else {
            stars = 2 * N - i;
            spaces = 2 * i - 2 * N;
        }
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}