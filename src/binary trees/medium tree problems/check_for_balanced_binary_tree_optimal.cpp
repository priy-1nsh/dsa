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
    int findHeightModified(TreeNode* node) {
        if (node == NULL) return 0;

        int lh = findHeightModified(node->left);
        int rh = findHeightModified(node->right);

        // the next two lines make all the difference, changing the function into whether returning only two sort of integer values so that it behaves as a boolean function.
        if (lh == -1 || rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    // if this function returns -1, then it it is unbalanced, and if it is balanced. it will return the height of the BT.
public:
    bool isBalanced(TreeNode* root) {
        return findHeightModified(root) != -1;
        // if not -1, it will give true, else it will give false.
    }
};