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
    int numComponents(ListNode* head, vector<int>& nums) {
        int componentsCt = 0;
        unordered_set<int> numss;
        for(auto num : nums)
            numss.insert(num);
        ListNode *t = head;
        int streak = 0;
        while(t){
            if(numss.find(t->val) != numss.end()){
                numss.erase(t->val);
                streak++;
            }
            else{
                if(streak){
                    componentsCt++;
                    streak = 0;
                }
            }
            t = t->next;
        }
        if(streak)  componentsCt++;
        return componentsCt;
        
        
    }
};