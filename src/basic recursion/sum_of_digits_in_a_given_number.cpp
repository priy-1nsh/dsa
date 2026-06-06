#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int sumNum(int num) {
        // int sum = 0;
        // while (num > 0) {
        //     sum = sum + (num % 10);
        //     num = num / 10;
        // }
        // return sum;

        // recursive approach
        if (num == 0) return 0;
        return (num % 10) + sumNum(num / 10);
    }

   public:
    // sum of digits in a given number until just one digit remains
    int sumOfDigits(int num) {
        if (num < 10) return num;
        num = sumNum(num);
        return sumOfDigits(num);
    }
};

int main() {
    int num = 529;
    Solution sol;
    cout << sol.sumOfDigits(num);
    return 0;
}