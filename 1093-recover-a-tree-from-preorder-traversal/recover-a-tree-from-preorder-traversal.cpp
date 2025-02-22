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
    void recover(TreeNode *par, bool isleft, int dashes, int l, int r, TreeNode **adrOfRoot, string &traversal){
        // value of node
        int val = 0;
        int j = l;
        while(j<=r && traversal[j] != '-'){
            val = val * 10 + (traversal[j] - '0');
            j++;
        }

        // Attaching node to correct parent node
        TreeNode *nn = new TreeNode(val);
        if(!par)    *adrOfRoot = nn;
        else{
            if(isleft)  par->left = nn;
            else        par->right = nn;
        }

        // Figuring out subtrees
        int start = j+dashes, dashCnt = 0;
        vector<pair<int,int>> subtrees;
        for(int i=j+dashes; i<=r; i++){
            if(traversal[i] == '-') dashCnt ++;
            else{
                if(dashCnt == dashes){
                    subtrees.push_back({start, i-dashes-1});
                    start = i;
                    break;
                }
                dashCnt = 0;
            } 
        }
        if(start <= r) subtrees.push_back({start, r});

        int cnt = 0;
        for(auto subtree: subtrees){
            recover(nn, cnt==0, dashes+1, subtree.first, subtree.second, adrOfRoot, traversal);
            cnt ++;
        }
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode *root = NULL;
        int n = traversal.length();
        recover(NULL, true, 1, 0, n-1, &root, traversal);
        return root;
    }
};