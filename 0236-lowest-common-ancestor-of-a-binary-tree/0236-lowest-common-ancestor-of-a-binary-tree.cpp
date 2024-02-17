/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * recur(TreeNode *root, TreeNode* p, TreeNode* q,TreeNode * &ans){
     if(root==NULL)return NULL;
     if(root->val==p->val||root->val==q->val){
         return root;
     }
     TreeNode * left=recur(root->left,p,q,ans);
     TreeNode * right=recur(root->right,p,q,ans);
     if(left!=NULL ||right!=NULL){
         if(left!=NULL&&right!=NULL)return root;
         else if(left==NULL)return right;
     }
     return left;
     

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans=nullptr;
       return recur(root,p,q,ans);


    }
};