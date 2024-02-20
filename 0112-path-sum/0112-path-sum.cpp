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
    bool recur(TreeNode *root,int targetSum,int sum ){
        if(root==NULL)return false;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum)return true;
            else return false;
        }
        bool ans_left=recur(root->left,targetSum,sum);
        bool ans_right=recur(root->right,targetSum,sum);
        return ans_left||ans_right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        int sum=0;
         return recur(root,targetSum,sum);

    }
};