class Solution {
   public:
    int maxLoot(TreeNode* node) {
        if (node == nullptr) return 0;

        int pick = node->val;
        if (node->left)
            pick += maxLoot(node->left->left) + maxLoot(node->left->right);
        if (node->right)
            pick += maxLoot(node->right->left) + maxLoot(node->right->right);

        int notPick = maxLoot(node->left) + maxLoot(node->right);

        return max(pick, notPick);
    }

    int rob(TreeNode* root) { return maxLoot(root); }
};