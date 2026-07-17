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
   public:
    int maxLoot(TreeNode* node, unordered_map<TreeNode*, int>& dp) {
        if (node == nullptr) return 0;
        auto it = dp.find(node);
        if (it != dp.end()) {
            // i have found it
            return dp[node];
        }

        // pick
        int pick = node->val;
        if (node->left)
            pick +=
                maxLoot(node->left->left, dp) + maxLoot(node->left->right, dp);
        if (node->right)
            pick += maxLoot(node->right->left, dp) +
                    maxLoot(node->right->right, dp);

        // not pick
        int notPick =
            0 + maxLoot(node->left, dp) +
            maxLoot(node->right,
                    dp);  // it's not like we can go either to the left of node
                          // or to the right of the node, we can go and select
                          // both the node->left as well as node->right, hence
                          // we add it, not like taking it individually and
                          // selecting only the max out of them.

        return dp[node] = max(pick, notPick);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return maxLoot(root, dp);
    }
};