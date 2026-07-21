// dfs on adjacency matrix
// u's neighbours are those for which grid[u][v] = 1
void dfsOnAdjMatrix(int u, vector<vector<int>>& matrix, vector<int>& vis) {
    // visit u
    vis[u] = 1;
    for (int v = 0; v < matrix.size(); v++) {
        if (matrix[u][v] == 1 && !vis[v]) {
            dfsOnAdjMatrix(v, matrix, vis);
        }
    }
}