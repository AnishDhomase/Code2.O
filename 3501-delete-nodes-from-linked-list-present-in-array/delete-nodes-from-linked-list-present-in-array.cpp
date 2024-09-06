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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto num: nums)
            mp[num] ++;
        ListNode *t = head, *prev = NULL;
        while(t){
            if(mp[t->val]){ //delete
                if(t == head){
                    head = t->next;
                    delete t;
                    t = head;
                }
                else{
                    prev->next = t->next;
                    delete t;
                    t = prev->next;
                }
            }
            else{
                prev = t;
                t = t->next;
            }
        }
        return head;
    }
};