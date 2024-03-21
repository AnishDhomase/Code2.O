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
    ListNode* reverseList(ListNode* head) {
        ListNode* headrev=NULL;
        ListNode* temp=head;
        while(temp){
            ListNode* nn=new ListNode(temp->val);
            nn->next=headrev;
            headrev=nn;
            temp=temp->next;
        }
        return headrev;
    }
};