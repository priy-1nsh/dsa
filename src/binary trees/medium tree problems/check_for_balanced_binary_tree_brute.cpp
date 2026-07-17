/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findHeight(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + max(findHeight(node->left), findHeight(node->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        if (abs(lh - rh) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};