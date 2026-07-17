/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // your code goes here
        //  we will do a level order traversal
        queue<pair<TreeNode*, pair<int, int>>> q;
        // queue contains (node, {col, row});
        vector<vector<int>> res;
        if (root == NULL) return res;
        map<int, map<int, multiset<int>>>
            mpp;  // to store the [col][row]{multiset}
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int col = it.second.first;
            int row = it.second.second;
            mpp[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        // put into res
        for (auto p : mpp) {
            // p is of type pair<int, map<int, multiset>>
            // first p will have col = -1, then next iteration it will be 0 and
            // so on
            vector<int> column;
            for (auto q : p.second) {
                // p.second is a map
                // based on int (first index), it will be sorted
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            res.push_back(column);
        }
        return res;
    }
};