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
    int sizeOfLL(ListNode *hd){
        int sz = 0;
        while(hd){
            sz++;
            hd = hd -> next;
        }
        return sz;
    }
    ListNode* mergeLLs(ListNode *h1, ListNode *h2){
        ListNode *mhd = NULL, *nn=NULL, *last=NULL;
        while(h1 && h2){
            if(h1->val < h2->val){
                nn = new ListNode(h1->val);
                h1 = h1->next;
            }
            else{
                nn = new ListNode(h2->val);
                h2 = h2->next;
            }
            
            if(last)    last->next = nn;
            else    mhd = nn;
            last = nn;
            
        }
        while(h1){
            nn = new ListNode(h1->val);
            h1 = h1->next;

            if(last)    last->next = nn;
            else    mhd = nn;
            last = nn;
        }
        while(h2){
            nn = new ListNode(h2->val);
            h2 = h2->next;
            
            if(last)    last->next = nn;
            else    mhd = nn;
            last = nn;
        }
        return mhd;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> heap;
        for(auto hd : lists){
            int szOfLL = sizeOfLL(hd);
            if(szOfLL)
                heap.push({szOfLL,hd});
        }
        while(heap.size() >= 2){
            int sz1 = heap.top().first;
            ListNode *h1 = heap.top().second;
            heap.pop();
            int sz2 = heap.top().first;
            ListNode *h2 = heap.top().second;
            heap.pop();
            ListNode *mhd = mergeLLs(h1,h2);
            heap.push({sz1+sz2, mhd});
        }
        if(!heap.size())    return NULL;    
        return heap.top().second;
    }
};