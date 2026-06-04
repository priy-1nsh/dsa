#include <iostream>
using namespace std;

int main() {
    // pattern 11
    int N = 5;
    int start = 1;
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j < i; j++) {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
    return 0;
}