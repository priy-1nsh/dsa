/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
    int maxDepthHelper(TreeNode* node, int height) {
        if (!node) return 0;

        int left = maxDepth(node->left, height);
        int right = maxDepth(node->right, height);

        return 1+max(left, right);
    }
public:
    int maxDepth(TreeNode* root) {
        //your code goes here
        return maxDepthHelper(root, 0);
    }
};