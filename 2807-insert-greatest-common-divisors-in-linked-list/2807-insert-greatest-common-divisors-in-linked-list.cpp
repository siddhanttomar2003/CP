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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // ListNode *temp=head;
        ListNode *start=head;
        ListNode *nx=head->next;
        while(nx!=NULL){
            int gg=__gcd(start->val,nx->val);
            ListNode *temp=new ListNode(gg);
            temp->next=start->next;
            start->next=temp;
            start=start->next->next;
            nx=nx->next;
        }
        return head;

    }
};