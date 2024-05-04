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
    TreeNode* replaceValueInTree(TreeNode* root) {
      queue<TreeNode *>q;
      q.push(root);
      unordered_map<int,int>mp;
      int level=0;
      while(q.size()>0){
        int size=q.size();
        int level_sum=0;
        for(int i=0;i<size;i++){
           TreeNode *temp=q.front();
           q.pop();
           level_sum+=temp->val;
           if(temp->left!=NULL){
            q.push(temp->left);
           }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
           
        }
               mp[level]=level_sum;
               level++;
      }
      queue<TreeNode *>qu;
      qu.push(root);
      root->val=0;
      int level1=0;
      while(qu.size()>0){
        int size=qu.size();
        for(int i=0;i<size;i++){
            TreeNode *temp=qu.front();
            qu.pop();
            int curr=0;
            if(temp->left!=NULL){
                 qu.push(temp->left);
                 curr+=temp->left->val;
            }
            if(temp->right!=NULL){
                qu.push(temp->right);
                curr+=temp->right->val;
            }
            if(mp.find(level1+1)!=mp.end() && curr<mp[level1+1]){
                if(temp->left!=NULL)temp->left->val=mp[level1+1]-curr;
                if(temp->right!=NULL)temp->right->val=mp[level1+1]-curr;
            }
            else {
                if(temp->left!=NULL)temp->left->val=0;
                if(temp->right!=NULL)temp->right->val=0;
            }
           
        }
        level1++;
      }
   return root;


    }
};