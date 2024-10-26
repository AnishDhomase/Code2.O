/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getMaxPathDown(TreeNode* rt, int &maxPathSum){
        if(rt == NULL)  return 0;

        int leftDown = getMaxPathDown(rt->left, maxPathSum);
        leftDown = leftDown < 0 ? 0 : leftDown;
        int rightDown = getMaxPathDown(rt->right, maxPathSum);
        rightDown = rightDown < 0 ? 0 : rightDown;

        maxPathSum = max(maxPathSum, rt->val + leftDown + rightDown);

        return rt->val + max(leftDown, rightDown);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        getMaxPathDown(root, maxPathSum);
        return maxPathSum;
    }
};