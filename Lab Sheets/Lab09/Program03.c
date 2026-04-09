#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// count Nodes in BST
// if null, return 0
// if < L , go to right
// if > R, go to left
// else = [L, R] then return 1 + go to left + go to right

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int x) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;
    return newNode;
}

// insert into bst
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return createNode(key);

    TreeNode* curr = root;
    while (true) {
        if (key < curr->data) {
            // go left
            if (curr->left != NULL)
                curr = curr->left;
            else {
                curr->left = createNode(key);
                break;
            }
        } else {
            // key > curr->data
            // go right
            if (curr->right != NULL)
                curr = curr->right;
            else {
                curr->right = createNode(key);
                break;
            }
        }
    }
    return root;
}

int countNodes(TreeNode* root, int l, int r) {
    if (root == NULL) return 0;

    if (root->data < l) {
        return countNodes(root->right, l, r);
    } else if (root->data > r) {
        return countNodes(root->left, l, r);
    } else {
        return 1 + countNodes(root->right, l, r) + countNodes(root->left, l, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int x;
    TreeNode* root = NULL;

    // read the n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int l, r;
    scanf("%d %d", &l, &r);

    int ans = countNodes(root, l, r);

    printf("%d", ans);

    return 0;
}