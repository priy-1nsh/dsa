// V = number of vertices or nodes
// adj = adjacency list of graph, each index is home to a list of neighbours of
// the node represented by the index of the adj list
vector<int> bfsOfGraph(
    int V, vector<int> adj[]) {  // adj automatically passed by reference
    vector<int> vis(V, 0);
    vis[0] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    bfs.push_back(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node] {
            if (!vis[it]) {
                // if not yet visited
                vis[node] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

// SC - O(3N)
// TC - O(N * 2E)