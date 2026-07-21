void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
    if (!vis[node]) {
        // not yet visited
        vis[node] = 1;
        ans.push_back(node);
    }
    else return;

    // traverse all the neighbours of node
    for (auto it : adj[node]) {
        if (!vis[it]) {
            // not yet visited
            dfs(it, adj, vis, ans);
        }
    }
} 

vector<int> dfs(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V, 0); // assuming the indexing is 0-based
    int start = 0; // starting node
    dfs(start, adj, vis, ans);
    return ans;
}