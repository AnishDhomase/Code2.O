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
    bool trav(TreeNode *par, TreeNode *rt, TreeNode **rootAdr){
        if(rt){
            bool v = rt->val == 1;
            bool l = trav(rt, rt->left, rootAdr);
            bool r = trav(rt, rt->right, rootAdr);
            bool result = l || r || v;
            if(result)  return true;
            if(par){
                if(par->left == rt) par->left = NULL; 
                else par->right = NULL; 
            }
            else    *rootAdr = NULL;
            delete rt;
        }
        return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        trav(NULL, root, &root);
        return root;
    }
};