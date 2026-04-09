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

TreeNode* LCAinBST(TreeNode* root, int u, int v) {
    if (root == NULL) return NULL;
    TreeNode* curr = root;
    while (true) {
        // both are on the right
        if (u > curr->data && v > curr->data) {
            // go right
            curr = curr->right;
        } else if (u < curr->data && v < curr->data) {
            // go left
            curr = curr->left;
        }
        // in all other cases - ans is root itself
        else {
            return curr;
        }
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

    int u, v;
    scanf("%d %d", &u, &v);

    TreeNode* ans = LCAinBST(root, u, v);

    printf("%d", ans->data);

    return 0;
}