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
     ListNode * reverse(ListNode *head){
         if(head==NULL||head->next==NULL){
             return head;
         }
         ListNode *smallans=reverse(head->next);
         ListNode *temp=head->next;
         temp->next=head;
         head->next=NULL;
         return smallans;
     }
    bool isPalindrome(ListNode* head) {
        ListNode *start=head;
        if(head==NULL||head->next==NULL)return true;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp=reverse(slow->next);
        while(temp!=NULL){
            if(start->val!=temp->val)return false;
            start=start->next;
            temp=temp->next;
        }
        return true;
    }
};