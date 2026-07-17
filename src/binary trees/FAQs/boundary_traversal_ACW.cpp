/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    void leftBoundary(vector<int>& res, TreeNode* node) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL) {
            return;
        }

        res.push_back(node->val);
        leftBoundary(res, node->left);
        if (node->left == NULL) leftBoundary(res, node->right);
    }
    void leafNodes(vector<int>& res, TreeNode* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == NULL) {
            res.push_back(node->val);
            return;
        }

        // go left
        leafNodes(res, node->left);
        // go right
        leafNodes(res, node->right);
    }
    void rightBoundary(vector<int>& res, TreeNode* node) {
        // add right boundary
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) return;

        // go right
        rightBoundary(res, node->right);
        if (node->right == nullptr) rightBoundary(res, node->left);
        res.push_back(node->val);
    }
    vector<int> boundary(TreeNode* root) {
        // your code goes here
        vector<int> ans;
        if (root == NULL) return ans;
        ans.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return ans;
        }
        leftBoundary(ans, root->left);
        leafNodes(ans, root);
        rightBoundary(ans, root->right);
        return ans;
    }
};