/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *cal (TreeNode * root, TreeNode *p, TreeNode * q){
        if(root == NULL)return NULL;
        TreeNode * left = cal(root -> left, p, q);
        TreeNode * right = cal(root -> right, p, q);
        if(root == p){
            return root;
        }
        else if(root == q)return root;
        else if(left != NULL && right != NULL)return root;
        else if(left != NULL)return left;
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return cal(root, p, q);
    }
};