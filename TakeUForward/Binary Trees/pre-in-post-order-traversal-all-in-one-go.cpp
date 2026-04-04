// all the traversals in a single go

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> allTraversals(TreeNode* root) {
    vector<int> pre, in, post;
    if (root == nullptr) return {pre, in, post};
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left) st.push({it.first->left, 1});
        }

        else if (it.second == 2) {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right) st.push({it.first->right, 1});
        }

        else {
            post.push_back(it.first->val);
        }
    }
    return {pre, in, post};
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> traversals = allTraversals(root);

    // Print Preorder traversal
    cout << "Preorder traversal: ";
    for (int val : traversals[0]) cout << val << " ";
    cout << endl;

    // Print Inorder traversal
    cout << "Inorder traversal: ";
    for (int val : traversals[1]) cout << val << " ";
    cout << endl;

    // Print Postorder traversal
    cout << "Postorder traversal: ";
    for (int val : traversals[2]) cout << val << " ";
    cout << endl;

    return 0;
}