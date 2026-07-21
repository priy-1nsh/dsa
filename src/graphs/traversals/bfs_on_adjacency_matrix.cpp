// bfs on adjacency matrix
void bfsOnAdjacencyMatrix(int start, vector<vector<int>>& matrix, vector<int>& vis) {
    queue<int> q;
    vis[start] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < matrix.size(); v++) {
            if (!vis[v] && matrix[u][v] == 1) {
                // v is not yet visited and v is the neighbour of u
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}