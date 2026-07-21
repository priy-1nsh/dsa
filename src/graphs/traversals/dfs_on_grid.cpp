// let's assume the neighbours on the grid are on the left right bottom and top
void dfs(int startRow, int startCol, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    int n = grid.size();
    int m = grid[0].size();
    // vis the startRow and startCol
    vis[startRow, startCol] = 1;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        // go to all the neighbours and call dfs on them
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1 /*whatever is the condition on each cell*/) {
            // call dfs on it
            dfs(nrow, ncol, grid. vis);
        }
    }
}