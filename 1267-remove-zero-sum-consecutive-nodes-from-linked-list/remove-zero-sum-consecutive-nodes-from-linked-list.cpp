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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *prev=NULL, *i=head, *j;
        bool flag = true;
        while(flag){
            bool fl = false;
            while(i){
                int consSum = 0;
                for(j=i ; j; j=j->next){
                    consSum += j->val;
                    if(consSum == 0){
                        fl = true;
                        if(prev)
                            prev->next = j->next;
                        else head = j->next;
                        i = j->next;
                        break;
                    }
                }
                if(j==NULL){
                    prev=i; i=i->next;
                }
            }
            flag = fl;
        }
        return head;
    }
};