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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int start=0;
        int end=m-1;
        int left=0;
        int right=n-1;
        int i=start;
        int j=left;
        ListNode *temp=head;
        while(start<=end || left<=right && temp!=NULL){
            while(j<=right && temp!=NULL){
                ans[i][j]=temp->val;
                temp=temp->next;
                j++;
            }
            j--;
            start++; i=start;
            while(i<=end && temp!=nullptr){
                ans[i][j]=temp->val;
                temp=temp->next;
                i++;
            }
            i--;
            right--;j=right;
            while(j>=left && temp!=NULL){
                 ans[i][j]=temp->val;
                 temp=temp->next;
                 j--;
            }
            j++;
            end--;i=end;
            while(i>=start && temp!=nullptr){
                 ans[i][j]=temp->val;
                 temp=temp->next;
                 i--;
            }
            i++;
            left++;j=left;
        }
        return ans;

    }
};