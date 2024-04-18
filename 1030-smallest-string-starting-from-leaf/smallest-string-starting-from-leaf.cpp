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
    void checkIsBeforeLexicographically(string str, string &ans){
        reverse(str.begin(), str.end());
        if(ans=="" || ans.compare(str)>0)
            ans = str;
    }
    void preorder(TreeNode *rt, string &str, string &ans){
        char ch = 97 + rt->val;
        str += ch;
        if(rt->left)    preorder(rt->left, str, ans);
        if(rt->right)   preorder(rt->right, str, ans);
        if(!rt->left && !rt->right)
            checkIsBeforeLexicographically(str,ans);
        str.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans, str;
        preorder(root, str, ans);
        return ans;
    }
};