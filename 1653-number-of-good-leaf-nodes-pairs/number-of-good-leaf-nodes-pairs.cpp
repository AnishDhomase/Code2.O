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
    int getDistBetweenNodes(int i, int j, vector<string> &pathsToLeaf){
        int ind=0, n1 = pathsToLeaf[i].length(), n2 = pathsToLeaf[j].length();
        while(ind < n1 && ind < n2){
            if(pathsToLeaf[i][ind] != pathsToLeaf[j][ind]) break;
            ind ++;
        }
        return n1 + n2 - (2*ind);
    }
    void trav(TreeNode *rt,  string path, vector<string> &pathsToLeaf){
        if(rt){
            if(rt->left)  trav(rt->left, path + 'L', pathsToLeaf);
            if(rt->right) trav(rt->right, path + 'R', pathsToLeaf);
            if(!rt->left && !rt->right)
                pathsToLeaf.push_back(path);
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ct = 0;
        vector<string> pathsToLeaf;
        trav(root, "", pathsToLeaf);
        int n = pathsToLeaf.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(getDistBetweenNodes(i, j, pathsToLeaf) <= distance)
                    ct ++;
            }
        }
        return ct;
    }
};