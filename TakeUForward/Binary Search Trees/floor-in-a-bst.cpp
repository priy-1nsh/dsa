#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int floorInBST(TreeNode* root, int key) {
    // greatest element smaller than or equal to key
    int ans = -1;
    while (root) {

        if (root->data == key) {
            return root->data;
        }

        if (key < root->data) {
            // go left
            root = root->left;
        }
        else {
            // key > root->data
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

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

int main() {

    TreeNode* root = nullptr;
    root = insert(root, 8);
    insert(root, 4);
    insert(root, 12);
    insert(root, 2);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);

    int key = 11;

    int ans = floorInBST(root, key);

    cout << ans;

    return 0;
}