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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* temp1= l1;
      ListNode* temp2= l2;
      ListNode* head=NULL;
      ListNode* tail=NULL;
      int carry=0;
      int current=0;
      while(temp1!=NULL&&temp2!=NULL){
           current=(temp1->val+temp2->val+carry)%10;
       carry=(temp1->val+temp2->val+carry)/10;
          ListNode * newnode=new ListNode(current);
          if(head==NULL){
      head=newnode;
      tail=newnode;
      temp1=temp1->next;
      temp2=temp2->next;
          }
          else{
              tail->next=newnode;
              tail=newnode;
               temp1=temp1->next;
               temp2=temp2->next;
          }
           
      }
      while(temp1!=NULL){
          current=(temp1->val+carry)%10;
          carry=(temp1->val+carry)/10;
             ListNode * newnode=new ListNode(current);
          if(head==NULL){
      head=newnode;
      tail=newnode;
      temp1=temp1->next;
      
          }
          else{
              tail->next=newnode;
              tail=newnode;
               temp1=temp1->next;
              
          }
      }
        while(temp2!=NULL){
          current=(temp2->val+carry)%10;
          carry=(temp2->val+carry)/10;
             ListNode * newnode=new ListNode(current);
          if(head==NULL){
      head=newnode;
      tail=newnode;
      temp2=temp2->next;
      
          }
          else{
              tail->next=newnode;
              tail=newnode;
               temp2=temp2->next;
              
          }
         
      }
       if(carry==1){
               ListNode * newnode=new ListNode(carry);
               tail->next=newnode;
               tail=newnode;
          }
      return head;

    }
};