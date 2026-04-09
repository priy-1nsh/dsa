#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Queue {
    TreeNode* arr[1000];
    int front, rear;  // front and rear index
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue* q) { return q->front == q->rear; }

void push(Queue* q, TreeNode* node) {
    q->arr[q->rear] = node;
    q->rear++;
}

TreeNode* pop(Queue* q) {
    TreeNode* el = q->arr[q->front];
    q->front++;
    return el;
}

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

// zig-zag traversal
void zigZag(TreeNode* root) {
    if (root == NULL) return;
    Queue* q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    push(q, root);
    bool zigzag = true;

    while (!isEmpty(q)) {
        int size = q->rear - q->front;
        int level[1000];
        // level array for each array
        for (int i = 0; i < size; i++) {
            TreeNode* curr = pop(q);
            level[i] = curr->data;

            if (curr->left) push(q, curr->left);
            if (curr->right) push(q, curr->right);
        }
        // print based on direction
        if (zigzag) {
            for (int i = 0; i < size; i++) {
                printf("%d ", level[i]);
            }
        } else {
            for (int i = size - 1; i >= 0; i--) {
                printf("%d ", level[i]);
            }
        }
        zigzag = !zigzag;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    TreeNode* root = NULL;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    zigZag(root);

    return 0;
}