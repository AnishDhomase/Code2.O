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

        if(head){
            ListNode *fast=head, *slow=head;
            while(fast && fast->next){
                slow=slow->next;
                fast=fast->next->next;
                if(fast==slow)  return true;
            }
        }
        return false;



        // if(head){
        //     ListNode *temp=head;
        //     while(temp){
        //         if(temp->val == pow(10,6)) return true;
        //         temp->val=pow(10,6);
        //         temp=temp->next;
        //     }
        // }
        // return false;


        // unordered_map<ListNode*,int> ptrs;
        // if(head){
        //     ListNode *temp=head;
        //     while(temp){
        //         if(ptrs[temp])  return true;
        //         ptrs[temp]++;
        //         temp=temp->next;    
        //     }
        //     return false;
        // }
        // return false;
    }
};