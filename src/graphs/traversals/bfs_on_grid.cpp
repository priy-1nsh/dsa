// bfs on grids
// will return the visited grid array
vectorvector < int >>
    bfsOnGrid(vector<vector<int>>& grid, int startRow, int startCol) {
    int n = grid.size();     // number of rows
    int m = grid[0].size();  // number of columns

    queue<pair<int, int>> q;
    vector<vector<int>> vis(
        n, vector<int>(m, 0));  // visited grid with n rows and m columns where
                                // each column is 0

    vis[startRow][startCol] = 1;
    q.push({startRow, startCol});

    int delr[] = {-1, 1, 0, 0};  // up down left right
    int delc[] = {0, 0, -1, 1};  // up down left right

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 2 /*or whatever based on question */) {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
    return vis;  // showing which cells have been visited
}

// the above code for bfs in grid is for the time of the questions where each
// node in the group represents a node, that is, one node is represented by one
// cell, and not cells represent one node - that is - (i, j) and (j, i)
// represents two different nodes and each node is connected to the 4 nodes
// which are top, left, right, bottom to it.