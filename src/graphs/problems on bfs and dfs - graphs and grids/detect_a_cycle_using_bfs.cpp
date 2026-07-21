class Solution{
public:
    bool detect(int start, vector<int> adj[], vector<int>& vis) {
        // 0-based graph : vis[V] : 0 to V-1
        queue<pair<int, int>> q;
        q.push({start, -1});
        vis[start] = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front(); q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    // not yet visited
                    vis[it] = 1;
                    q.push({it, node}); // node is the parent of it
                }
                else if (vis[it] && it != parent) {
                    // visited but it (neighbour of node) is not the parent of node
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // 0 to V-1
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis) == true) return true;
            }
        }
        return false;
    }
};