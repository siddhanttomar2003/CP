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
    void recur(TreeNode *root, TreeNode *newnode){
       if(root->val>newnode->val){
           if(root->left==NULL){
               root->left=newnode;
               return;
           }
           else{
               recur(root->left,newnode);
           }
       }
       else{
           if(root->right==NULL){
               root->right=newnode;
               return;
           }
           else{
               recur(root->right,newnode);
           }
       }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode * newnode= new TreeNode(val);
         if(root==NULL){
             return newnode;
         }
        recur(root,newnode);
        return root;
    }
};