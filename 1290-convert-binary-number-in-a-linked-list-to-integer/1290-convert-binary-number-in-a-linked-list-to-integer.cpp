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
    ListNode * reverse_ll(ListNode * &head){
        if(head -> next == NULL)return head;
        ListNode * mhead = reverse_ll(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return mhead;
    }
    int getDecimalValue(ListNode* head) {
        head = reverse_ll(head);
        int num = 0;
        int curr = 0;
        ListNode * temp = head;
        while(temp != NULL){
            if(temp -> val == 1){
                num += pow(2, curr);
            }
            // cout << temp -> val << endl;
            temp = temp -> next;
            curr++;
        }
        return num;
    }
};