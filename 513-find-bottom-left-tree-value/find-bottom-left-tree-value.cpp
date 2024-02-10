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
    void preorder(TreeNode *rt, int lvl, int &ans, int &ansLvl){
        if(rt){
            if(lvl > ansLvl){
                ans = rt->val;
                ansLvl = lvl;
            }
            preorder(rt->left, lvl+1, ans, ansLvl);
            preorder(rt->right, lvl+1, ans, ansLvl);
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans=root->val, ansLvl=0;
        preorder(root, 0, ans, ansLvl);
        return ans;
    }
};