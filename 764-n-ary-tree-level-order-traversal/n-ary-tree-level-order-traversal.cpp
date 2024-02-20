/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void preorder(Node *rt, int lvl, unordered_map<int,vector<int>> &mp){
        if(rt){
            mp[lvl].push_back(rt->val);
            for(auto chldAddr : rt->children)
                preorder(chldAddr, lvl+1, mp);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        int lvl = 0;
        preorder(root, 0, mp);
        while(mp[lvl].size()){
            ans.push_back(mp[lvl]);
            lvl++;
        }
        return ans;
    }
};