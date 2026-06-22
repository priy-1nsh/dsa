class Solution {
   private:
    void combSum2(int index, vector<int>& arr, int n, vector<int>& temp,
                  vector<vector<int>>& ans, int sum) {
        // base case
        if (sum == 0) {
            ans.push_back(temp);
            return;
        }
        if (index == n) return;
        if (sum < 0) return;

        // take
        temp.push_back(arr[index]);
        combSum2(index + 1, arr, n, temp, ans, sum - arr[index]);
        temp.pop_back();

        // not take
        int i = index;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] != arr[index]) {
                // j is the new index
                combSum2(j, arr, n, temp, ans, sum);
                break;
            }
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // your code goes here
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combSum2(0, candidates, candidates.size(), temp, ans, target);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};