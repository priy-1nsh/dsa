#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void combSum2(int index, vector<int>& arr, int n, vector<int>& temp,
                  set<vector<int>>& ans, int sum) {
        // concept : take and move to the next index since i don't want
        // duplicates OR not take and move to the next to generate subsequences
        // n the order as that of the array we will sort before adding to the
        // answer array to avoid duplication

        // base case
        if (sum == 0) {
            vector<int> toInsert = temp;  // make a copy
            sort(toInsert.begin(), toInsert.end());
            ans.insert(toInsert);
            return;
        }
        if (sum < 0) return;
        if (index == n) return;

        // take and move
        temp.push_back(arr[index]);
        combSum2(index + 1, arr, n, temp, ans, sum - arr[index]);
        temp.pop_back();

        // not take and move
        combSum2(index + 1, arr, n, temp, ans, sum);
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // your code goes here
        set<vector<int>> ans;
        vector<int> temp;
        combSum2(0, candidates, candidates.size(), temp, ans, target);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c = {2, 1, 2, 7, 6, 1, 5};
    auto res = s.combinationSum2(c, 8);
    for (auto& v : res) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
    return 0;
}