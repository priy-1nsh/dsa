class DisjointSet {
    vector<int> parent, size;

   public:
    DisjointSet(int V) {
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
    int makeConnected(int n, vector<vector<int>>& edges) {
        // ans = number of components - 1
        // if (findUPar(u) == findUPar(v)) extraedges++;
        // if (extraedges >= ans) return ans;
        // else return -1

        // nodes are 0 to n-1
        int m = edges.size();
        DisjointSet dsu(n);
        int extraEdges = 0;
        for (int i = 0; i < m; i++) {
            auto it = edges[i];
            // it[0] and it[1] are the nodes between which edge is present
            if (dsu.findUPar(it[0]) == dsu.findUPar(it[1]))
                extraEdges++;
            else {
                // do their union
                dsu.unionBySize(it[0], it[1]);
            }
        }

        // connected the graph and found the extraEdges as well
        // now count the number of components
        int cntComp = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findUPar(i) == i) cntComp++;
        }

        if (extraEdges >= cntComp - 1) return cntComp - 1;
        return -1;
    }
};

// TC - O(m) + O(n)
// SC - O(2n)