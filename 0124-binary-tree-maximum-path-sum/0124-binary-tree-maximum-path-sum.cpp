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
    int cal_maxi(int &maxi,TreeNode * root){
        if(root==NULL)return 0;
        int value=root->val;
        int l=cal_maxi(maxi,root->left);
        int r=cal_maxi(maxi,root->right);
        int rr=-1e9,ll=-1e9,t=-1e9;
        if(r>0)rr=r+value;
        if(l>0)ll=l+value;
        maxi=max({maxi,rr,ll,value,rr+ll-value});
        return max({rr,ll,value});
    }
    int maxPathSum(TreeNode* root) {
      int maxi=-1e9;
     cal_maxi(maxi,root);
     return maxi;
      
    }
};
