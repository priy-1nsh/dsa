class Solution {
   public:
    // first get the edjacency list from the edges list
    vector<vector<int>> getAdjacencyList(int V, vector<vector<int>> edges) {
        int m = edges.size();  // no. of edges
        vector<vector<int>> adj(V);
        for (int i = 0; i < m; i++) {
            // edges[i] = ith edge
            // edges[i][0] = u and edges[i][1] = v
            // undirected graph has edge between u and v
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return adj;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& ans) {
        if (!vis[node]) {
            // not yet visited
            vis[node] = 1;
            ans.push_back(node);
        } else
            return;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                // not yet visited
                dfs(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj = getAdjacencyList(V, edges);
        vector<int> vis(V, 0);
        int start = 0;
        vector<int> ans;
        dfs(start, adj, vis, ans);
        return ans;
    }

    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        // 0-based graph -> vis[V]
        vector<vector<int>> adj = getAdjacencyList(V, edges);
        vector<int> vis(V, 0);
        vector<int> ls;
        queue<int> q;
        int start = 0;
        q.push(start);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ls.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ls;
    }
};
