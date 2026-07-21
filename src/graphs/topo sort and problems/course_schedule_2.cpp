class Solution {
   public:
    vector<int> findOrder(int V, vector<vector<int>>& prereq) {
        // let's do course schedule 2
        // return a topological ordering
        // using kahns algorithm

        // first let's build the adjacency list
        vector<vector<int>> adj(V);  // 0-based graph
        int n = prereq.size();
        for (int i = 0; i < n; i++) {
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }

        // now, we apply kahn's algorithm to find the linear ordering
        // 1. make the indegree array
        vector<int> indegree(V);
        for (int i = 0; i < V; i++) {
            // nodes are 0-indexed
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // 2. insert all the nodes with indegree 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. apply bfs - take out the front of the queue, subtract the indegree
        // from it's neighbours and put vertices with indegree = 0 into the
        // queue
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if (topo.size() != V) return {};
        return topo;
    }
};