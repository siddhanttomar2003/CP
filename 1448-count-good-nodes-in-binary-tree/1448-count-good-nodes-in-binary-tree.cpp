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
    void cal(TreeNode *root, int &count, int maxi){
        if(root==NULL)return;
        if(root->val>=maxi)count++;
        maxi=max(maxi,root->val);
        cal(root->left,count,maxi);
        cal(root->right,count,maxi);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        cal(root,count,-1e5);
        return count;
    }
};