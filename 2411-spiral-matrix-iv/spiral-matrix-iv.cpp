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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode *t = head;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        while(t){
            for(int c=left; c<=right; c++, t=t->next){
                if(t == NULL)   return matrix;
                matrix[top][c] = t->val; 
            }
            top ++;
            for(int r=top; r<=bottom; r++, t=t->next){
                if(t == NULL)   return matrix;
                matrix[r][right] = t->val; 
            }
            right --;
            for(int c=right; c>=left; c--, t=t->next){
                if(t == NULL)   return matrix;
                matrix[bottom][c] = t->val; 
            }
            bottom --;
            for(int r=bottom; r>=top; r--, t=t->next){
                if(t == NULL)   return matrix;
                matrix[r][left] = t->val; 
            }
            left ++;
        }
        return matrix;
    }
};