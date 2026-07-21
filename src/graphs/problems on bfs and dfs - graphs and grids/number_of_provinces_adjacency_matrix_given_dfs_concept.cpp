class Solution {
   private:
    void dfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        // visit the start node
        vis[start] = 1;

        for (auto it : adj[start]) {
            if (!vis[it]) {
                // not yet visited
                dfs(it, adj, vis);
            }
        }
    }

   public:
    int numberOfProvinces(vector<vector<int>> grid) {
        // first let's make the adjacency list from the adjacency matrix
        int n = grid.size();  // n = number of nodes
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);  // take n since 0-based
        // n empty lists in a list

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && i != j) {
                    // i and j are connected
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                groups++;
            }
        }
        return groups;
    }
};
