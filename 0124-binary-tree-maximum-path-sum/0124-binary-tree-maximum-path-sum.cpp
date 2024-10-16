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
    int cal(TreeNode * root , int &ans){
        if(root==NULL)return 0;
        int left=cal(root->left,ans);
        int right=cal(root->right,ans);
        int temp=max({ans,left+root->val,right+root->val,left+right+root->val});
        int choose=max(left+root->val,right+root->val);
        ans=max(ans,temp);
        return choose;
    }
    int maxPathSum(TreeNode* root) {
        int ans=-1e8;
        cal(root,ans);
        return ans;
    }
};