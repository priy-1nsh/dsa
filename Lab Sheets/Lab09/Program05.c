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

// dfs to compute size
int computeSize(TreeNode* root, int result[]) {
    if (root == NULL) return 0;

    int leftSize = computeSize(root->left, result[]);
    int rightSize = computeSize(root->right, result[]);
    int total = leftSize + rightSize;
    result[root->data] = total;
    return total + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int x;
    int arr[1000];
    TreeNode* = NULL;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        root = insert(root, arr[i]);
    }

    int result[1001] = {0};
    computeSize(root, result);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[arr[i]]);
    }

    return 0;
}