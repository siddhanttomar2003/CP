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
    int curr = 0;
    int num = 0;
    ListNode * reverse_ll(ListNode * &head){
        if(head -> next == NULL){
            if(head -> val)
            num += pow(2, curr);
            curr++;
            return head;
        }
        ListNode * mhead = reverse_ll(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        if(head -> val){
            num += pow(2, curr);
        }
        curr++;
        return mhead;
    }
    int getDecimalValue(ListNode* head) {
        head = reverse_ll(head);
        return num;
    }
};