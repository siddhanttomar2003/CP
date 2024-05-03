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
    int cal_nodes(ListNode *head){
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int n=cal_nodes(head);
        int right=k%n;
        int target=n-right;
        ListNode *temp=head;
        ListNode *hold=NULL;
        ListNode *last=head;
        while(last->next!=NULL){last=last->next;}
        while(target>1){
         temp=temp->next;
         target--;
        }
       last->next=head;
       head=temp->next;
       temp->next=NULL;
       return head;


    }
};