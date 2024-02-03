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
    int recur(TreeNode *root,vector<int>&v){
         if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return 1;
        int l=recur(root->left,v);
        int r=recur(root->right,v);
        v.push_back(l+r);
        return max(l+1,r+1);
       
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        vector<int>v;
        recur(root,v);
        int maxi=0;
        for(int i=0;i<v.size();i++){
            if(maxi<v[i])maxi=v[i];
        }
        return maxi;
    }
};