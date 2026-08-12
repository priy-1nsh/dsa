#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

   public:
    DisjointSet(int V) {
        parent.resize(V + 1);
        size.resize(V + 1, 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
   public:
    int numProvinces(vector<vector<int>> adj) {
        // here adj list is given
        int n = adj.size();
        DisjointSet dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // it is connected to i
                if (i == j) continue;

                if (adj[i][j] == 1) {
                    dsu.unionBySize(i, j);
                    // no need for ds.unionBySize(j, i) since repeated edges get
                    // discarded by the dsu
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findUPar(i) == i) count++;
        }

        return count;
    }
};

int main() { return 0; }