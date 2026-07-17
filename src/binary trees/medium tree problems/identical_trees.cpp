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
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // your code goes here
        if (!p && !q) return true;
        if (!p || !q || p->data != q->data) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // your code goes here
        // iterative
        if (!p && !q) return true;
        queue<pair<TreeNode*, TreeNode*>> q1;
        q1.push({p, q});
        while (!q1.empty()) {
            auto [n1, n2] = q1.front();
            q1.pop();
            if (!n1 && !n2) continue;
            if (!n1 || !n2 || n1->val != n2->val) return false;
            // push even the null
            q1.push({n1->left, n2->left});
            q1.push({n1->right, n2->right});
        }
        return true;
    }
};