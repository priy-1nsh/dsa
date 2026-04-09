#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// insert a given node in a BST
TreeNode* insertInBST(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);

    TreeNode* curr = root;

    while (true) {
        if (curr->data >= key) {
            // go left
            if (curr->left != nullptr)
                curr = curr->left;
            else {
                curr->left = new TreeNode(key);
                break;
            }
        } else {
            // curr->data < key
            // go right
            if (curr->right != nullptr)
                curr = curr->right;
            else {
                curr->right = new TreeNode(key);
                break;
            }
        }
    }
    return root;
}

// inorder traversal
void inorderTraversal(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;

    inorderTraversal(root->left, ans);
    // access
    ans.push_back(root->data);
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

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);

    int key = 5;
    // key to be inserted is 5

    TreeNode* ans = insertInBST(root, key);

    // print - inorder traversal
    printBinaryTree(ans);

    return 0;
}