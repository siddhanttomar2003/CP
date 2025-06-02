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
    pair<bool,bool> find_lca(TreeNode * root, TreeNode * p, TreeNode *q, bool &flag1 , bool &flag2, TreeNode*  &ans){
        if(root==NULL)return {false,false};
       pair<bool,bool>p1= find_lca(root->left,p,q,flag1,flag2,ans);
       pair<bool,bool>p2= find_lca(root->right,p,q,flag1,flag2,ans);
       bool l=p1.first|p2.first|(p==root);
       bool r=p2.second|p1.second|(q==root);
       if(l && r && !ans){
           ans=root;
       }
       return {l,r};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag_p,flag_q;
        flag_p=false,flag_q=false;
        TreeNode * ans=NULL;
        find_lca(root,p,q,flag_p,flag_q,ans);
        return ans;
    }
};