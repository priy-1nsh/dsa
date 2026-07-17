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
    vector<int> postorder(TreeNode* root) {
        // your code goes here
        // postorder :- (left right access)
        // to avoid accessing each node thrice,we will follow the reverse order
        // :- (access right left)
        stack<TreeNode*> st;
        vector<int> vc;
        st.push(root);
        while (true) {
            if (st.empty()) break;
            TreeNode* node = st.top();
            st.pop();
            vc.push_back(node->data);

            // now push left first then right
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(vc.begin(), vc.end());
        return vc;
    }
};