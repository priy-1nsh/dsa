#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void reverseS(int l, int r, vector<char>& str) {
        if (l >= r) return;
        swap(str[l], str[r]);
        reverseS(l + 1, r - 1, str);
    }

   public:
    vector<char> reverseString(vector<char>& str) {
        int n = str.size();
        reverseS(0, n - 1, str);
        return str;
    }
};

int main() {
    vector<char> s = {'t', 'h', 'i', 'n', 'g', 's'};
    Solution sol;
    vector<char> ans = sol.reverseString(s);
    for (auto it : ans) {
        cout << it;
    }
    return 0;
}

// TC - O(N/2)
// SC - O(N/2) + O(Ns)