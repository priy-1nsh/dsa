#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string largestOddNumber(string& str) {
        int N = str.length();
        int i, j;
        // from start, the first non-zero number
        for (i = 0; i < N; i++) {
            if (str[i] != '0') break;
        }
        if (i == N - 1) {
            // only one non-zero number in the whole string
            // check if it's odd or not
            if ((str[i] - '0') % 2 == 1) {
                return str.substr(N - 1);    
            } else
                return "";
        }

        // find the first odd digit from the end
        for (j = N - 1; j >= 0; j--) {
            if ((str[j] - '0') % 2 == 1) break;
        }
        // now, j is the first odd digit from the end
        return str.substr(i, j - i + 1);
    }
};
int main() {
    string str = "00000004";
    Solution sol;
    cout << sol.largestOddNumber(str);
    return 0;
}