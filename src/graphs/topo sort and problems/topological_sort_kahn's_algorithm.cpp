vector<int> kahnsAlgo(int V, vector<int>adj[]) {
    // given is the adj list
    queue<int> q;
    vector<int> indegree(V, 0); // 0-based indexing

    // 1. calculate indegree first of all the nodes
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    // 2. find all those nodes whose indgree is 0 and push them into the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // 3. apply bfs - keep adding all the nodes with indegree = 0 into the ans array and keep subtracting the indegrees from their neighbours
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            // it is the neighbour of node
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return topo;
}