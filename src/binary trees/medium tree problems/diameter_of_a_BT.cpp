class Solution {
   private:
    int findMaxLength(TreeNode* node, int& maxi) {
        if (node == NULL) return 0;

        int lh = findMaxLength(node->left, maxi);
        int rh = findMaxLength(node->right, maxi);

        maxi = max(maxi, lh + rh);

        return 1 + max(lh, rh);
    }

   public:
    int findDiameter(TreeNode* node) {
        int maxi = 0;
        findMaxLength(node, maxi);
        return maxi;
    }
};