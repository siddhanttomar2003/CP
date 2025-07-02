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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        if(k == 0)return head;
        int count = k;
        ListNode * last = NULL;
        ListNode * prev_head = head;
        bool check = false;
        while(temp != NULL){
            count --;
            if(count == 0){
               count = k;
               ListNode * store = temp -> next;
               ListNode * prev = NULL;
               ListNode * curr = prev_head;
               while(curr != store){
                   ListNode * next = curr -> next;
                   curr -> next = prev;
                   prev = curr;
                   curr = next;
               }
               if(!check){
                head = prev;
                check = true;
               }
               if(last != NULL){
                last -> next = temp;
               }
               last = prev_head;
               prev_head -> next = store;
               prev_head = store;
               temp = store;
            }
            else {
               temp = temp -> next;
            }
        }
        return head;
    }
};