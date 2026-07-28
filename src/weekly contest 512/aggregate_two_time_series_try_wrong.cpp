class Solution {
   public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& arr1,
                                            vector<vector<int>>& arr2) {
        queue<pair<int, int>> q;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (arr1[i][0] < arr2[j][0]) {
                pair<int, int> p;
                p.first = arr1[i][0];
                p.second = arr1[i][1];
                q.push(p);
                i++;
            }

            else {
                pair<int, int> p;
                p.first = arr2[j][0];
                p.second = arr2[j][1];
                q.push(p);
                j++;
            }
        }
        while (i < n1) {
            pair<int, int> p;
            p.first = arr1[i][0];
            p.second = arr1[i][1];
            q.push(p);
            i++;
        }
        while (j < n2) {
            pair<int, int> p;
            p.first = arr2[j][0];
            p.second = arr2[j][1];
            q.push(p);
            j++;
        }

        int n = q.size();

        vector<vector<int>> ans;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            int timestamp = p.first;
            int value = p.second;
            q.pop();
            if (q.empty())
                ans.push_back({timestamp, value});
            else if (timestamp == q.front().first) {
                ans.push_back({timestamp, value + q.front().second});
                q.pop();
            } else
                ans.push_back({timestamp, value + q.front().second});
        }

        int m = ans.size();
        // remove m/2 elements from the start of the ans

        return ans;
    }
};