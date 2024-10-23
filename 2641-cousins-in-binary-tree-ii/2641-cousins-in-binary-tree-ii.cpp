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
        queue<TreeNode *>q1;
        queue<TreeNode *>q2;
        if(!root)return nullptr;
        q1.push(root);
        q2.push(root);
        root->val=0;

        while(q1.size()>0){
            int size=q1.size();
            int sum=0;
            for(int i=0;i<size;i++){
              TreeNode *curr=q1.front();q1.pop();
                 if(curr->left!=NULL){
                    sum+=curr->left->val;
                    q1.push(curr->left);
                 }
                 if(curr->right!=NULL){
                    sum+=(curr->right->val);
                    q1.push(curr->right);
                 }
            }
            int size2=q2.size();
            for(int i=0;i<size2;i++){
                TreeNode * curr=q2.front();q2.pop();
                int curr_sum=0;
                if(curr->left!=NULL){
                    curr_sum+=curr->left->val;
                    q2.push(curr->left);
                }
                if(curr->right!=NULL){
                    curr_sum+=curr->right->val;
                    q2.push(curr->right);
                }
                if(curr->left!=NULL)
                curr->left->val=(sum-curr_sum);
                if(curr->right!=NULL)
                curr->right->val=(sum-curr_sum);
            }
        }
        return root;
    }
};