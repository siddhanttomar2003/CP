/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()>0){
           int size=q.size();
           long long c_sum=0;
           for(int i=0;i<size;i++){
               TreeNode *curr=q.front();
               q.pop();
               c_sum+=curr->val;
               if(curr->left!=NULL){
                q.push(curr->left);
               }
               if(curr->right!=NULL){
                q.push(curr->right);
               }
           }
           pq.push(c_sum);
           if(pq.size()>k){
            pq.pop();
           }
        }
        if(pq.size()<k)return -1;
        return pq.top();
    }
};