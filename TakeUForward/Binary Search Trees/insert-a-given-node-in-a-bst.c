#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int x) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertInBST(TreeNode* root, int key) {
    if (root == NULL) return createNode(key);
    TreeNode* curr = root;
    while (true) {
        if (curr->data <= key) {
            // go right
            if (curr->right != NULL)
                curr = curr->right;
            else {
                // curr->right = NULL
                // insert here
                curr->right = createNode(key);
                break;
            }
        } else {
            // curr->data > key
            // go left
            if (curr->left != NULL)
                curr = curr->left;
            else {
                curr->left = createNode(key);
                break;
            }
        }
    }
    return root;
}

// recursive inorder travrsal - left access right
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(2);
    root->right = createNode(12);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->left->right->left = createNode(3);

    int key = 5;

    TreeNode* ans = insertInBST(root, key);

    inorderTraversal(ans);

    printf("\n");

    return 0;
}