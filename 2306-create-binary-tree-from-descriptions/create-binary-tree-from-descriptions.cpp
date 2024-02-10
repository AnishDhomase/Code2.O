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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> ind;

        for(auto d : descriptions){
            int par = d[0], chld = d[1], dir = d[2];
            TreeNode *parAdd=NULL, *chldAdd=NULL;
            ind[chld]++;
            ind[par] += 0;
            if(mp[par]) parAdd = mp[par];
            else{   
                parAdd = new TreeNode(par);
                mp[par] = parAdd;
            }        
            if(mp[chld]) chldAdd = mp[chld];
            else{   
                chldAdd = new TreeNode(chld);
                mp[chld] = chldAdd;
            }
            if(dir) parAdd->left = chldAdd;
            else    parAdd->right = chldAdd;  
        }

        for(auto pr : ind){
            if(pr.second == 0)
                return mp[pr.first];
        }
        return NULL;
    }
};