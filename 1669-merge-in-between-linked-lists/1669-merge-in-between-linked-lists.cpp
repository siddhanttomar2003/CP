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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      // lets first connect  a point to head of ll2
      ListNode *temp=list1;
      while(a>1){
        temp=temp->next;
        a--;
      }
      // now lets find out the tail of list2 
      ListNode *temp2=list2;
      while(temp2->next!=NULL){
        temp2=temp2->next;
      }
      // now lets connect the tail to the b point of list2
      ListNode *temp3=list1;
      while(b>=0){
        temp3=temp3->next;
        b--;
      }
     temp->next=list2;
     temp2->next=temp3;
     return list1;
    }
};