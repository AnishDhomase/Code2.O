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
        if(!head || !head->next)    return true;
        ListNode *prev = NULL, *slow = head, *nxt = head->next, *fast = head;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
            if(nxt) nxt = nxt->next;
        }
        if(fast->next == NULL)
            slow = prev;
        else
            slow->next = prev;
        while(slow && nxt){
            if(slow->val != nxt->val)
                return false;
            slow = slow -> next;
            nxt = nxt -> next;
        }
        return true;

    }
};