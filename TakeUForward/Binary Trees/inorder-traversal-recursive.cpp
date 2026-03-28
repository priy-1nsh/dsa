#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
   private:
    // inorder traversal recursive function
    void inorderRecursive(TreeNode* root, vector<int>& arr) {
        // base case
        if (root == nullptr) {
            return;
        }

        // inorder : left access right

        inorderRecursive(root->left, arr);
        arr.push_back(root->data);
        inorderRecursive(root->right, arr);
    }

   public:
    vector<int> inorder(TreeNode* root) {
        vector<int> arr;
        inorderRecursive(root, arr);
        return arr;
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol = Solution();

    vector<int> ans = sol.inorder(root);

    cout << "Inorder Traversal :";

    for (int val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}