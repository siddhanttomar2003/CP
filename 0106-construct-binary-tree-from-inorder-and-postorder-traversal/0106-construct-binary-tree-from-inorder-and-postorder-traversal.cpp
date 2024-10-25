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
    TreeNode *construct(vector<int>&postorder, int post_s, int post_e, vector<int>&inorder, int in_s, int in_e, map<int,int>&mp){
        if(post_s>post_e || in_s>in_e)return NULL;
        TreeNode *root=new TreeNode (postorder[post_e]);
        int ind=mp[postorder[post_e]];
        int right_ele=in_e-ind;
        root->right=construct(postorder, post_e-right_ele,post_e-1,inorder,ind+1,in_e,mp);
        root->left=construct(postorder,post_s,post_e-right_ele-1,inorder,in_s,ind-1,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        if(postorder[0]==-1){
            TreeNode *temp=new TreeNode(-1);
            return temp;
        }
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
       return construct(postorder,0,n-1,inorder,0,n-1,mp);
    }
};