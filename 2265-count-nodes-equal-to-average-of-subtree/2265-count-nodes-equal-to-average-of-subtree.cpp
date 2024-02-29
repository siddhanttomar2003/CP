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
    pair<int,int> recur(TreeNode * root,int &ans){
        int sum=0;
        if(root==NULL)return {sum,0};
        if(root->left==NULL &&root->right==NULL){
           ans++;
           sum+=root->val;
           return {sum,1}; 
        }
        pair<int,int>p1;
        pair<int,int>p2;
        p1=recur(root->left,ans);
        p2=recur(root->right,ans);
        int avg=(p1.first+p2.first+root->val)/(p1.second+p2.second+1);
        if(avg==root->val)ans++;
        return {(p1.first+p2.first+root->val),(1+p1.second+p2.second)};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        recur(root,ans);
        return ans;
    }
};