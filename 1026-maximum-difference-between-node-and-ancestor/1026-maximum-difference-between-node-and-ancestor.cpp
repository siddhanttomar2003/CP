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
    int maxDiff=-1;
    void findDiff(TreeNode *root,TreeNode *child){
        if(root==NULL||child==NULL)return;
        maxDiff=max(maxDiff,abs(root->val-child->val));
        findDiff(root,child->left);
        findDiff(root,child->right);
    }
    void eachroot(TreeNode *root){
        if(root==NULL)return;
        findDiff(root,root->left);
        findDiff(root,root->right);
        eachroot(root->left);
        eachroot(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        eachroot(root);
        return maxDiff;

    }
};