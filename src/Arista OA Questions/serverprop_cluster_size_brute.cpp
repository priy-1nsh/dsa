#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(in start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        int count = 0;
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return count;
    }
    vector<int> findClusterSize(vector<int>& serverProp) {
        int n = serverProp.size();
        vector<int> ans;
        ans.reserve(n);

        // first you can make the adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int i = 0; i < n; i++) {
                if (gcd(i, j) > 1) {
                    // connect i and j
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // now we try to find the number of components at each index
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            ans[i] = bfs(i, adj, vis);
        }

        return ans;
    }
};

int main() {
    return 0;
}