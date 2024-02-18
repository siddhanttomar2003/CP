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
     void inorder(TreeNode *root,vector<int> &v){
         if(!root)return;
         inorder(root->left,v);
         v.push_back(root->val);
         inorder(root->right,v);
     }
     TreeNode * update(TreeNode *root,unordered_map<int,int>&mp){
         if(!root)return nullptr;
         root->val=mp[root->val];
         update(root->left,mp);
         update(root->right,mp);
         return root;
     }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return nullptr;
        vector<int>v;
        inorder(root,v);
        int size=v.size();
        long long sum=v[size-1];
        unordered_map<int,int>mp;
        mp[sum]=sum;
        for(int i=size-2;i>=0;i--){
            sum+=v[i];
            mp[v[i]]=sum;
        }
       return update(root,mp);
    }
};