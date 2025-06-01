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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1=list1;
        ListNode *head2=list2;
        ListNode *last=NULL;
        ListNode *newhead=NULL;
    while(head1!=NULL && head2!=NULL){
        if(newhead==NULL){
            if(head1->val<head2->val){
                newhead=head1;
                last=head1;
                head1=head1->next;
            }
            else {
                newhead=head2;
                last=head2;
                head2=head2->next;
            }
        }
        else {
            if(head1->val<head2->val){
                last->next=head1;
                last=head1;
                head1=head1->next;
            }
            else {
                last->next=head2;
                last=head2;
                head2=head2->next;
            }
        }
    }
    while(head1!=NULL){
        if(newhead==NULL){
            newhead=head1;
            last=head1;
        }
        else {
        last->next=head1;
        last=head1;
        }
        head1=head1->next;
    }
    while(head2!=NULL){
        if(newhead==NULL){
            newhead=head2;
            last=head2;
        }
        else {
        last->next=head2;
        last=head2;
        }
        head2=head2->next;
    }
    return newhead;
        
    }
};
