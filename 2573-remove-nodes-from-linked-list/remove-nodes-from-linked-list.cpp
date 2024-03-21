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
    void insertAtEnd(int val, ListNode **addrHead){
        if(*addrHead == NULL){
            *addrHead = new ListNode(val);
        }
        else{
            ListNode *nn = new ListNode(val, *addrHead);
            *addrHead = nn;
        }
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *aHead = NULL; 
        vector<int> copy;
        ListNode *t = head;
        while(t){
            copy.push_back(t->val);
            t = t->next;
        }
        stack<int> st;
        int n = copy.size();
        for(int i=n-1; i>=0; i--){
            while(st.size() && st.top()<=copy[i]){
                st.pop();
            }
            if(!st.size())
                insertAtEnd(copy[i], &aHead);
            st.push(copy[i]);
        }
        return aHead;
    }
};