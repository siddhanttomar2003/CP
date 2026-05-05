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
    int len(ListNode* head){
        int count = 0;
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = len(head);
        if(n == 0)return nullptr;
        if(n == 1)return head;
        k = k % n;
        if(k == 0)return head;
        ListNode *temp = head;
        int save = n - k;
        ListNode* prev = NULL;
        while(temp != NULL && save--){
            prev = temp;
            temp = temp -> next;
        }
        while(temp != NULL && temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = head;
        head = prev -> next;
        prev -> next = NULL;
        return head;
    }
};