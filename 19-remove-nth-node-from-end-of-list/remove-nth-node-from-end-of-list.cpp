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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0,startPos;
        ListNode *temp=head, *toDel;
        while(temp){
            len++;
            temp=temp->next;
        }

        startPos=len-n+1;
        if(startPos==1)
            head=head->next;
        else{
            temp=head;
            int pos=1;
            while(temp && pos<startPos-1){
                temp=temp->next;
                pos++;
            }
            toDel=temp->next;
            temp->next=temp->next->next;
            delete toDel;
        }
        return head;
    }
};