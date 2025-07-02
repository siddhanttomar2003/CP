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
    ListNode* rev_ll(ListNode * head){
        if(head == NULL ||  head -> next == NULL)return head;
        ListNode * mhead = rev_ll(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return mhead;
    }
    int get_len(ListNode * head){
        ListNode * temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==  NULL )return nullptr;
        int len = get_len(head);
        k %= len;
        if(k == 0)return head;
        head = rev_ll(head);
        ListNode * temp = head;
        ListNode * last_head = head;
        ListNode * nhead = head;
        // while(temp != NULL){
        //     cout << temp -> val << " ";
        //     cout << endl;
        //     temp = temp -> next;
        // }
        while(k--){
            if(k == 0){
               ListNode * store = temp -> next;
               ListNode * curr = last_head;
               ListNode * prev = NULL;
               while(curr != store){
                 ListNode * next = curr -> next;
                 curr -> next = prev;
                 prev = curr;
                 curr = next;
               }
               head = prev;
               ListNode * curr2 = store;
               ListNode * prev2 = NULL;
               while(curr2 != NULL){
                 ListNode * next = curr2 -> next;
                 curr2 -> next = prev2;
                 prev2 = curr2;
                 curr2 = next;
               }
               last_head -> next = prev2;
               return head;
            }
            temp = temp -> next;
        }
        return head;
    }
};