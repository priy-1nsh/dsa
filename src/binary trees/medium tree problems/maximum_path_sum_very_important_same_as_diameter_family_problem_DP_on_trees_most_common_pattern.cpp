class Solution {
   public:
    // maximum path sum
    int maxSum(TreeNode* node, int& maxi) {
        if (node == nullptr) return 0;

        int lSum = max(0, maxSum(node->left, maxi));
        int rSum = max(0, maxSum(node->right, maxi));

        maxi = max(maxi, node->data + lSum + rSum);
        // update the maxi with the path that passes through this node as the
        // peak

        return node->data + max(lSum, rSum);  // choose which branch
    }
};