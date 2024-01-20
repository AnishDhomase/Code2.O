/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool inorder(TreeNode *rt, ListNode* head){
        if(rt){
            if(isPathExist(rt, head))
                return true;
            if(inorder(rt->left, head))
                return true;
            return inorder(rt->right, head);
        }
        return false;
    }
    bool isPathExist(TreeNode *rt, ListNode *head){
        if(!head)   return true;
        if(rt){
            if(rt->val != head->val)
                return false;
            if(isPathExist(rt->left, head->next))
                return true;
            return isPathExist(rt->right, head->next);
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return inorder(root, head);
    }
};