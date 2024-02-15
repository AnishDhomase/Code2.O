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
    bool preorder(TreeNode *rt, int lvl, unordered_map<int,int> &mp){
        if(rt){
            if(lvl % 2 && rt->val%2!=0) return false;
            if(lvl % 2 == 0 && rt->val%2==0) return false;
            if(!mp[lvl]){
                mp[lvl] = rt->val;
            }
            else{
                if(lvl % 2){ //odd level
                    if(mp[lvl] <= rt->val)
                        return false;
                }
                else{ //even level
                    if(mp[lvl] >= rt->val)
                        return false;
                }
                mp[lvl] = rt->val;
            }
            if(preorder(rt->left, lvl+1, mp)==false)
                return false;
            return preorder(rt->right, lvl+1, mp);
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        unordered_map<int,int> mp;
        return preorder(root, 0, mp);
    }
};