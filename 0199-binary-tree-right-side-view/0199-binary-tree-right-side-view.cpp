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
    void cal(vector<int>&ans,TreeNode *root,int d){
        if(root==NULL)return ;
        if(ans.size()==d){
            ans.push_back(root->val);
        }
        cal(ans,root->right,d+1);
        cal(ans,root->left,d+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        cal(ans,root,0);
        return ans;
    }
};