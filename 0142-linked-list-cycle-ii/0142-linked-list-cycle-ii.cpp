/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *,int>mp;
        ListNode *temp=head;
        while(temp!=NULL){
            mp[temp]++;
            if(mp[temp]==2)return temp;
            temp=temp->next;
        }
        return NULL;
    }
};