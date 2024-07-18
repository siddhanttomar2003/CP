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

    int cal(TreeNode *root, int &ans){
        if(root==NULL)return 0;
        // ans=max(ans,root->val);
        int a=cal(root->left,ans);
        int b=cal(root->right,ans);
        ans=max(ans,max(root->val,root->val+a+b));
        ans=max(ans,max(root->val+a,root->val+b));
        return max(root->val,root->val+max(a,b));
        
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
       cal(root,ans);
        return ans;
    }
};