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
    void smaller(int target, TreeNode* rt, int &ans){
        if(rt){
            if(target == rt->val)
                ans = target;
            else if(target < rt->val)
                smaller(target, rt->left, ans);
            else{
                ans = max(ans, rt->val);
                smaller(target, rt->right, ans);
            }
        }
    }
    void bigger(int target, TreeNode* rt, int &ans){
        if(rt){
            if(target == rt->val)
                ans = target;
            else if(target < rt->val){
                ans = min(ans, rt->val);
                bigger(target, rt->left, ans);
            }
            else{
                bigger(target, rt->right, ans);
            }
        }
    }
    void inorder(TreeNode* rt, vector<int> &v){
        if(rt){
            inorder(rt->left, v);
            v.push_back(rt->val);
            inorder(rt->right, v);
        }
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> v;
        inorder(root, v);
        int n = v.size();
        for(auto q : queries){
            int small=-1, big=-1;
            int lb = lower_bound(v.begin(), v.end(), q) - v.begin();
            if(lb == n)
                small = v[n-1];
            else{
                if(v[lb] == q){
                    small = big = q;
                }
                else{
                    big = v[lb];
                    if(lb!=0){
                        small = v[lb-1];
                    }
                }
            }
            ans.push_back({small,big});
        }
        return ans;

        // TLE 35/36
        // vector<vector<int>> ans;
        // for(auto q : queries){
        //     int small=-1, big=1e9;
        //     smaller(q, root, small);
        //     if(small != q)
        //         bigger(q, root, big);
        //     else   big = q; 
        //     if(big==1e9)    big = -1;
        //     ans.push_back({small,big});
        // }
        // return ans;
    }
};