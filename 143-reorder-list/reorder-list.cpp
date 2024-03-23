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
    void listTrav(ListNode *h, vector<ListNode*> &arr){
        while(h){
            arr.push_back(h);
            h = h->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        listTrav(head, list);
        int n = list.size(), i=0, j=n-1;
        while(i<j){
            list[i]->next = list[j];
            if(i+1 < j)
                list[j]->next = list[i+1];
            else
                list[j]->next = NULL;
            i++;
            j--;
        }
        if(i==j){
            list[j]->next = NULL;
        }
    }
};