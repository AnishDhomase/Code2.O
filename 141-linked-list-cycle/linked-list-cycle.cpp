/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f, *s;
        f = s = head;
        while(f && f->next && f->next->next){
            f = f->next->next;
            s = s->next;
            if(f == s) 
                return true;
        }
        return false;
    }
};