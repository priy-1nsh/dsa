#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* searchInBST(TreeNode* root, int target) {
    TreeNode* node = root;
    while (node != nullptr && node->val != target) {
        if (target < node->val) 
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

// inorder traversal
void inorderTraversal(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;

    inorderTraversal(root->left, ans);
    // access
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);
}

// print the tree given the root
void printBinaryTree(TreeNode* root) {
    // inorder traversal
    vector<int> ans;
    inorderTraversal(root, ans);
    // now print the ans
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

int main () {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);

    int target = 2;

    TreeNode* ans = searchInBST(root, target);
    printBinaryTree(ans);
    return 0;
}