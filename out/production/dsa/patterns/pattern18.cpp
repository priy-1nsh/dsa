#include <iostream>
using namespace std;

int main() {
    int N = 5;
    for (int i = 1; i <= N; i++) {
        char start = 'A' + N - i;
        for (int j = 1; j <= i; j++) {
            cout << start;
            start++;
        }
        cout << endl;
    }
    return 0;
}