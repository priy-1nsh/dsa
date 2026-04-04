#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> postorder(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* node = root;

    while (!st.empty()) {
        // access
        node = st.top();
        // go right then left
        st.pop();
        ans.push_back(node->data);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    vector<int> ans;
    ans = postorder(root);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}