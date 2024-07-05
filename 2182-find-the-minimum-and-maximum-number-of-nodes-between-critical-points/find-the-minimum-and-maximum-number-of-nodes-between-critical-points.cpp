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
    bool isCriticalPoint(ListNode *curr, ListNode *prev){
        if(prev == NULL)    return false;
        if(curr -> next == NULL)    return false;
        if(prev->val < curr->val && curr->val > curr->next->val)    return true;
        if(prev->val > curr->val && curr->val < curr->next->val)    return true;
        return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCriticalPt = -1, lastCriticalPt = -1, ind = 0, prevCriticalPt = -1;
        int minDist = INT_MAX, maxDist;
        ListNode *prev = NULL, *curr = head;
        while(curr){
            if(isCriticalPoint(curr, prev)){
                if(prevCriticalPt != -1)
                    minDist = min(ind - prevCriticalPt, minDist);
                prevCriticalPt = ind;
                if(firstCriticalPt == -1) firstCriticalPt = ind;
                else lastCriticalPt = ind;
            }
            prev = curr;
            curr = curr -> next;
            ind ++;
        }
        if(lastCriticalPt == -1)    return {-1,-1};
        maxDist = lastCriticalPt - firstCriticalPt;
        return {minDist, maxDist};
    }
};