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
        // your code goes here
        // (access left right)
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while (true) {
            if (node != NULL) {
                ans.push_back(node->data);
                st.push(node);
                node = node->left;
            }
            else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                node = node->right;
            }
        }
        return ans;
    }
};