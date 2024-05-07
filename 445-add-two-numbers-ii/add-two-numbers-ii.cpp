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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> n1, n2;
        ListNode *t = l1, *head=NULL, *nn=NULL;
        while(t){
            n1.push_back(t->val);
            t = t->next;
        }
        t = l2;
        while(t){
            n2.push_back(t->val);
            t = t->next;
        }
        int i1 = n1.size()-1, i2 = n2.size()-1, carry = 0;
        while(i1 != -1 && i2 != -1){
            int addition = n1[i1] + n2[i2] + carry;
            int NodeVal = addition % 10;
            carry = addition / 10;
            nn = new ListNode(NodeVal, head);
            head = nn;
            i1--; i2--;
        }
        while(i1 != -1){
            int addition = n1[i1] + carry;
            int NodeVal = addition % 10;
            carry = addition / 10;
            nn = new ListNode(NodeVal);
            if(head)    nn->next = head;
            head = nn;
            i1--;
        }
        while(i2 != -1){
            int addition = n2[i2] + carry;
            int NodeVal = addition % 10;
            carry = addition / 10;
            nn = new ListNode(NodeVal);
            if(head)    nn->next = head;
            head = nn;
            i2--;
        }
        if(i1 == -1 && i2 == -1 && carry){
            nn = new ListNode(1);
            if(head)    nn->next = head;
            head = nn;
        }
        return head;
    }
};