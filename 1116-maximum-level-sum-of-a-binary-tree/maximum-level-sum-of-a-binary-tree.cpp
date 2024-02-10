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
    void preorder(TreeNode *rt, int lvl, unordered_map<int,int> &sum){
        if(rt){
            sum[lvl]+=rt->val;
            preorder(rt->left, lvl+1, sum);
            preorder(rt->right, lvl+1, sum);
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<int,int> sum;
        preorder(root, 1, sum);
        int maxSum=(*sum.begin()).second, maxSumlvl=(*sum.begin()).first;
        for(auto it : sum){
            int currlvlSum = it.second, currlvl = it.first;
            if(currlvlSum > maxSum){
                maxSum = currlvlSum;
                maxSumlvl = currlvl;
            }
            else if(currlvlSum == maxSum){
                if(currlvl < maxSumlvl){
                    maxSumlvl = currlvl;
                }
            }
        }
        return maxSumlvl;
    }
};