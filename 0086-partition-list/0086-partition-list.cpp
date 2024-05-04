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
    ListNode* partition(ListNode* head, int x) {
        // storing all values of elements greater or equal to x 
        vector<int>storegreater;
         vector<int>storelesser;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val>=x)storegreater.push_back(temp->val);
            else storelesser.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *temp2=head;
        int i1=0;int e1=storelesser.size();
        int i2=0; int e2=storegreater.size();
        while(temp2!=NULL){
            if(i1<e1){
             temp2->val=storelesser[i1];
             i1++;
            }
            else {
                temp2->val=storegreater[i2];
                i2++;
            }
            temp2=temp2->next;
        }
       return head;
    }
};