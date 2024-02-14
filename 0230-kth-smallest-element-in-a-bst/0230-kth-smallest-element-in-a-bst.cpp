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
    void recur(TreeNode* root, vector<int> &ans,int &a,int k){
        if(!root)return;
        recur(root->left,ans,a,k);
        ans.push_back(root->val);
        if(ans.size()==k){
            a=ans[k-1];
            return;
        }
        recur(root->right,ans,a,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int a;
        vector<int>ans;
        recur(root,ans,a,k);
      
        return a;
    }
};