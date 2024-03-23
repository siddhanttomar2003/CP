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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL)return head;
        if(left==right)return head;
        int a=1;
       ListNode *start=head;
       ListNode *end=head;
       while(a!=left){
        start=start->next;
         a++;
       }
       int b=1;
       while(b!=right){
         end=end->next;
         b++;
       }
       ListNode *prev=end->next;
       ListNode *next=NULL;
       int s=left;int e=right;
       while(s<=e){
         next=start->next;
         start->next=prev;
         prev=start;
         start=next;
         s++;
       }
       ListNode *start_prev=head;
       int c=1;
       while(c<left-1&&left!=1){
        start_prev=start_prev->next;
        c++;
       }
       if(left!=1){
        start_prev->next=prev;
       }
       else{
        head=prev;
       }
       return head;
    }
};