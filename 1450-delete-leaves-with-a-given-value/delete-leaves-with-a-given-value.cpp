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
    // dir -1, 0, 1
    void inorder(int dir, TreeNode *par, TreeNode *chld, int target){
        if(chld){
            inorder(-1, chld, chld->left, target);
            inorder(1, chld, chld->right, target);
            if(chld->left==NULL && chld->right==NULL){
                if(chld->val == target && par){
                    if(dir == -1)
                        par->left = NULL;
                    else if(dir == 1)
                        par->right = NULL;
                    delete chld;
                } 
            }
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        inorder(0, NULL, root, target);
        if(root->left==NULL && root->right==NULL){
            if(root->val == target){
                return NULL;
            } 
        }
        return root;
    }
};