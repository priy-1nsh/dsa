#include <iostream>
using namespace std;

int main() {
    int N = 5;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            cout << " ";
        }
        char ch = 'A' - 1;
        for (int j = 1; j <= 2 * i - 1; j++) {
                        if (j > i) {
                ch--;
            } else {
                ch++;
            }
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}