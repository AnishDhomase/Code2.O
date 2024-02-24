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
    void trav(TreeNode* rt, int &sum){
        if(rt){
            trav(rt->right, sum);
            rt->val += sum;
            sum = rt->val;
            trav(rt->left, sum);
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        trav(root, sum);
        return root;
    }
};