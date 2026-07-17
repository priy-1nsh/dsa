1. Level Order Traversal - BFS

https://takeuforward.org/plus/dsa/problems/level-order-traversal?subject=dsa&approach=iterative

Trick :- **qSize snapshot size before the loop" trick**

General template for *any* level-by-level BFS — same skeleton works for right-side-view, zigzag traversal, level averages, etc.

```cpp
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            vector<int> level;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
```

2. Max Depth of the Tree

https://takeuforward.org/plus/dsa/problems/maximum-depth-in-bt?subject=dsa&approach=recursive

Use recursive formula : 1+max(left_subtree_height, right_subtree_height)

3. Print the route from root to leaf for the max depth of the tree

https://takeuforward.org/plus/dsa/problems/maximum-depth-in-bt?subject=dsa&approach=recursive

Recursive - 

Backtracking trick 

base case : if (node==null) and if (node==leafNode)

```cpp
void dfs(TreeNode* node, vector<int>& path, vector<int>& maxPath,
             int maxDepth) {
        if (node == nullptr) return;
        // else not null
        path.push_back(node->val);

        // if leaf node
        if (node->left == NULL && node->right == NULL) {
            if ((int)path.size() > maxDepth) {
                maxDepth = path.size();
                maxPath = path;
            }
            path.pop_back();
            return;
        }

        // call left recurse
        dfs(node->left, path, maxPath, maxDepth);
        dfs(node->right, path, maxPath, maxDepth);

        // once done - backtrack
        path.pop_back();
        // return
}
int maxDepth(TreeNode* root) {
        // call the dfs with root as node and empty vectors as path and maxPath
        // and maxDepth as 0
}
```

Iterative -

BFS + remember the parent of each node using the parent unordered_map

```cpp
class Solution {
   public:
    vector<int> maxDepth(TreeNode* root) {
        vector<int> path;
        if (root == NULL) return path;

        // BFS - track the last node and also track the parent of each node
        unordered_map<TreeNode*, TreeNode*> parent;

        parent[root] = nullptr;  // nullptr acts as false

        // also track the last node
        TreeNode* lastNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                lastNode = node;
                q.pop();
                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        for (TreeNode* curr = lastNode; curr; curr = parent[curr]) {
            path.push_back(curr->val);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
```

4. Same tree or not

https://takeuforward.org/plus/dsa/problems/check-if-two-trees-are-identical-or-not?subject=dsa&approach=recursive&tab=submissions

Recursive -

Better readable version -

```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, the trees are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // If one of the nodes is null, the trees are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // If the values of the nodes are different, the trees are not the same
        if (p->data != q->data) {
            return false;
        }

        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
```

```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->data != q->data) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```

Iterative -

```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*>> q1;
    q1.push({p, q});
    while (!q1.empty()) {
        auto [n1, n2] = q1.front(); q1.pop();
        if (!n1 && !n2) continue;                          // both null, fine, move on
        if (!n1 || !n2 || n1->data != n2->data) return false;
        q1.push({n1->left,  n2->left});
        q1.push({n1->right, n2->right});
    }
    return true;
}
```

5. Check Balanced Or Not

https://takeuforward.org/plus/dsa/problems/check-for-balanced-binary-tree?subject=dsa&approach=optimal&tab=editorial

DESC -

Brute force Solution :

```cpp
class Solution {
private:
    int findHeight(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + max(findHeight(node->left), findHeight(node->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        if (abs(lh - rh) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
```

Since, we are using findHeight everytime inside the recursive isBalanced function, it takes O(N2) TC, when the tree is skewed, and the height of the tree becomes equal to the number of nodes in the tree.

Optimal Solution :

```cpp
class Solution {
private:
    int findHeightModified(TreeNode* node) {
        if (node == NULL) return 0;

        int lh = findHeightModified(node->left);
        int rh = findHeightModified(node->right);

        // the next two lines make all the difference, changing the function into whether returning only two sort of integer values so that it behaves as a boolean function.
        if (lh == -1 || rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    // if this function returns -1, then it it is unbalanced, and if it is balanced. it will return the height of the BT.
public:
    bool isBalanced(TreeNode* root) {
        return findHeightModified(root) != -1;
        // if not -1, it will give true, else it will give false.
    }
};
```

We used a trick here, by which we modified the findHeight function to return only two types of value, either the height of the balanced BT, or -1 if it is unbalanced, and we shortcircuit it using return -1.

6. Diameter of a BT

https://takeuforward.org/plus/dsa/problems/diameter-of-binary-tree?subject=dsa&approach=optimal

DESC -

```cpp
class Solution {
    private:
        int findMaxLength(TreeNode* node, int& maxi) {
            if (node == NULL) return 0;

            int lh = findMaxLength(node->left, max);
            int rh = findMaxLength(node->right, max);

            maxi = max(maxi, lh+rh);

            return 1+max(lh, rh);
        }
    public:
        int findDiameter(TreeNode* node) {
            int maxi = 0;
            findMaxLength(node, maxi);
            return maxi;
        }
};
```

This is a classic **tree DP** pattern — "compute a bottom-up value (height) while opportunistically using it to update a separate global answer."

Use the same findHeight function and modify it a bit

7. Max Path Sum - Super Important : same as diameter concept

https://takeuforward.org/plus/dsa/problems/maximum-path-sum-?subject=dsa&approach=optimal

DESC -

What to return and what to update the maxi with are two different things, `return` helps decide which branch to choose, `update maxi` with the sum of the path with the current node as the peak.

```cpp
class Solution {
public:
    // maximum path sum
    int maxSum(TreeNode* node, int& maxi) {
        if (node == nullptr) return 0;

        int lSum = maxSum(node->left, maxi);
        int rSum = maxSum(node->right, maxi);

        maxi = max(maxi, node->data + lSum + rSum); // update the maxi with the path that passes through this node as the peak

        return node->data + max(lSum, rSum); // choose which branch
    }
};
```

8. hasPathSum

https://leetcode.com/problems/path-sum/submissions/2065144898/

Look at this solution - it's just recursion, just remember where do u want to encounter the base case - at the leaf node or at the null node.

9. Symmetric Tree

https://takeuforward.org/plus/dsa/problems/check-for-symmetrical-bts?subject=dsa&approach=optimal&tab=editorial

DESC -

Do the identical trees question first then only try to attempt this. Because this following condition is very important.

```cpp
if (l == nullptr || r == nullptr) {
    return l == r;
}
```

```cpp
class Solution {
private:
    bool check(TreeNode* l, TreeNode* r) {
        if (l == nullptr || r == nullptr) {
            return l == r;
        }
        if (l->val != r->val) return false;

        return check(l->left, r->right) && check(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return false;
        return check(root->left, root->right);
    }
};
```

10. Boundary Traversal -

https://takeuforward.org/plus/dsa/problems/boundary-traversal?subject=dsa&approach=optimal&tab=submissions

DESC -

Very important : split into left + leaf nodes + right. That's it.

11. Vertical Order Traversal

https://takeuforward.org/plus/dsa/problems/vertical-order-traversal?subject=dsa&approach=optimal

DESC -

use `map<int, map<int, multiset<int>>>` for storing the left to right, top to bottom, and if row same, still sorted order.

12. 
