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
    ListNode * rev_ll(ListNode * &head ){
        if(head -> next == NULL)return head;
        ListNode * nhead = rev_ll(head -> next);
        ListNode * prev = NULL;
        head -> next -> next = head;
        head -> next = prev;
        return nhead;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)return NULL;
        if(head -> next == NULL){
            if(n == 1)return NULL;
            return head;
        }
        ListNode * temp = rev_ll(head);
        ListNode * nhead = temp;
        ListNode * last = temp;
        if(n == 1){
            return rev_ll(temp -> next);
        }
        while(temp != NULL){
            n--;
            if(n == 0){
                last -> next = temp -> next;
                return rev_ll(nhead);
            }
            last = temp;
            temp = temp -> next;
        }
        return NULL;
    }
};