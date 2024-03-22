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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode *t = head, *pHead;
        int n = 0;
        while(t){
            n++;
            t = t->next;
        }
        int bigParts = n%k, smallParts = n-bigParts, i=0;
        int generalLenOfPart = n/k;
        pHead = head;
        t = head;
        while(t){
            i++;
            if(bigParts){
                if(i == generalLenOfPart+1){
                    ans.push_back(pHead);
                    bigParts--;
                    pHead = t->next;
                    t->next = NULL;
                    t = pHead;
                    i=0;
                    continue;
                }
                t=t->next;
            }
            else{
                if(i == generalLenOfPart){
                    ans.push_back(pHead);
                    smallParts--;
                    pHead = t->next;
                    t->next = NULL;
                    t = pHead;
                    i=0;
                    continue;
                }
                t=t->next;
            }
        }
        while(ans.size() != k){
            ans.push_back(NULL);
        }
        return ans;
    }
};