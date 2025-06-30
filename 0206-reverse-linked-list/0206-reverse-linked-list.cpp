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
    void  rev(ListNode * &head, ListNode * &last){
        ListNode * temp = head -> next;
        head -> next = last;
        last = head;
        if(temp != NULL){
          head = temp;
          rev(head , last);
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return NULL;
        if(head -> next == NULL)return head;
        ListNode * last = NULL;
        rev(head,last);
        return head;
    }
};