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
    bool preTrav(TreeNode *rt, string &path, int target) {
        if(rt){
            if(rt->left){
                path += 'L';
                if(preTrav(rt->left, path, target))
                    return true;
            }
            if(rt->val == target)   return true;
            if(rt->right){
                path += 'R';
                if(preTrav(rt->right, path, target))
                    return true;
            }
        }
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathFromRootToStart, pathFromRootToEnd, ans;
        preTrav(root, pathFromRootToStart, startValue);
        preTrav(root, pathFromRootToEnd, destValue);
        int s=0, e=0;
        int sizeS = pathFromRootToStart.length(), sizeE = pathFromRootToEnd.length();
        while(s < sizeS && e < sizeE) {
            if(pathFromRootToStart[s] != pathFromRootToEnd[e]) break;
            s ++;
            e ++;
        }
        while(s < sizeS) {
            ans += 'U';
            s ++;
        }
        while(e < sizeE) {
            ans += pathFromRootToEnd[e];
            e ++;
        }
        return ans;
    }
};