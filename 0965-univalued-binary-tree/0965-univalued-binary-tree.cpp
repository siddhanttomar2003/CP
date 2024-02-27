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
     void recur(unordered_map<int,int> &mp,TreeNode *root){
         if(root==NULL)return;
         mp[root->val]++;
         recur(mp,root->left);
         recur(mp,root->right);
     }
    bool isUnivalTree(TreeNode* root) {
     unordered_map<int,int>mp;
     recur(mp,root);
     if(mp.size()>1)return false;
     else return true;

    }
};