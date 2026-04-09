#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// utility function to insert nodes in a BST
TreeNode* insert(TreeNode* node, int key) {
    if (node == nullptr) return new TreeNode(key);

    if (key < node->data) { // to reach the null node at the correct place
        node->left = insert(node->left, key);
    }
    else if (key > node->data) {
        node->right = insert(node->right, key);
    }
    return node; // returns the root of this subtree
}

int ceilInBST(TreeNode* node, int key) {
    int ans = -1;
    while (node) {
        if (node->data == key)
            return node->data;
        if (node->data > key) {
            // that's what we want
            ans = node->data;
            // go for smallest
            node = node->left;
        }
        else {
            // node->data < key
            // go right
            node = node->right;
        }
    }
    return ans;
}

int main() {

    TreeNode* root = nullptr;
    root = insert(root, 8);
    insert(root, 4);
    insert(root, 12);
    insert(root, 2);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);

    int key = 11; // ans = 12

    int ans = ceilInBST(root, key);
    
    cout << ans << endl;

    return 0;
}