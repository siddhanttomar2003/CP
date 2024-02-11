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
    bool recur(TreeNode *root, long long mini, long long maxi){
        if(root==NULL)return true;
        if(root->val<mini+1 || root->val>maxi-1){
            return false;
        }
        
        bool check_left=recur(root->left,mini,root->val);
        bool check_right=recur(root->right,root->val,maxi);
        return check_left&&check_right;
    }
    bool isValidBST(TreeNode* root) {
        // top to down approach
        long long int mini=-1000000000000;        
        long long int maxi=1000000000000;
          bool ans=recur(root,mini,maxi);
          return ans;
    }
};