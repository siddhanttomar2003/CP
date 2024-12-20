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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int level=0;
        while(q.size()>0){
            int size=q.size();
        
            vector<TreeNode *>v;
            vector<int>temp;
            
            for(int i=0;i<size;i++){
                TreeNode * curr=q.front();
                q.pop();
                if(level&1){
                v.push_back(curr);
                temp.push_back(curr->val);
                }
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            if(level&1){
                int j=size-1;
                for(int i=0;i<size;i++){
                   TreeNode *t=v[i];
                   t->val=temp[j];
                   j--;
                }
            }
            level++;
        }
        return root;
    }
};