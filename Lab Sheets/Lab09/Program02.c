#include <Stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
        if (curr->data < key) {
            if (curr->right != NULL)
                curr = curr->right;
            else {
                curr->right = createNode(key);
                break;
            }
        } else {
            // key < root->data
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

int findFloor(TreeNode* root, int key) {
    // floor is the greatest node <= given key

    int ans = -1;
    while (root != NULL) {
        if (root->data == key) return root->data;
        if (key > root->data) {
            // that's what we want
            // but greater
            ans = root->data;
            root = root->right;
        } else {
            // key < root->data
            root = root->left;
        }
    }
    return ans;
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

    int p;
    scanf("%d", &p);

    int ans = findFloor(root, p);

    printf("%d", ans);

    return 0;
}