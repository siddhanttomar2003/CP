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
    int numComponents(ListNode* head, vector<int>& nums) {
      int count=0;
      ListNode *temp=head;
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++)mp[nums[i]]++;
      while(temp!=NULL){
        bool flag=false;
        while(temp!=NULL && mp.find(temp->val)!=mp.end()){
            flag=true;
            temp=temp->next;
        }
        if(flag)count++;
        if(temp!=NULL)temp=temp->next;
      }
      return count;
    }
};