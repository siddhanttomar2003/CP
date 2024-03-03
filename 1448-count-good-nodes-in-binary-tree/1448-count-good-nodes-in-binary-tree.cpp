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
     void recur(TreeNode *root,int &ans,int &prev,int maxi){
         if(root==NULL)return;
         if(root->left==NULL && root->right==NULL){
             if(root->val>=prev){
            ans++;
             }
             return;
         }
         if(root->val>=prev){
             ans++;prev=root->val;
             maxi=max(maxi,root->val);
         }
         recur(root->left,ans,prev,maxi);
          prev=maxi;
         recur(root->right,ans,prev,maxi);
        

     }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int prev=INT_MIN;
        int maxi=INT_MIN;
        recur(root,ans,prev,maxi);
        return ans;
    }
};