class Solution{
public:
    void dfs(int node, stack<int>& st, vector<int>& vis, vector<int>adj[]) {
        // visit the node
        vis[node] = 1;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, st, vis, adj);
            }
        }
        // deepest node bfs ended - add it to the stack
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[]){
        // let's do topo sort
        vector<int> vis(V, 0); // 0-based graph
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, st, vis, adj);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
