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
    ListNode* doubleIt(ListNode* head) {
        // first reverse it
        // then travel and update at the same time
        ListNode *prev=NULL;
        ListNode *nex=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
             prev=curr;
             curr=nex;
        }
        int carry=0;
        ListNode *rev=prev;
        while(prev!=NULL){
         int a=(prev->val)*2;
         prev->val=(a+carry)%10;
         carry=(a+carry)/10;
         if(prev->next== NULL && carry>0){
            ListNode *newnode=new ListNode (carry);
            prev->next=newnode;
            prev=prev->next;
            break;
         }
         prev=prev->next;
        }
        ListNode *temp2=rev;// newhead but is reversed
        ListNode * prev2=NULL;
        ListNode *nex2=NULL;
        while(temp2!=NULL){
            nex2=temp2->next;
            temp2->next=prev2;
            prev2=temp2;
            temp2=nex2;
        }
          return prev2;
          
    }
};