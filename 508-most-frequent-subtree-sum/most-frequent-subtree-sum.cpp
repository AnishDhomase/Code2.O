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
    int trav(TreeNode *rt, unordered_map<int,int> &freq){
        if(rt){
            int leftSubtreeSum = trav(rt->left, freq);
            int rightSubtreeSum = trav(rt->right, freq);
            int treeSum = leftSubtreeSum  + rightSubtreeSum + rt->val;
            freq[treeSum]++;
            return treeSum;
        }
        return 0;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> freq; //{SubtreeSum, freq}
        trav(root, freq);
        vector<int> ans;
        int maxFreq = 0;
        for(auto it : freq){
            int currFreq = it.second;
            int sum = it.first;
            if(maxFreq < currFreq){
                maxFreq = currFreq;
                ans.clear();
                ans.push_back(sum);
            }
            else if(maxFreq == currFreq){
                ans.push_back(sum);
            }
        }
        return ans;
    }
};