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
    ListNode* removeNodes(ListNode* head) {
        // find the leaders in the array
        vector<int>vec;
        ListNode *temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int maxi=vec[vec.size()-1];
        for(int i=vec.size()-2;i>=0;i--){
            maxi=max(maxi,vec[i]);
            vec[i]=maxi;
        }
        
        ListNode *newhead=NULL;
        ListNode *tail=NULL;
        ListNode *tempi=head;
        int i=0;
        while(tempi!=NULL){
            if(tempi->val==vec[i]){
                ListNode *newnode=new ListNode(tempi->val);;
                if(newhead==NULL){
                    newhead=newnode;
                    tail=newnode;
                }
                else {
                    tail->next=newnode;
                    tail=tail->next;
                }
            }
            tempi=tempi->next;i++;

        }
        return newhead;
    }
};