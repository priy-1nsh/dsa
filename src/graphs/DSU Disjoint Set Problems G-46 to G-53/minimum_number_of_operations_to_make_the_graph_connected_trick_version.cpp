class DisjointSet {
    vector<int> parent, size;
    int components;

   public:
    DisjointSet(int V) : components(V) {
        parent.resize(V + 1);
        size.resize(V + 1, 1);
        for (int i = 0; i < V + 1; i++) parent[i] = i;
    }

    int findUPar(int node) {
        // let's find the ultimate parent
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;
        components--;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getComponents() { return components; }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        int m = edges.size();  // number of edges
        if (m < n - 1) return -1;

        DisjointSet dsu(n);
        for (int i = 0; i < m; i++) {
            auto it = edges[i];
            dsu.unionBySize(it[0], it[1]);
        }

        return dsu.getComponents() - 1;
    }
};

// TC - O(m)
// SC - O(2n) for parent and size arrays