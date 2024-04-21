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
     void recur(string &ans,string &curr,TreeNode *root){
        if(root==NULL)return;
        curr=curr+((char)(97+root->val));
        if(root->left==NULL && root->right==NULL){
            reverse(curr.begin(),curr.end());
            if(ans.size()==0)ans=curr;
            else 
            ans=min(ans,curr);
            reverse(curr.begin(),curr.end());
            curr.pop_back();
            return;
        }
        recur(ans,curr,root->left);
        recur(ans,curr,root->right);
        if(curr.size()>0)curr.pop_back();
        
      
     
     }
    string smallestFromLeaf(TreeNode* root) {
       string ans="";
       string curr="";
       recur(ans,curr,root);      
       return ans;  
    }
};