#include <iostream>
using namespace std;

int main() {
    int N = 5;
    for (int i = 1; i <= 2 * N - 1; i++) {
        int stars = 0;
        if (i > N)
            stars = 2 * N - i;
        else
            stars = i;
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}