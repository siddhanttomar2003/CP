/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL)return;
        
      ListNode *temp=node;

      while(temp!=NULL){
          if(temp->next->next==NULL){
              temp->val=temp->next->val;
               temp->next=NULL;
               temp=temp->next;
          }
          else{
          temp->val=temp->next->val;
          temp=temp->next;
          }
      }
       
      return;
        }
    
};