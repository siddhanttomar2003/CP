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
     void traversal(TreeNode * root,vector<int> &ans){
         if(!root)return;
         ans.push_back(root->val);
         traversal(root->left,ans);
         traversal(root->right,ans);
     }
    TreeNode * buildBST(vector<int> &ans,int i,int e){
        if(i>e)return nullptr;
        int mid=i+(e-i)/2;
        TreeNode * root=new TreeNode(ans[mid]);
        root->left=buildBST(ans,i,mid-1);
        root->right=buildBST(ans,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        traversal(root,ans);
        sort(ans.begin(),ans.end());
        int i=0;int e=ans.size()-1;
      return  buildBST(ans,i,e);
    }
};