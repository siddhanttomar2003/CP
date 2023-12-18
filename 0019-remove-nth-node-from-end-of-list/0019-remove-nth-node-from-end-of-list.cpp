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
    int length(ListNode *head){
        ListNode *temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp=head;
        int len=length(head);
        if(n>len){
            return head;
        }
        if(n==len){
            head=head->next;
            return head;
        }
        int tar=len-n+1;
        int start=1;
        while(start<tar-1){
            temp=temp->next;
            start++;
        }
        temp->next=temp->next->next;
        return head;



    }
};