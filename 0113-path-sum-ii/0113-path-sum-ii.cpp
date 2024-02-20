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
     void recur(TreeNode *root, int targetSum,int sum, vector<int> &v,vector<vector<int>>&ans){
         if(root==NULL)return;
         sum+=root->val;
         v.push_back(root->val);
         if(root->left==NULL&&root->right==NULL){
             if(sum==targetSum){
                 ans.push_back(v);
             }
             v.pop_back();
             return;
         }
         recur(root->left,targetSum,sum,v,ans);
         recur(root->right,targetSum,sum,v,ans);
         v.pop_back();
     }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        int sum=0;
        recur(root,targetSum,sum,v,ans);
         return ans;
    }
};