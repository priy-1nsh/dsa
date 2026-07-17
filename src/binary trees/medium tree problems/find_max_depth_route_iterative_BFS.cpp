class Solution {
   public:
    vector<int> maxDepth(TreeNode* root) {
        vector<int> path;
        if (root == NULL) return path;

        // BFS - track the last node and also track the parent of each node
        unordered_map<TreeNode*, TreeNode*> parent;

        parent[root] = nullptr;  // nullptr acts as false

        // also track the last node
        TreeNode* lastNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                lastNode = node;
                q.pop();
                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        for (TreeNode* curr = lastNode; curr; curr = parent[curr]) {
            path.push_back(curr->val);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};