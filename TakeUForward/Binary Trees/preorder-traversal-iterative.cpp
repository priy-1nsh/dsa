#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> preorder(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode* node = root;

    while (true) {
        if (node != NULL) {
            // new node

            // access it
            result.push_back(node->data);

            // push to the stack
            st.push(node);

            // now go left
            node = node->left;
        }
        else {
            // we encounter a null
            if (st.empty()) break;
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    return result;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans;
    ans = preorder(root);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}