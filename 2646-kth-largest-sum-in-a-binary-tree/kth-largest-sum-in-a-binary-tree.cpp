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
    void preorder(TreeNode *rt,int lvl, unordered_map<int,long long> &sum){
        if(rt){
            sum[lvl] += rt->val;
            preorder(rt->left, lvl+1, sum);
            preorder(rt->right, lvl+1, sum);
        }
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int,long long> sum;
        vector<long long> sums;
        preorder(root, 1, sum);
        int lvls = sum.size();
        if(lvls < k)  return -1;
        for(auto it : sum){
            long long lvl = it.first, lvlSum = it.second;
            sums.push_back(lvlSum);
        }
        sort(sums.begin(), sums.end());
        return sums[lvls-k];
    }
};