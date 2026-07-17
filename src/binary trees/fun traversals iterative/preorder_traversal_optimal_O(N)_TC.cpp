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
    vector<int> preorder(TreeNode* root) {
        vector<int> vc;
        stack<TreeNode*> st;
        st.push(root);
        while (true) {
            // if stack is empty, we can't accss it
            if (st.empty()) break;
            TreeNode* node = st.top();
            st.pop();
            // access it
            vc.push_back(node->data);

            // first store right then left
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return vc;
    }
};