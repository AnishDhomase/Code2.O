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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp, *start, *end, *list2End;
        int i=0;
        temp=list1;
        while(i!=b){
            if(i == a-1)    start = temp;
            temp=temp->next;
            i++;
        }
        end=temp;

        temp=list2;
        while(temp->next){
            temp=temp->next;
        }
        list2End = temp;

        start->next = list2;
        list2End->next=end->next;

        return list1;

    }
};