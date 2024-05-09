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
    void addLhsToRhs(TreeNode *toAdd, TreeNode *rt){
        if(rt){
            if(rt->left==NULL)  rt->left = toAdd;
            else    addLhsToRhs(toAdd, rt->left);
        }
    }
    void trav(TreeNode *par, TreeNode *rt, TreeNode **rootAdr, int key){
        if(rt){
            if(rt->val == key){
                int dir = (par && par->left==rt) ? 0 : 1;
                if(rt->left==NULL && rt->right==NULL){ // 0 child
                    delete rt;
                    if(par){
                        if(dir) par->right = NULL;
                        else    par->left  = NULL;
                    }
                    else    *rootAdr = NULL;
                }
                else if(rt->left && rt->right){ // 2 child
                    if(par){
                        if(dir) par->right = rt->right;
                        else    par->left  = rt->right;
                    }
                    else    if(dir) *rootAdr = rt->right;
                    addLhsToRhs(rt->left, rt->right);
                    delete rt;
                }
                else{ // 1 child
                    if(par){
                        if(dir) par->right = rt->left ? rt->left : rt->right;
                        else    par->left  = rt->left ? rt->left : rt->right;
                    }
                    else{
                        *rootAdr = rt->left ? rt->left : rt->right;
                    }
                    delete rt;
                }
            }
            else{
                trav(rt, rt->left, rootAdr, key);
                trav(rt, rt->right, rootAdr, key);
            }  
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
            trav(NULL, root, &root, key);
        return root;
    }
};