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
    ListNode* revLL(ListNode *p, ListNode *c, ListNode *n){
        if(!c)  return p;
        c->next = p;
        if(n)   return revLL(c, n, n->next);
        return c;
    }
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if(!head || !head->next)    return head;
        // ListNode *prev = head, *curr = head->next, *nxt = head->next->next;
        // while(curr){
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = nxt;
        //     if(nxt)
        //         nxt = nxt -> next;
        // }
        // head -> next = NULL;
        // head = prev;
        // return head;
        if(!head)   return NULL;
        return revLL(NULL, head, head->next);
    }
};