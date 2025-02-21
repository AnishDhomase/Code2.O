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
class FindElements {
    TreeNode* root;
    void recover(int v, TreeNode *rt){
        if(!rt) return;

        rt->val = v;
        recover(2*v+1, rt->left);
        recover(2*v+2, rt->right);
    }
    bool search(int v, TreeNode *rt){
        if(!rt) return false;
        if(rt->val == v)    return true;

        if(search(v, rt->left))    return true;
        return search(v, rt->right);
    }
public:
    FindElements(TreeNode* root) {
        this->root = root;
        recover(0, root);
    }
    
    bool find(int target) {
        return search(target, root);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */