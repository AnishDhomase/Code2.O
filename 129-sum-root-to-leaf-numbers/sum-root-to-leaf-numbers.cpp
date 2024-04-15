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
    void preorder(TreeNode *rt, string &num, int &sum){
        num += rt->val+48;
        if(!rt->left && !rt->right)
            sum += stoi(num);
        if(rt->left)    preorder(rt->left, num, sum);
        if(rt->right)    preorder(rt->right, num, sum);
        if(num != "") num.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string num;
        preorder(root, num, sum);
        return sum;
    }
};