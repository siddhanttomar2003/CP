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
typedef long long ll;
class Solution {
public:
    void cal(TreeNode * root, bool &ans, ll mini, ll maxi){
         if(root==NULL)return;
         if((ll)root->val<mini || (ll)root->val>maxi)ans=false;
         cal(root->left,ans,mini,root->val-1*1ll);
         cal(root->right,ans,root->val+1*1ll,maxi);
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        ll mini=-1e10;
        ll maxi=1e10;
        cal(root,ans,mini,maxi);
        return ans;
    }
};
