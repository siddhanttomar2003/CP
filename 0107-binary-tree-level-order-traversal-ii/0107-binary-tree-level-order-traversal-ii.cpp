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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode *>q;
         q.push(root);
         q.push(NULL);
         vector<int>v;
         while(q.size()>1){
             if(q.front()==NULL){
                  ans.push_back(v);
                 v.clear();
                 q.pop();
                 q.push(NULL);        
                 continue;
             }
             TreeNode *first=q.front();
             q.pop();
             v.push_back(first->val);
             if(first->left!=NULL)q.push(first->left);
             if(first->right!=NULL)q.push(first->right);
         }
         ans.push_back(v);
         reverse(ans.begin(),ans.end());

         return ans;
    }
};