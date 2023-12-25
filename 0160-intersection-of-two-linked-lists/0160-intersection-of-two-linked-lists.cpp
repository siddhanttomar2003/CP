/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempa=headA;
        ListNode *tempb=headB;
        set<ListNode *>s;
        while(tempa!=NULL){
            s.insert(tempa);
            tempa=tempa->next;
        }
        while(tempb!=NULL){
            if(s.find(tempb)!=s.end())return tempb;
            tempb=tempb->next;
        }
        return NULL;

        return NULL;
    }
};