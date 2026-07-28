// Important : Kahn's algo separates the grapg into two set of nodes -
// 1. popped : no cycle can reach me
// 2. lwftover : i lie on a cycle or a cycle reach me'

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> indegree(V, 0);
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[i]++;
                revAdj[it].push_back(i);
            }
        }

        // revAdj is the reverse adjacency list
        // now we apply bfs topo sort (kahns) on the revAdj
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // now we apply the bfs
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : revAdj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo; // same as set of all safe nodes which do not lead to or lie on cycles
    }
};