#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create node
TreeNode* createNode(int x) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return createNode(key);

    TreeNode* curr = root;

    while (1) {
        if (key < curr->data) {
            if (curr->left)
                curr = curr->left;
            else {
                curr->left = createNode(key);
                break;
            }
        } else {
            if (curr->right)
                curr = curr->right;
            else {
                curr->right = createNode(key);
                break;
            }
        }
    }
    return root;
}

// Find LCA
TreeNode* findLCA(TreeNode* root, int A, int B) {
    while (root != NULL) {
        if (A < root->data && B < root->data)
            root = root->left;
        else if (A > root->data && B > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

// Find sum from root to target
int pathSum(TreeNode* root, int target) {
    int sum = 0;

    while (root != NULL) {
        sum += root->data;

        if (root->data == target)
            return sum;
        else if (target < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    TreeNode* root = NULL;
    int x;

    // build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int A, B;
    scanf("%d %d", &A, &B);

    // Step 1: find LCA
    TreeNode* lca = findLCA(root, A, B);

    // Step 2: path sums
    int sum1 = pathSum(lca, A);
    int sum2 = pathSum(lca, B);

    // subtract LCA once (counted twice)
    int result = sum1 + sum2 - lca->data;

    printf("%d\n", result);

    return 0;
}