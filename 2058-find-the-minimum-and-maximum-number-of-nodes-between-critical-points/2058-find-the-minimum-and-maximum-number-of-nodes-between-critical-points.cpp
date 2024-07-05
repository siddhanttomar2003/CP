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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL)return {-1,-1};
        ListNode *nex=head->next->next;
        ListNode *curr=head->next;
        ListNode *prev=head;
        int p1=-1;int p2=-1;int mini=INT_MAX;
        int s=-1;
        int i=1;
        while(nex!=NULL){
           int num1=curr->val;
           int num2=nex->val;
           int num=prev->val;
           if(num1>num && num1>num2 || num1<num && num1<num2){
            if(s==-1)s=i;
            if(p1==-1)p1=i;
            else if(p2==-1){
                p2=i;
                mini=min(mini,p2-p1);
            }
            else {
                p1=p2;
                p2=i;
                mini=min(mini,p2-p1);
            }
           }
           i++;
           curr=curr->next;
           nex=nex->next;
           prev=prev->next;
        }
        int maxi=-1;
        maxi=max(maxi,p2-s);
        if(p1>=0 && p2>0)return {mini,maxi};
        return {-1,-1};
    }
};