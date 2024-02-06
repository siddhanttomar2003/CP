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
   int recur(TreeNode*root,bool &ans){
 if(root==NULL)return 0;
   int height_left=recur(root->left,ans);
   int height_right=recur(root->right,ans);
   if(abs(height_left-height_right)>1){
	   ans=false;
   }
   return 1+max(height_right,height_left);

 }
    bool isBalanced(TreeNode* root) {
        bool ans=true; 
	 int sum=recur(root,ans);
	return ans;
    }
};