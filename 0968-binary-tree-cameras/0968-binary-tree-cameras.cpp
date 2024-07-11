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
    int recur(TreeNode *root, int &cameras,TreeNode *mainroot){
        if(root==NULL)return 1;
          if(root->left==NULL && root->right==NULL)return -1;
        int a= recur(root->left,cameras,mainroot);
        int b= recur(root->right,cameras,mainroot);
        if(a==(-1) || b==(-1)){
            cameras++;
            return 0;
        }
        else if(a==0 || b==0){
            return 1;
        }
        else {
            if(root==mainroot)cameras++;
             return -1;
        }
    }
    int minCameraCover(TreeNode* root) {
        int cameras=0;
        TreeNode *mainroot=root;
        if(root->left==NULL && root->right==NULL)return 1;
      recur(root,cameras,mainroot);
      return cameras;
    }
};