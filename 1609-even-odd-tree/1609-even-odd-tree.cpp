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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL)return false;
        queue<TreeNode *>q;
        int curr_level=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int prev1=INT_MIN;
            int prev2=INT_MAX;
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(curr_level&1){
                    if(temp->val&1){
                        return false;
                    }
                    if(temp->val>=prev2){
                        return false;
                    }
                    prev2=temp->val;
                }
                else{
                    if(temp->val%2==0)return false;
                    if(temp->val<=prev1)return false;
                     prev1=temp->val;
                }
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
                curr_level++;
        }
        return true;
    }
};