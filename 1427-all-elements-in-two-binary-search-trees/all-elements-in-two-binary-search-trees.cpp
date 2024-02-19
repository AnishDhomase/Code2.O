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
    void inorder(TreeNode *rt, vector<int> &arr){
        if(rt){
            inorder(rt->left, arr);
            arr.push_back(rt->val);
            inorder(rt->right, arr);
        }
    }
    void mergeTwoSortedArr(vector<int> &mergedArr, vector<int> arr1, vector<int> arr2){
        int i=0, j=0;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                mergedArr.push_back(arr1[i]);
                i++;
            }
            else{
                mergedArr.push_back(arr2[j]);
                j++;
            }
        }
        while(i < arr1.size()){
            mergedArr.push_back(arr1[i]);
            i++;
        }
        while(j < arr2.size()){
            mergedArr.push_back(arr2[j]);
            j++;
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2, mergedArr;
        inorder(root1, arr1);
        inorder(root2, arr2);
        mergeTwoSortedArr(mergedArr, arr1, arr2);
        return mergedArr;
    }
};