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
        vector<pair<int,ListNode *>>ans;
        for(int i=0;i<lists.size();i++){
            ListNode *temp=lists[i];
            while(temp!=NULL){
                ans.push_back({temp->val,temp});
                temp=temp->next;
            }
        }
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++){
            if(i==ans.size()-1)ans[i].second->next=NULL;
            else 
            ans[i].second->next=ans[i+1].second;
        }
        if(ans.size()==0)return NULL;
        return ans[0].second;
    }
};