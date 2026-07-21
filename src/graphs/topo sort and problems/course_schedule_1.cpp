class Solution {
   public:
    bool canFinish(int V, vector<vector<int>>& prereq) {
        // we will use topo sort, if the topo sort size doesn't match the V
        // (number of nodes), we will return false - there is a cycle at each i,
        // we have prereq[i] where a pair is stored [0][1] which indicates that
        // we have a directed edge from [1] to [0]. so first we make the
        // adjacency list
        vector<vector<int>> adj(V);
        int n = prereq.size();
        for (int i = 0; i < n; i++) {
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }

        // now we apply kahn's algo to the adj
        // 1. make the indegree
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // 2. now find the ones with indegree 0 and put into the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // 3. apply bfs and subtract the indegree by 1 from the neighbours of
        // the front node of the queue
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            // put into the topo sort array
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        // if the q gets empty without processing through all the nodes
        if (cnt != V) return false;
        return true;
    }
};