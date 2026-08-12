class Solution{
public:
    int bfs (int start, vector<vector<int>>& adj, vector<int>& vis) {
        // return 1 after completing one traversal
        int n = adj.size();
        queue<int> q;
        vis[start] = 1;
        q.push(start);
 
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (adj[node][v] == 1 && !vis[v] && v != node) {
                    // v is adjacent to node
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }

        return 1;
    }
    int numProvinces(vector<vector<int>> adj) {
        int n = adj.size();
        // n X n adjacency matrix is given
        int cnt = 0;
        vector<int> vis(n, 0); // visited array of size n+1 since 0-based graph

        // driver code to cover all the nodes/vertices
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // not yet visited, then visit it
                cnt += bfs(i, adj, vis);
            }
        }
        return cnt;
    }
};