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
    ListNode* insertAsItis(vector<int> gpArr, ListNode **addrHead, ListNode *lastNode){
        int n = gpArr.size();
        for(int i=0; i<n; i++){
            ListNode *nn = new ListNode(gpArr[i]);
            if(lastNode == NULL){
                *addrHead = nn;
                lastNode = nn;
            }
            else{
                lastNode->next = nn;
                lastNode = nn;
            }
        }
        return lastNode;
    }
    ListNode* insertRev(vector<int> gpArr, ListNode **addrHead, ListNode *lastNode){
        int n = gpArr.size();
        for(int i=n-1; i>=0; i--){
            ListNode *nn = new ListNode(gpArr[i]);
            if(lastNode == NULL){
                *addrHead = nn;
                lastNode = nn;
            }
            else{
                lastNode->next = nn;
                lastNode = nn;
            }
        }
        return lastNode;
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *aHead=NULL, *t=head, *last=NULL;
        int gp = 1;
        int ithMemberOfGrp = 1;
        vector<int> gpArr;
        while(t){
            while(t && ithMemberOfGrp <= gp){
                gpArr.push_back(t->val);
                ithMemberOfGrp++;
                t = t->next;
            }
            int actualGpSize = ithMemberOfGrp - 1;
            if(actualGpSize % 2)
                last = insertAsItis(gpArr, &aHead, last);
            else
                last = insertRev(gpArr, &aHead, last);
            gp++;
            ithMemberOfGrp = 1;
            gpArr.clear();
        }
        return aHead;

    }
};