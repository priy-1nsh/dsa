#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

   public:
    DisjointSet(int V) {
        parent.resize(V + 1);
        size.resize(V + 1, 1);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUPar(parent[u]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class solution {
   public:
    long long getMinCost(vector<int>& x, vector<int>& y) {
        // Write your code here...
        // let's make the adjacency list
        int V = x.size();
        vector<vector<pair<int, int>>> adj(V);  // 0-based
        for (int i = 0; i < V; i++) {
            // (x[i], y[i]) is the node
            for (int j = 0; j < V; j++) {
                // (x[j], y[j]) is the neighbour node
                if (i == j) continue;
                int wt = min(abs(x[i] - x[j]), abs(y[i] - y[j]));
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
                // bidirectional
            }
        }

        // adj list made
        // now, we try to find the minimum spanning tree
        // using kruskal's algorithm
        long long minWt = 0;
        DisjointSet ds(V);
        for (int i = 0; i < V; i++) {
            // i is the node
            for (auto it : adj[i]) {
                // adj[i] is the vector of pair<neighbour, weight>
                //  auto [neighbour, wt] = it;
                int neighbour = it.first;
                int wt = it.second;
                // now i and neighbour are neighbours with edge weight as wt
                if (ds.findUPar(i) != ds.findUPar(neighbour)) {
                    minWt += wt;
                    ds.unionBySize(i, neighbour);
                }
            }
        }
        return minWt;
    }
};