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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)return;
        ListNode *temp=head;
        vector<ListNode *>v;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->next;
        }
         
        int i=1;int e=v.size()-1;
        ListNode * temp2=head;
        while(i<=e){
            if(i==e){
                temp2->next=v[i];
                temp2=v[i];
                temp2->next=NULL;
                i++;e--;
                continue;
            }
            temp2->next=v[e];
            temp2=v[e];
            e--;
            if(i<e){
            temp2->next=v[i];
            temp2=v[i];i++;
            }
            
        }
          

    }
};