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
    int pairSum(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        int n=0;
        while(fast->next->next!=NULL&&fast!=NULL){
            slow=slow->next;
            n++;
            fast=fast->next->next;
        }
        ListNode *newhead=slow->next;
        ListNode *prev=slow;
        ListNode *newnode=newhead;
         while(newnode!=NULL){
             newnode=newhead->next;
             newhead->next=prev;
             prev=newhead;
             newhead=newnode;
         }
         ListNode * head2=prev;
         int sum=0;
         int ans=0;
         while(n>=0)
         {
        sum+=head->val+head2->val;
        ans=max(ans,sum);
        sum=0;
        head=head->next;
        head2=head2->next;
        n--;
         }
         return ans;

    }
};