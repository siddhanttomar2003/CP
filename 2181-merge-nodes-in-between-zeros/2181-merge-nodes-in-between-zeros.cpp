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
    ListNode* mergeNodes(ListNode* head) {
        if(head->next==NULL)return NULL;
        ListNode *temp=head->next;
        ListNode *h=NULL;
        ListNode *t=NULL;
        int sum=0;
        while(temp!=NULL){
          while(temp!=NULL && temp->val!=0){
            sum+=temp->val;
            temp=temp->next;
          }
          ListNode *newnode= new ListNode(sum);
          if(h==NULL){
            h=newnode;
            t=newnode;
          }
          else {
            t->next=newnode;
            t=newnode;
          }
          sum=0;
          temp=temp->next;
        }
        return h;
    }
};