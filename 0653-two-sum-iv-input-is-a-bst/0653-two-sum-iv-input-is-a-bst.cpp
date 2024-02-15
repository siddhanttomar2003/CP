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
    void preorder(TreeNode *root, vector<int> &v){
        if(root==nullptr)return;
        preorder(root->left,v);
          v.push_back(root->val);
        preorder(root->right,v);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        preorder(root,v);
        int i=0;  int e=v.size()-1;
        while(i<e){
            int sum=v[i]+v[e];
            if(sum==k)return true;
            else if(sum<k)i++;
            else e--;
        }
        return false;
    }
};