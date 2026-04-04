#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    // iterative inorder traversal
    // let's start
    void iterativeInorder(TreeNode* root, vector<int>& arr) {
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true) {
            // left
            if (node != nullptr) {
                st.push(node);
                // go to left
                node = node->left;
                // keep going left like this until you encounter a NULL
            } else {
                if (st.empty()) {
                    break;
                    // nowhere to go - completion
                }
                // we found a nullptr node
                // get the last node pushed into the stack
                node = st.top();
                // pop the element out
                st.pop();
                // access the node
                arr.push_back(node->data);
                // go right
                node = node->right;
            }
        }
    }
};

int main() {
    // list to add the tree elements

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> result;

    Solution* sol = new Solution();
    sol->iterativeInorder(root, result);

    // print result
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}