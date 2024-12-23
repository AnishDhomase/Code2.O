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
    void trav(int lvl, TreeNode *rt, unordered_map<int, vector<int>> &levels){
        if(rt){
            levels[lvl].push_back(rt->val);
            trav(lvl + 1, rt->left, levels);
            trav(lvl + 1, rt->right, levels);
        }
    }
public:
    int minimumOperations(TreeNode* root) {
        int swaps = 0;
        unordered_map<int, vector<int>> levels;
        trav(0, root, levels);
        for(auto &it: levels){
            auto v = it.second;
            int n = v.size();
            for(int i=0; i<n; i++){
                int smaller = 1e9, smallerInd = -1;
                bool sorted = true;
                for(int j=i+1; j<n; j++){
                    if(v[j-1] > v[j])   sorted = false;
                    if(v[j] < smaller){
                        smaller = v[j];
                        smallerInd = j;
                    }
                }
                if(sorted)  break;
                if(v[i] > smaller){
                    swaps ++;
                    swap(v[i], v[smallerInd]);
                } 
                
            }
        }
        return swaps;
    }
};