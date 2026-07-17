/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   private:
    void dfs(TreeNode* node, vector<int>& path, vector<int>& maxPath,
             int maxDepth) {
        if (node == nullptr) return;
        // else not null
        path.push_back(node->val);

        // if leaf node
        if (node->left == NULL && node->right == NULL) {
            if ((int)path.size() > maxDepth) {
                maxDepth = path.size();
                maxPath = path;
            }
            path.pop_back();
            return;
        }

        // call left recurse
        dfs(node->left, path, maxPath, maxDepth);
        dfs(node->right, path, maxPath, maxDepth);

        // once done - backtrack
        path.pop_back();
        // return
    }

   public:
    int maxDepth(TreeNode* root) {
        // call the dfs with root as node and empty vectors as path and maxPath
        // and maxDepth as 0
    }
};