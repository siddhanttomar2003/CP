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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return NULL;
       map<int,int>mp;
       ListNode *temp=head;
       while(temp!=NULL){
           mp[temp->val]++;
           temp=temp->next;
       }   
     ListNode *head1=NULL;
        ListNode *tail1=NULL;
       for(auto it:mp){
           if(it.second==1){
               ListNode *newnode=new ListNode(it.first);
              if(head1==NULL){
                  head1=newnode;
                  tail1=newnode;
                  
              }
               else{
                tail1->next=newnode;
                   tail1=tail1->next;
               }
           }
       }
       
      
      
       return head1;    
    }
};