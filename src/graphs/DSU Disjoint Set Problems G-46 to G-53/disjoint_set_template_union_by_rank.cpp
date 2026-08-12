#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

   public:
    DisjointSet(int n) {
        // 1-based graph
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        // find ultimate parent of u
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        // connect u and v
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;  // same ultimate parents - nothing to update

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            // no change in rank as attaching smaller height to the larger
            // height
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            // connect anyone to anyone as the ranks/heights are same -> have to
            // increase the rank anyhow
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

// pass by refernece if you don't wanna loose out on the amortized changes in
// the disjoint set everytime you call this function
bool checkIfSameParent(DisjointSet& ds, int u, int v) {
    // check if u and v have the same ultimate parents
    if (ds.findUPar(u) == ds.findUPar(v))
        return true;
    else
        return false;
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    DisjointSet ds(7);  // 1 to 7 nodes
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);

    // check if 1 and 4 belong to the same component
    if (checkIfSameParent(ds, 1, 4))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    ds.unionByRank(5, 6);
    ds.unionByRank(3, 7);

    if (checkIfSameParent(ds, 1, 4))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}