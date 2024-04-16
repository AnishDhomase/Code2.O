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
    void preorder(TreeNode *rt, int depth, int val, int reqDepth){
        if(rt){
            if(depth == reqDepth-1){
                TreeNode *lNewNode = new TreeNode(val);
                TreeNode *rNewNode = new TreeNode(val);
                lNewNode->left = rt->left;
                rNewNode->right = rt->right;
                rt->left = lNewNode;
                rt->right = rNewNode;
                return;
            }
            preorder(rt->left, depth+1, val, reqDepth);
            preorder(rt->right, depth+1, val, reqDepth);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        preorder(root, 1, val, depth);
        return root;

    }
};