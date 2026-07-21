class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();     // number of rows
        int m = grid[0].size();  // number of columns
        queue<pair<pair<int, int>, int>> q;
        int vis[12][12] = {0};
        int freshCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // rotten orange
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1)
                    freshCount++;
            }
        }

        int minTime = 0;
        int cnt = 0;
        int delr[] = {-1, 1, 0, 0};
        int delc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [rowCol, time] = q.front();
            q.pop();
            int row = rowCol.first;
            int col = rowCol.second;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    // orange is fresh and th orange besides is rotten
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                    minTime = time + 1;
                }
            }
        }
        if (cnt != freshCount) return -1;
        return minTime;
    }
};