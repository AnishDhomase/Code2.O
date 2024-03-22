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
    bool isPalindrome(ListNode* head) {
        string str;
        ListNode *t = head;
        while(t){
            str += (t->val + 48);
            t = t->next;
        }
        int n = str.length();
        int i=0, j=n-1;
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};