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
     TreeNode * travel(TreeNode *root, vector<TreeNode *>&ans , map<int,int> &mp){
        if(root==NULL)return NULL;
         TreeNode *l=travel(root->left,ans,mp);
         TreeNode *r=travel(root->right,ans,mp);
         if(mp.find(root->val)!=mp.end()){
            root=NULL;
            if(l!=NULL)ans.push_back(l);
            if(r!=NULL)ans.push_back(r);
            return root;
         }
         root->left=l;
         root->right=r;
         return root;

     }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        map<int,int>mp;
        for(int i=0;i<to_delete.size();i++){
            mp[to_delete[i]]++;
        }
        travel(root,ans,mp);
        if(mp.find(root->val)==mp.end())ans.push_back(root);
        return ans;
    }
};