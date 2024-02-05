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
    void preorder(TreeNode *rt, int max, int &ct){
        if(rt){
            if(max <= rt->val)  ct++;
            int currMax = max > rt->val ? max : rt->val;
            preorder(rt->left, currMax, ct);
            preorder(rt->right, currMax, ct);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        int ct = 0;
        preorder(root, -100000, ct);
        return ct;
    }
};