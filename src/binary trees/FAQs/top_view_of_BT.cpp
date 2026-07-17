/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push(root, 0);
        map<int, int> mpp;
        while (!q.empty()) {
            auto it = q,front(); q.pop();
            TreeNode* node = it.first;
            int horDist = it.second;
            
        }
    }
};