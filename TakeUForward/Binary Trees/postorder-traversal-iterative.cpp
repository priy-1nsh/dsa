#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> postorder(TreeNode* root) {
    TreeNode* node = root;
    stack<TreeNode*> st;
    vector<int> ans;

    while (true) {
        // access right left
        if (node != nullptr) {
            ans.push_back(node->data);
            // before going right, put into stack
            st.push(node);
            // go right
            node = node->right;
        } else {
            if (st.empty()) break;
            // going right, we get nullptr
            node = st.top();
            st.pop();
            // now go left
            node = node->left;
        }
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
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans;
    ans = postorder(root);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}