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
    ListNode* middleNode(ListNode* head) {


        ListNode *slow=head, *fast=head;
        while(true){
            if(fast==NULL || fast->next==NULL)  break;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;















        // int count=0, mid;
        // ListNode *temp=head;
        // while(temp){
        //     count++;
        //     temp=temp->next;
        // }
        // mid=count/2 + 1;
        // temp=head;
        // int i=1;
        // while(i!=mid){
        //     temp=temp->next;
        //     i++;
        // }
        // return temp;


        
    }
};