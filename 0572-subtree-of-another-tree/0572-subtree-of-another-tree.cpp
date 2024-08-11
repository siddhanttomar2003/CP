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
    bool check(TreeNode *a1, TreeNode *b1){
        if(a1==NULL && b1==NULL)return true;
        if(a1==NULL || b1==NULL)return false;
        if(a1->val!=b1->val)return false;
        bool l=check(a1->left,b1->left);
        bool r=check(a1->right,b1->right);
        return l&r;
    }
    bool cal(TreeNode *a1, TreeNode *b1,bool &ans){
        if(a1==NULL)return false;
        if(a1->val==b1->val){
           if(check(a1,b1))ans=true;
        }
        cal(a1->left,b1,ans);
        cal(a1->right,b1,ans);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        cal(root,subRoot,ans);
        return ans;
    }
};