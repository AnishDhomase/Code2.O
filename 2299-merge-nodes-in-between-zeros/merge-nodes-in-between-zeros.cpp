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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp, *nn, *pn;
        bool headassgn=true;
        int sum=0;
        temp=head->next;
        while(temp){
            if(temp->val==0){
                nn=new ListNode(sum);
                sum=0;
                if(headassgn){
                    headassgn=false;
                    head=nn;
                } 
                else    pn->next=nn; 
                nn->next=temp->next;
                temp->next=NULL;
                temp=nn->next;
                pn=nn;   
                continue; 
            }
            sum+=temp->val;
            temp=temp->next;
        }
        return head;


        // ListNode *temp, *ansHead=NULL, *nn, *pn;
        // int sum=0;
        // temp=head->next;
        // while(temp){
        //     if(temp->val==0){
        //         nn=new ListNode(sum);
        //         sum=0;
        //         if(ansHead) pn->next=nn;
        //         else        ansHead=nn;
        //         pn=nn;    
        //     }
        //     sum+=temp->val;
        //     temp=temp->next;
        // }
        // return ansHead;
    }
};