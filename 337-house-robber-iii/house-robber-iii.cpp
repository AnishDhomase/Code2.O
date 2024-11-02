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
    int getMaxMoney(TreeNode *rt, int prev, map<TreeNode*, unordered_map<int,int>> &dp){
        if(!rt) return 0;
        if(dp[rt][prev] != -1)  return dp[rt][prev];

        // notRob
        int notRob = getMaxMoney(rt->left, 0, dp) + getMaxMoney(rt->right, 0, dp);
        // rob
        int rob = 0;
        if(prev == 0)
            rob = rt->val + getMaxMoney(rt->left, 1, dp) + getMaxMoney(rt->right, 1, dp);
        return dp[rt][prev] = max(rob, notRob);

    }
    void trav(TreeNode *rt, map<TreeNode*, unordered_map<int,int>> &dp){
        if(!rt)   return;

        dp[rt][0] = -1;
        dp[rt][1] = -1;

        trav(rt->left, dp); 
        trav(rt->right, dp); 
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode*, unordered_map<int,int>> dp;
        trav(root, dp);
        return getMaxMoney(root, 0, dp);
    }
};