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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
            pq.push({lists[i]->val,lists[i]});
        }
        ListNode * head=NULL,*tail=NULL;
        while(pq.size()>0){
            ListNode *temp=pq.top().second;
            int num=pq.top().first;
            pq.pop();
            ListNode *newnode=new ListNode(num);
            if(temp->next!=NULL){
                pq.push({temp->next->val,temp->next});
            }
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }
            else {
                tail->next=newnode;
                tail=newnode;
            }
        }
        return head;
    }
};
