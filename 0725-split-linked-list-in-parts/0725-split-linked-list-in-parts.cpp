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
    int count(ListNode *head){
        ListNode *temp=head;
        int ans=0;
        while(temp!=NULL){
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=count(head);
        int per=len/k;
        int rem=len%k;
        ListNode *temp=head;
        ListNode *start=head;
        int curr=0;
        cout<<len<<" "<<rem<<endl;
        vector<ListNode *>ans;
        if(per==0){

            while(temp!=NULL){
                ListNode *t=temp->next;
                temp->next=NULL;
                ans.push_back(temp);
                temp=t;
            }
            int rr=k-rem;
            while(rr--){
                ans.push_back(nullptr);
            }
            return ans;

        }
        while(temp!=NULL){
          curr++;
          if(curr==per && rem>0){
            rem--;
            temp=temp->next;
            curr=0;
            ListNode *temp2=temp->next;
            temp->next=NULL;
            temp=temp2;
            ans.push_back(start);
            start=temp2;
            curr=0;
          }
          else if(curr==per){
            curr=0;
            ans.push_back(start);
            ListNode *temp2=temp->next;
            temp->next=NULL;
            temp=temp2;
            start=temp2;
          }
          else {
              temp=temp->next;
          }
        }
        return ans;

    }
};