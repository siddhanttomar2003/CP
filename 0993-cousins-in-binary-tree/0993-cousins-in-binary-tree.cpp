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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y)return false;
       queue<TreeNode *>q;
       q.push(root);
       while(q.size()>0){
        int size=q.size();
        unordered_set<int>s;
        for(int i=0;i<size;i++){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
                s.insert(temp->left->val);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                s.insert(temp->right->val);
            }
            if(temp->left!=NULL  && temp->right!=NULL){
                if(temp->left->val==x && temp->right->val==y)return false;
                if(temp->left->val==y && temp->right->val==x)return false;
            }
            if(temp->left!=NULL){
                if(temp->left->val==x && s.find(y)!=s.end())return true;
                if(temp->left->val==y && s.find(x)!=s.end())return true;
              
            }
            if(temp->right!=NULL){
                  if(temp->right->val==x && s.find(y)!=s.end())return true;
                if(temp->right->val==y && s.find(x)!=s.end())return true;
            }

        }
       }
       return false;

    }
};